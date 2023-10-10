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
const ll OO =10e7;
#define mine(x,y,z) min(x,min(y,z))
#define maxe(x,y,z) max(x,min(y,z))
map<ll, vector < pair<int,int> > >adj;
map<ll,bool> vis;
int di=OO,first,last;
bool cycle=false;
void dfs( int node,int par)
{
    vis[node] = true;
    for ( auto child : adj[node])
        if(vis[child.first] == false){
            last=child.first;
            di=min(di,child.second);
            dfs(child.first,node);
        }else if (child.first !=par){
            cycle =true;
        }
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int num,mm;cin>>num>>mm;
        map<int,int>m;
        fo(i,mm){
            int u,v,k;cin>>u>>v>>k;
            adj[u].pb({v,k});
            adj[v].pb({u,k});
            m[u]++;m[v]--;
        }
        vector<vector<int>>re;
        fp(i,1,num){
            if(m[i]==1){
                first=i;last=OO;
                di=OO;
                cycle=false;
                dfs(i,0);
                if(!cycle)
                    re.pb({first,last,di});
            }
        }
        cout<<re.size()<<endl;
        fo(i,(re.size())){
            cout<<re[i][0]<<" "<<re[i][1]<<" "<<re[i][2]<<endl;
        }
}

