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
 vs adjlist(505);
 bool vis[505][505];
 int dx[]={1,-1,0,0};
 int dy[]={0,0,-1,1};
    vector<pair<int,int>> s;

int BFS2(int x,int y,int n,int m,int counter) {
	queue<pair<int,int>> q;
    int siz=1;
	q.push({x,y});
	s.push_back({x,y});
	vis[x][y]=true;
	while(!q.empty()) {
		pair<int,int> cur=q.front();q.pop();
		fo(i,4){
		    if(siz==counter)return 1;
            int xx=cur.first+dx[i],yy=cur.second+dy[i];
            if((xx<0||xx>=n||yy<0||yy>=m))continue;
            if( !vis[xx][yy]&&adjlist[xx][yy]=='X')
            {
                siz++;
                vis[xx][yy]=true;
                s.push_back({xx,yy});
                q.push({xx,yy});
            }
		}
	}
	return 0;	//cur is the furthest node from s with depth dep && dep is the depth of it
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n,m,k;cin>>n>>m>>k;
        fo(i,n) cin>>adjlist[i];
        int counter=0;
        pair<int ,int>xx;
        fo(i,n)
            fo(j,m)
                if(adjlist[i][j]=='.'){adjlist[i][j]='X';counter++;
                    xx.first=i;xx.second=j;
                }
                else if(adjlist[i][j]=='#')vis[i][j]=true;
            counter=counter-k;
        BFS2(xx.first,xx.second,n,m,counter);

        fo(i,sz(s)){
            pair<int,int>cur=s[i];
            adjlist[cur.first][cur.second]='.';
        }
        fo(i,n)cout<<adjlist[i]<<endl;
}

