#include <bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()), ((v).end())
#define siz(v) ((long long)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < sz(v); ++i)
#define fo(i, n) for (int i = 0; i < (int)(n); ++i)
#define fp(i, j, n) for (int i = (j); i <= (int)(n); ++i)
#define fn(i, j, n) for (int i = (j); i >= (int)(n); --i)
#define fvec(i, vec) for (auto i : vec)
#define pb push_back
#define MP make_pair
#define mine(x, y, z) min(x, min(y, z))
#define maxe(x, y, z) max(x, min(y, z))
#define F first
#define S second
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef unsigned long long ull;
typedef long long ll;
const ll OO = 1e18, mod = 1e9 + 7, N = 1e6+200;
vector<int>adjList[N];
ll vis[N] ,vis2[N];

void dfs( int u ){
    vis[u] = 1;
    for(auto v : adjList[u]){
        if( vis[v] )
            continue;
        vis[v] = 1;
        dfs( v );
    }
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
   ll n,m;cin>>n>>m;
   ll loop=0,root=0;
   fo(i,m){
       ll u,v;cin>>u>>v;        vis2[u]=1;vis2[v]=1;

        if(u==v){
            loop++;continue;
        }
        root=u;
        adjList[u].pb(v);
        adjList[v].pb(u);
   }
   dfs(root);
   for(int i=1;i<=n;i++){
        if((vis2[i])&&!(vis[i])){
            cout<<0;return 0;
        }
   }
   ll re=0;
   fp(i,1,n){
       ll sz=siz(adjList[i]);
        re+=(sz*(sz-1))/2;
   }
   fp(i,1,loop){
    re+=m-i;
   }
   cout<<re;
}

