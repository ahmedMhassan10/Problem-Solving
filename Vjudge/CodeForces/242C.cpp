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
/*map<ll, vector < int > >adj;
map<ll,bool> vis;
void dfs( int node)
{
    vis[node] = true;
    for ( auto child : adj[node]){
        if(vis[child] == false){
            dfs(child);

        }
    }
}
*/

map<pair<ll,ll>,bool>adjList;
map<pair<ll,ll>,ll>len;
int dx[]={1,1,1,-1,-1,-1,0,0};
int dy[]={1,-1,0,1,-1,0,1,-1};
void BFS2(ll x,ll y, ll d1,ll d2) {
	queue<pair<ll,ll>> q;
	q.push({x,y}), len[{x,y}] = 0;
	pair<ll,ll> cur = {x,y};
	while(!q.empty()) {
			cur = q.front(), q.pop();
			fo(i,8){
                ll xx=cur.first+dx[i],yy=cur.second+dy[i];
                if(adjList[{xx,yy}]&&len[{xx,yy}]==0&&!(xx<1||yy<1||xx>OO||yy>OO)){
                    q.push({xx,yy});
                    len[{xx,yy}]=len[cur]+1;
                }
			}
			if(len[{d1,d2}]!=0)break;
	}
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        ll x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        int num;cin>>num;
        fo(i,num){
            int r,a,b;cin>>r>>a>>b;
            fp(i,a,b){
                adjList[{r,i}]=true;
            }
        }
        if(x1==x2&&y1==y2)cout<<"0\n";
        else{
            BFS2(x1,y1,x2,y2);
            if(len[{x2,y2}]==0)cout<<"-1\n";
            else cout<<len[{x2,y2}]<<'\n';
        }

}

