#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v) ((v).begin()), ((v).end())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < siz(v); ++i)
#define fo(i, n) for (int i = 0; i < (int)(n); ++i)
#define fp(i, j, n) for (long long i = (j); i <= (long long)(n); ++i)
#define fn(i, j, n) for (int i = (j); i >= (int)(n); --i)
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
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO =1e18, mod = 1e9+7,mod2=1e9+9, N =2e5+5,M=30,MOD=998244353, minOO=LLONG_MIN;
///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة
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
    }else a[l]=seg[node];
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
vector<vector < int > >adj(N);
vector<bool>vis(N,0);
vll st(N,0),en(N,0);
ll ind=0;
vll value(N);

void dfs( int node,int par)
{
    vis[node] = true;
    st[node]=en[node]=ind--;
    a[en[node]]=value[node];
    if(par!=-1){
        a[en[node]]+=a[en[par]];
    }
    for ( auto child : adj[node])
        if(vis[child] == false)
        {
            dfs(child,node);
            st[node]=min(st[node],st[child]);
        }
}
void func(int inde) {
    cin>>num;ll q;cin>>q;
    ind=num;
    fp(i,1,num)cin>>value[i];
    fo(i,num-1){
        ll u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    build(1,1,num);
    fo(i,q){
        ll t;cin>>t;
        if(t==1){
            ll u,v;cin>>u>>v;
            ll vv= query(1,1,num,en[u],en[u]);
            update(1,1,num,st[u],en[u],v-value[u]);
            value[u]=v;
        }else {
            ll u;cin>>u;
            cout<<query(1,1,num,en[u],en[u])<<'\n';
        }
    }
}
int main() {
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