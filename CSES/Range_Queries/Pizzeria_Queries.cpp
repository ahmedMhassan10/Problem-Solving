#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define clr(v, d)			memset(v, d, sizeof(v))
#define ll long long
#define int long long
typedef tree< pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define setp(item) cout<<fixed<<setprecision(item);
#define PI 3.14159265358979323846264338327950

int ceilSqrt(int a){
    return ::ceil(sqrtl(a));
}
int  divC(int a,int b){
    return a/b+(a%b!=0);
}
int gcd(int a, int b) { return ((b == 0) ? a : gcd(b, a % b)); }
int lcm(int a,int b){return (a*b)/gcd(a,b);}
const ll OO =1e18, mod = 1e9+7,mod2=1e9+9, N =2e5+5,M=30,MOD= 998244353, minOO=LLONG_MIN;

///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة

/// a33333333333333333333333333333333333333333333333333333333333333333333333333333333333333
ll seg[N<<2];
ll seg2[N<<2];
ll arr[N];
void Build_seg(ll node,ll l , ll r) {// DONT FORGET BUILD IN MAIN YA 7OMAR
    if (l == r) {
        seg[node] = arr[l]+l;
        seg2[node] = arr[l]-l;
        arr[l]+=l;
        return;
    }
    ll mid = (l + r) / 2;
    Build_seg(node * 2, l, mid);
    Build_seg(node * 2 + 1, mid + 1, r);
    seg[node] = min(seg[node * 2] , seg[node * 2 + 1]);// DONT FORGET BUILD IN MAIN YA 7OMAR
    seg2[node] = min(seg2[node * 2] , seg2[node * 2 + 1]);// DONT FORGET BUILD IN MAIN YA 7OMAR

}
void update(ll node,ll l ,ll r,ll idx,ll val) {// DONT FORGET BUILD IN MAIN YA 7OMAR
    if (l == r) {
        seg[node] = val+l;
        seg2[node] = val-l;
        arr[l]=val+l;
        return;
    }
    ll mid = (l + r) / 2;
    if (idx <= mid) update(node * 2, l, mid, idx,val);
    else update(node * 2 + 1, mid + 1, r, idx,val);
    seg[node] = min(seg[node * 2] , seg[node * 2 + 1]);// DONT FORGET BUILD IN MAIN YA 7OMAR
    seg2[node] = min(seg2[node * 2] , seg2[node * 2 + 1]);// DONT FORGET BUILD IN MAIN YA 7OMAR
}
ll queryMin(ll node,ll l ,ll r,ll st,ll en) {// DONT FORGET BUILD IN MAIN YA 7OMAR
    if(l>en || r<st){
        return OO;
    }
    if(l>=st && r<=en){
        return seg[node];
    }
    ll md= (l+r)/2 ;
    return min(queryMin(node*2,l,md,st,en),queryMin(node*2+1,md+1,r,st,en));// DONT FORGET BUILD IN MAIN YA 7OMAR
}
ll queryMax(ll node,ll l ,ll r,ll st,ll en) {// DONT FORGET BUILD IN MAIN YA 7OMAR
    if(l>en || r<st){
        return OO;
    }
    if(l>=st && r<=en){
        return seg2[node];
    }
    ll md= (l+r)/2 ;
    return min(queryMax(node*2,l,md,st,en),queryMax(node*2+1,md+1,r,st,en));// DONT FORGET BUILD IN MAIN YA 7OMAR
}
void func(int index) {
    ll n,m;cin>>n>>m;
    vector<int>curr(n+1);
    for (int i =1; i <=n ; ++i) {
        cin>>arr[i];
        curr[i]=arr[i];
    }
    Build_seg(1,1,n);
    for (int i = 0; i < m; ++i) {
        ll t;cin>>t;
        if(t==1){
            ll u,v;cin>>u>>v;
            curr[u]=v;
            update(1,1,n,u,v);
        }else{
            ll u;cin>>u;
            ll q1=OO,q2=OO;
            if(u+1<=n)
                q1= queryMin(1,1,n,u+1,n);
            if(u-1>=1)
                q2= queryMax(1,1,n,1,u-1);
            ll v1=OO,v2=OO;
            if(q1!=OO)
                v1=q1-arr[u]+curr[u];
            if(q2!=OO)
                v2=q2+u;
            cout<<min(v1,min(v2,curr[u]))<<endl;
        }
    }
}
signed main() {
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
//    cin>>t;
    ll index=1;
    while (t--){
        func(index++);
    }
    return 0;
}