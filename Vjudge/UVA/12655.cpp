#include <bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()), ((v).end())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < sz(v); ++i)
#define fo(i, n) for (int i = 0; i < (int)(n); ++i)
#define fp(i, j, n) for (int i = (j); i <= (int)(n); ++i)
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
typedef vector<pair<ll,ll>> vp;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
#define setp(item) cout<<fixed<<setprecision(item);
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO = 1e9, mod = 1e9 + 7,mod2=1e9+9, N = 5e5+10,M=25;
int par[N], sz[N];
void init(int n)
{
    for ( int i = 1 ; i <= n ;i++)
        par[i] = i , sz[i] = 1;
}
// O(n) ---> O(n ^ 2)
int findparent( int u)
{
    if(par[u] == u)
        return  u;
    return par[u] = findparent(par[u]);
}
bool iscyclic = false;
void connect( int u , int v)
{
    u = findparent(u);
    v = findparent(v);
    if ( u == v)
    {
        iscyclic =true;
        return;
    }
    if(sz[v] < sz[u])
        par[v] = u ,sz[u] += sz[v];
    else
        par[u] = v,sz[v] += sz[u];
}
bool isconnected( int u , int v)
{
    return (findparent(u) == findparent(v));
}

int n, m,q, ancestor[N][M], lvl[N],sp[N][M];
vector < pair<int,int> > g[N];

void dfs( int node , int par,int cost)
{
    lvl[node] = lvl[par] + 1;
    ancestor[node][0] = par;
    sp[node][0]=cost;
    for ( int j = 1 ; j < M ; j++)
    {
        int p = ancestor[node][j-1];
        ancestor[node][j] = ancestor[p][j-1];
        sp[node][j] = min(sp[node][j-1], sp[p][j-1]);
    }
    for(auto ch : g[node])
    {
        if(ch.F == par)
            continue;
        dfs(ch.F,node,ch.S);
    }
}
int findKthAncestor( int u , int k)
{
    for ( int j = M-1 ; j >= 0 ; j--)
        if(k&(1<<j))
            u = ancestor[u][j];
    return u;
}
int getLCA( int u , int v)
{
    if(lvl[u] < lvl[v])
        swap(u,v);
    u = findKthAncestor(u,lvl[u]-lvl[v]);
    if ( u == v)
        return u;
    for ( int i = M-1 ; i>= 0 ;i--)
    {
        if(ancestor[u][i] == ancestor[v][i])
            continue;
        u = ancestor[u][i];
        v = ancestor[v][i];
    }
    return ancestor[u][0];
}
int maxi(int u,int k,int v,int c)
{
    int ma=OO;
    for ( int i = M-1 ;i>= 0 ;i--){

        if((1<<i) <= k){
            k -= (1<<i);
            ma=min(ma,sp[u][i]);
            u=findKthAncestor(u,1<<i);
        }
        if((1<<i) <= c){
            c -= (1<<i);
            ma=min(ma,sp[v][i]);
            v=findKthAncestor(v,1<<i);
        }
    }
    return ma;
}

int test(int u,int v){
    int md=getLCA(u,v);
    int lv1=lvl[u]-lvl[md],lv2=lvl[v]-lvl[md];
    return maxi(u,lv1,v,lv2);
}
void solve(){
    clr(g,0);clr(sp,OO);clr(lvl,0),clr(ancestor,0);
    init(n);
    vector<pair<int,pair<int,int>>>vec;
    fo(i,m){
        int u,v,w;cin>>u>>v>>w;
        vec.pb({w,{u,v}});
    }
    sort(all(vec));
    fn(i,m-1,0){
        int u=vec[i].S.F,v=vec[i].S.S,w=vec[i].F;
        if(isconnected(u,v))continue;
        connect(u,v);
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    dfs(1,1,0);
    while(q--){
        int u,v;cin>>u>>v;
        cout<<test(u,v)<<"\n";
    }
}
int main() {
        // freopen("survive.in "," r ",stdin);
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        while( cin>>n>>m>>q){
            //if(n==0)break;
            solve();
        }
        return 0;
}
