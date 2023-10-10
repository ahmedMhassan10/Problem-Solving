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
ll type[N<<2];
void build( int node , int l , int r)
{
    lazy[node]=0;
    type[node]=0;
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
    if(type[node]==1){
        seg[node] += lazy[node] * (r- l + 1);
    }else{
        seg[node] = lazy[node] * (r- l + 1);
    }
    if(l != r) {
        ll md=(l+r)/2;
        if(type[node]==1){
            if(type[node<<1]==2) {
                propagate(node<<1,l,md);
                lazy[node << 1] = lazy[node];
            }else{
                lazy[node << 1] += lazy[node];
            }
            if(type[node<<1|1]==2){
                propagate(node<<1|1,md+1,r);
                lazy[node << 1 | 1] = lazy[node];
            }else{
                lazy[node << 1 | 1] += lazy[node];
            }
            type[node<<1]=1;
            type[node<<1|1]=1;
        }else{
            lazy[node << 1] = lazy[node];
            lazy[node << 1 | 1] = lazy[node];
            type[node<<1]=2;
            type[node<<1|1]=2;
        }
    }else a[l]=seg[node];
    lazy[node] = 0;
    type[node]=0;
}

void update( int node , int l , int r , int s , int e , int val)
{
    propagate(node,l,r);
    if ( l > e || r < s)
        return ;
    if ( l >= s and r <= e)
    {
        lazy[node] = val;
        type[node]=1;
        propagate( node , l, r);
        return;
    }
    int md = l + r >> 1 ;
    update(node<<1,l,md,s,e,val),update(node<<1|1,md+1,r,s,e,val);
    seg[node] = seg[node<<1] + seg[node<<1|1];
}
void update2( int node , int l , int r , int s , int e , int val)
{
    propagate(node,l,r);
    if ( l > e || r < s)
        return ;
    if ( l >= s and r <= e)
    {
        lazy[node] = val;
        type[node]=2;
        propagate( node , l, r);
        return;
    }
    int md = l + r >> 1 ;
    update2(node<<1,l,md,s,e,val),update2(node<<1|1,md+1,r,s,e,val);
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
    ll n,q;cin>>n>>q;
    for (int i = 1; i <=n ; ++i) {
        cin>>a[i];
    }
    build(1,1,n);
    while (q--){
        ll t;
        cin>>t;
        if(t==1){
            ll u,v,w;cin>>u>>v>>w;
            update(1,1,n,u,v,w);
        }else if(t==2){
            ll u,v,w;cin>>u>>v>>w;
            update2(1,1,n,u,v,w);
        }else{
            ll u,v;cin>>u>>v;
            cout<<query(1,1,n,u,v)<<'\n';
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