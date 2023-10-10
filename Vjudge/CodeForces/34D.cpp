#include<bits/stdc++.h>
using namespace std;
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define fo(i, n)		for(int i=0;i<(int)(n);++i)
#define fp(i, j, n)	for(int i=(j);i<=(int)(n);++i)
#define fn(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define fvec(i,vec) for(auto i:vec)
#define pb				push_back
#define MP			make_pair
typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef unsigned long long ull;
typedef  long long ll;
const ll OO =10e9;
#define mine(x,y,z) min(x,min(y,z))
#define maxe(x,y,z) max(x,min(y,z))
map<ll, vector < int > >adj;
map<ll,bool> vis;
map<int,int>m;
void dfs( int node,int par)
{
    vis[node] = true;
    m[node]=par;
    for ( auto child : adj[node])
        if(vis[child] == false){
            dfs(child,node);
        }
}
int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int num,r1,r2;cin>>num>>r1>>r2;
        fp(i,1,num){
            if(i==r1)continue;
                        int u;cin>>u;

            adj[i].pb(u);
            adj[u].pb(i);
        }
        dfs(r2,0);
        for(auto it:m){
            if(it.second==0)continue;
            cout<<it.second<<" ";
        }
}

