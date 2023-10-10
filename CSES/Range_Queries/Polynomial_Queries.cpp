#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define all(v) ((v).begin()), ((v).end())
#define invAll(v) ((v).rbegin()), ((v).rend())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define fo(i, n) for (long long i = 0; i < (long long)(n); ++i)
#define fp(i, j, n) for (long long i = (j); i <= (long long)(n); ++i)
#define fn(i, j, n) for (long long i = (j); i >= (long long)(n); --i)
#define fvec(i, vec) for (auto i : vec)
#define pb push_back
#define MP make_pair
#define mine(x, y, z) min(x, min(y, z))
#define maxe(x, y, z) max(x, max(y, z))
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef vector<pll> vp;
typedef vector< long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef tree< pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define setp(item) cout<<fixed<<setprecision(item);
#define div(a,b) a/b+(a%b!=0)
#define PI 3.1415926535897932384626433
ll ceilSqrt(ll a){
    return ::ceil(sqrtl(a));
}
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO =1e17, mod = 1e9+7,mod2=1e9+9, N =2e5+5,M=30,MOD= 998244353, minOO=LLONG_MIN;
///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة
/// :-)
/// a33333333333333333333333333333333333333333333333333333333333333333333333333333333333333
ll seg[N<<2], a[N], lazy[N<<2],counter[N<<2];
void build( int node , int l , int r)
{
    lazy[node]=0;
    counter[node]=0;
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
    ll n=r-l+1;
    ll start=lazy[node]-(r-l)*counter[node];
    ll c=counter[node]*(n-1)+2*start;
    ll nn=n*(2*start+(n-1)*counter[node])/2;
    seg[node] +=n*(2*start+(n-1)*counter[node])/2;
    if(l != r) {
        int md = l + r >> 1 ;
        lazy[node << 1] += lazy[node]-(r-md)*counter[node];
        lazy[node << 1 | 1] += lazy[node];
        counter[node<<1]+=counter[node];
        counter[node<<1|1]+=counter[node];
    }
    counter[node]=0;
    lazy[node] = 0;
}

void update( int node , int l , int r , int s , int e , int val)
{
    propagate(node,l,r);

    if ( l > e || r < s)
        return ;
    if ( l >= s and r <= e)
    {
        lazy[node] += val-(e-r);
        counter[node]++;
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

void func(int ind) {
    ll n,q;cin>>n>>q;
    fp(i,1,n)cin>>a[i];
    build(1,1,n);
    while (q--){
        ll t;cin>>t;
        if(t==1){
            ll u,v;cin>>u>>v;
            update(1,1,n,u,v,v-u+1);
        }else{
            ll u,v;cin>>u>>v;
            cout<<query(1,1,n,u,v)<<'\n';
        }
    }
//    fp(i,1,n)cout<<query(1,1,n,i,i)<<'\n';
}
signed main() {
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
//    cin>>t;
    ll ind=1;
    while (t--){
        func(ind++);
    }
    return 0;
}