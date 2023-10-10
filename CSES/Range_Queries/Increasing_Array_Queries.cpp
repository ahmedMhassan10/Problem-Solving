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
ll seg[N<<2], a[N], lazy[N<<2];
void build( int node , int l , int r)
{
    lazy[node]=0;
    if( l == r)
    {
        seg[node]=a[l];
        return ;
    }
    int md = l + r >> 1 ;
    build(node<<1,l,md),build(node<<1|1,md+1,r);
    seg[node] = seg[node<<1] + seg[node<<1|1];
}

void propagate( int node , int l , int r )
{
    if(lazy[node] == 0)
        return;
    seg[node] = lazy[node] * (r- l + 1);
    if(l != r) {
        lazy[node << 1] = lazy[node];
        lazy[node << 1 | 1] = lazy[node];
    }
    lazy[node] = 0;
}

void update( int node , int l , int r , int s , int e , int val)
{
    propagate(node,l,r);
    if ( l > e || r < s)
        return ;
    if ( l >= s and r <= e)
    {
        lazy[node] = val;
        propagate( node , l, r);
        return;
    }
    int md = l + r >> 1 ;
    update(node<<1,l,md,s,e,val),update(node<<1|1,md+1,r,s,e,val);
    seg[node] = seg[node<<1] + seg[node<<1|1];
}

ll query( int node , int l , int r , int s , int e)
{
    propagate(node,l,r);
    if ( l > e || r < s)
        return 0;
    if ( l >= s and r <= e)
        return seg[node];
    int md = l + r >> 1 ;
    return query(node<<1,l,md,s,e)+query(node<<1|1,md+1,r,s,e);
}

void func(int index) {
    ll n;cin>>n;
    ll m;cin>>m;
    int  mnr[n], mxr[n];
    vector<int>prif(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        prif[i]=a[i];
        if(i)
            prif[i]+=prif[i-1];
    }
    build(1,0,n-1);
    stack<int>  s4,s3;
    for(int i = 0; i < n; i++) {
        while(!s4.empty() && a[s4.top()] > a[n - 1 - i])
            s4.pop();
        while(!s3.empty() && a[s3.top()] < a[n - 1 - i])
            s3.pop();
        mnr[n - 1 - i] = s4.empty() ? -1: s4.top() - (n - 1 - i);//distance
        mxr[n - 1 - i] = s3.empty() ? -1: s3.top() - (n - 1 - i);//distance
        s4.push(n - 1 - i);
        s3.push(n - 1 - i);
    }

    vector<int>res(m);
    vector<pair<pair<int,int>,int>>q;
    for (int i = 0; i < m; ++i) {
        ll u,v;cin>>u>>v;
        u--,v--;
        q.push_back({{u,v},i});
    }
    sort(q.begin(),q.end());
    ll last=m-1;
    for (int i = n-1; i >=0 ; i--) {
        if(mxr[i]!=-1){
            update(1,0,n-1,i,mxr[i]+i-1,a[i]);
        }else update(1,0,n-1,i,n-1,a[i]);
        while (last>=0&&q[last].first.first>=i){
            ll v=0;
            ll qq=query(1,0,n-1,q[last].first.first,q[last].first.second);
            if(q[last].first.first!=0)
                v=prif[q[last].first.first-1];
            ll t1=prif[q[last].first.second]-v;
            res[q[last].second]=-t1+qq ;
            last--;
        }
    }

    for (int i = 0; i < m; ++i) {
        cout<<res[i]<<'\n';
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