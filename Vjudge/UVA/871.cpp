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
vs adj(5);
int BFS2(int x,int y,int siz) {

	queue<pair<int,int>> q;
	q.push({x,y}), adj[x][y]='0';
	int xx = x,yy=y,len=1;
	int dx[]={1,1,0,1,-1,-1,-1,0};
	int dy[]={1,0,1,-1,-1,0,1,-1};
	while(!q.empty()) {
			xx = q.front().first;
			yy=q.front().second;
			 q.pop();
			 fo(i,8){
                int xxx=xx+dx[i],yyy=yy+dy[i];
                if(xxx<0||xxx>=siz||yyy<0||yyy>=siz)continue;
                if(adj[xxx][yyy]=='1'){
                    len++;adj[xxx][yyy]='0';
                    q.push({xxx,yyy});
                }
			 }
	}
	return len;	//cur is the furthest node from s with depth dep && dep is the depth of it
}
int main()
{


        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int t;cin>>t;
        string line;getline(cin,line);getline(cin,line);
        while(t--){
            adj.clear();
            int ma=0;
            while(true){
                getline(cin,line);
                if(line.empty())break;
                adj.pb(line);
            }
            fo(i,sz(adj)){
                fo(j,sz(adj)){
                    if(adj[i][j]=='1'){
                        int len=BFS2(i,j,sz(adj));
                        ma=max(ma,len);
                    }
                }
            }
            cout<<ma<<"\n";
            if(t)cout<<"\n";
        }
}

