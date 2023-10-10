#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define clr(v, d)			memset(v, d, sizeof(v))
#define ll long long
#define int long long
typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
ll num,q;
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
    seg[node] += lazy[node] * (r- l + 1);
    if(l != r) {
        lazy[node << 1] += lazy[node];
        lazy[node << 1 | 1] += lazy[node];
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
void func(int index)
{
    ll n,q;cin>>n>>q;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    build(1,1,n);
    for (int i = 0; i < q; ++i) {
        ll t;cin>>t;
        if(t==1){
            ll st,en,val;cin>>st>>en>>val;
            update(1,1,n,st,en,val);
        }else{
            ll st;cin>>st;
            cout<<query(1,1,n,st,st)<<'\n';
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