#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")

#define clr(v, d)			memset(v, d, sizeof(v))
#define ll long long
#define int long long
typedef tree< pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define setP(item) cout<<fixed<<setprecision(item);
int ceilSqrt(int a){
    return ::ceil(sqrtl(a));
}
int  divC(int a,int b){
    return a/b+(a%b!=0);
}
int gcd(int a, int b) { return ((b == 0) ? a : gcd(b, a % b)); }
int lcm(int a,int b){return (a*b)/gcd(a,b);}
const ll OO =1e18, mod = 1e9+7,mod2=1e9+9,  N=2e5+5,M=25,MOD= 998244353, minOO=LLONG_MIN;
const double EPS=1e-10;
const double PI=acos(-1);
const ll maximum=1e5+3;
const int NOT_VISITED = -1;

///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة
vector<pair<int,int>> par(N);
vector<int>sz(N);
void init(int n)
{
    for ( int i = 1 ; i <= n ;i++)
        par[i] = {i,0} , sz[i] = 1;
}
int findparent( int u)
{
    if(par[u].first == u)
        return  u;
    return findparent(par[u].first);
}

void connect( int u , int v,int sec)
{
    u = findparent(u);
    v = findparent(v);
    if ( u == v)
    {
        return;
    }
    if(sz[v] < sz[u])
        par[v].first = u ,par[v].second=sec,sz[u] += sz[v];
    else
        par[u].first = v,par[u].second=sec,sz[v] += sz[u];
}
int n , ancestor[N][M], lvl[N],sp[N][M];
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
        sp[node][j] = max(sp[node][j-1], sp[p][j-1]);
    }
    for(auto ch : g[node])
    {
        if(ch.first == par)
            continue;
        dfs(ch.first,node,ch.second);
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
    int ma=0;
    for ( int i = M-1 ;i>= 0 ;i--){
        if((1<<i) <= k){
            k -= (1<<i);
            ma=max(ma,sp[u][i]);
            u=findKthAncestor(u,1<<i);
        }
        if((1<<i) <= c){
            c -= (1<<i);
            ma=max(ma,sp[v][i]);
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

void func(int index) {
    int m,q;cin>>n>>m>>q;
    init(n);
    for (int i = 1; i <= m; ++i) {
        ll u,v;cin>>u>>v;
        connect(u,v,i);
    }
    set<int>comp;
    for (int i = 1; i <= n ; ++i) {
        if(par[i].first!=i){
            g[par[i].first].push_back({i,par[i].second});
        }
        comp.insert(findparent(i));
    }
    for(auto item:comp){
        dfs(item,0,0);
    }
    for (int i = 0; i < q; ++i) {
        ll u,v;cin>>u>>v;
        if(findparent(u) != findparent(v)){
            cout<<"-1\n";
        }else {
            cout<<test(u,v)<<'\n';
        }
    }
}
signed main() {
//    freopen("lcm.in","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
//    cin>>t;
    ll index=1;
    while (t--){
        func(index++);
    }
    return 0;
}