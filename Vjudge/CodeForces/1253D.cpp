#include<bits/stdc++.h>
using namespace std;
#define all(v)				((v).begin()), ((v).end())
#define siz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define fo(i, n)		for(int i=0;i<(int)(n);++i)
#define fp(i, j, n)	for(int i=(j);i<=(int)(n);++i)
#define fn(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define fvec(i,vec) for(auto i:vec)
#define pb				push_back
#define MP			make_pair
#define mine(x,y,z) min(x,min(y,z))
#define maxe(x,y,z) max(x,min(y,z))
typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef unsigned long long ull;
typedef  long long ll;
const ll OO =10e7;
const int N=200005;
int par[N], sz[N];
int maxi,mini;
void init(int n)
{
    for ( int i = 1 ; i <= n ;i++)
        par[i] = i , sz[i] = 1;
}

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
    if(sz[v] < sz[u]){
        par[v] = u ;sz[u] += sz[v];
    }
    else{
        par[u] = v;sz[v] += sz[u];
    }
}
bool isconnected( int u , int v)
{
    return (findparent(u) == findparent(v));
}
vector < int > adj[N];
bool vis[N];
void dfs( int node)
{
    maxi=max(maxi,node);
    mini=min(mini,node);
    vis[node] = true;
    for ( auto child : adj[node])
        if(vis[child] == false){
            dfs(child);
        }
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int ans=0;
        int n,m;cin>>n>>m;
        init(n);
        vector<pair<int,int>>vec;
        fo(i,m){
            int u,v;cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
            connect(u,v);
        }
        fp(i,1,n){
            if(!vis[i])
            {
                mini=OO;maxi=-1;
                dfs(i);
                if(mini<maxi)
                for(int j=mini;j<maxi;j++){
                    //vis[i]=true;
                    if(!vis[j]){
                    ans++;
                    dfs(j);}
                }
            }
        }
        cout<<ans;
}

