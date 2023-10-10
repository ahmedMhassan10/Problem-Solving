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


map<ll,vector<int>>adjList;
vector<int> BFS2(int s,int num) {
	vector<int> len(num+1, OO);
	queue<pair<int,int>> q;
	q.push({s,0}), len[s] = 1;
	pair<int,int> cur ;
	while(!q.empty()) {
			cur = q.front(), q.pop();
			if(cur.first==s){
                int siz=2;
                fvec(i, adjList[cur.first])
                    if (len[i] == OO){
                        q.push({i,cur.first}); len[i] =siz;siz++;
                    }
			}else {
                map<int,int>m;
                int siz=1;
                m[len[cur.first]]=1;m[len[cur.second]]=1;
                fvec(i, adjList[cur.first])
                    if (len[i] == OO){
                        while(m[siz]==1)siz++;
                        q.push({i,cur.first}); len[i] =siz;siz++;
                    }
			}
	}
	return len;	//cur is the furthest node from s with depth dep && dep is the depth of it
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int num;cin>>num;
        fo(i,num-1){
            int u,v;cin>>u>>v;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }
        vector<int>vec=BFS2(1,num);
        set<int>s(vec.begin()+1,vec.end());
        cout<<s.size()<<endl;
        fo(i,num){cout<<vec[i+1]<<" ";}

}

