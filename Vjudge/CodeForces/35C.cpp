#include <bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()), ((v).end())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < sz(v); ++i)
#define fo(i, n) for (int i = 0; i < (int)(n); ++i)
#define fp(i, j, n) for (long long i = (j); i <= (long long)(n); ++i)
#define fn(i, j, n) for (int i = (j); i >= (int)(n); --i)
#define fvec(i, vec) for (auto i : vec)
#define pb push_back
#define MP make_pair
#define mine(x, y, z) min(x, min(y, z))
#define maxe(x, y, z) max(x, max(y, z))
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<pair<ll,ll>> vp;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
#define setp(item) cout<<fixed<<setprecision(item);
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO = 1e9, mod = 1e9 + 7,mod2=1e9+9, N =1e5 +5,M=23;
map<ll,vector<int>>adjList;
ll len[2002][2002];
vector<int>dx={1,-1,0,0};
vector<int>dy={0,0,1,-1};
ll n,m;

void BFS(int x,int y) {
	queue<pair<int,int>> q;
	q.push({x,y}), len[x][y] = 0;
	while(!q.empty()) {

            pair<int,int> cur = q.front(); q.pop();
			fo(i,4){

                ll xx=cur.F+dx[i],yy=cur.S+dy[i];
                //cout<<xx<<" "<<yy<<endl;
                if(xx>n||xx<1||yy>m||yy<1){
                                 //   cout<<xx<<" "<<yy<<endl;

                        continue;

                }
              //  cout<<xx<<" "<<yy<<endl;
			    if (len[xx][yy]==OO||((len[xx][yy] > len[cur.F][cur.S]+1))){
                    q.push({xx,yy}); len[xx][yy] =len[cur.F][cur.S]+1;
				}
			}
	}
}
int main() {
        freopen("input.txt","rt",stdin);
        freopen("output.txt","wt",stdout);
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        cin>>n>>m;
        ll q;cin>>q;
        fp(i,1,n){
            fp(j,1,m)len[i][j]=OO;
        }

        fo(i,q){
            ll u,v;
            cin>>u>>v;
            //cout<<u<<v<<endl;
            BFS(u,v);
        }
        ll ans=-1,x=-1,y=-1;
        fp(i,1,n){
            fp(j,1,m){
               // cout<<len[i][j]<<endl;
                if(ans<len[i][j]){
                    //cout<<"A\n";
                    ans=len[i][j];
                    x=i,y=j;
                }
            }
        }
        cout<<x<<" "<<y<<endl;
}
