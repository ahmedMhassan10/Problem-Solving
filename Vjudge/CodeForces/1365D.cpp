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
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
vs adjList;
int BFS2(int x,int y,int n,int m) {
	map<pair<int,int>,bool>vis;
	queue<pair<int,int>> q;
	int gcounter=0;
	vis[{x,y}]=true;
	q.push({x,y});
	while(!q.empty()) {
            pair<int,int>cur = q.front();q.pop();
            fo(kk,4){
                    int xx=cur.first+dx[kk],yy=cur.second+dy[kk];
                    if((xx<0||yy<0||xx>=n||yy>=m)||(adjList[xx][yy]=='#')||vis[{xx,yy}])continue;
                    q.push({xx,yy});
                    vis[{xx,yy}]=true;
                    if(adjList[xx][yy]=='G'){
                            gcounter++;
                    }
            }

	}
	return gcounter;	//cur is the furthest node from s with depth dep && dep is the depth of it
}
int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int t;cin>>t;
        while(t--){
            int n,m;cin>>n>>m;
            adjList.clear();
            fo(i,n)
            {
                string str;cin>>str;
                adjList.pb(str);
            }
            int gcounter=0;
            fo(i,n)
                fo(j,m){
                    if(adjList[i][j]=='G')gcounter++;
                }
            fo(i,n)
                fo(j,m){
                    if(adjList[i][j]=='B'){
                        fo(kk,4){
                            int xx=i+dx[kk],yy=j+dy[kk];
                            if(xx<0||yy<0||xx>=n||yy>=m)continue;
                            if(adjList[xx][yy]!='B')adjList[xx][yy]='#';
                        }
                    }
                }
            if(gcounter==0){
                if(adjList[n-1][m-1]!='B')cout<<"YES\n";
                else cout<<"NO\n";
            }else  if(gcounter!=0 && adjList[n-1][m-1]=='#')cout<<"NO\n";
            else {
                int cc=BFS2(n-1,m-1,n,m);
                if(cc==gcounter)cout<<"YES\n";
                else cout<<"NO\n";
            }
        }

}

