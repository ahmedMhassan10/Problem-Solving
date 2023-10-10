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
const ll OO = 1e9, mod = 1e9 + 7,mod2=1e9+9, N =184,M=23;
map<ll,vector<int>>adjList;
queue<pair<int,int>> q;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};ll n,m;
void BFS(vector<vll> &len) {
	while(!q.empty()) {
            pair<int,int> cur = q.front(); q.pop();
            fo(i,4){
                ll xx=cur.F+dx[i],yy=cur.S+dy[i];
                if(xx<1||xx>n||yy<1||yy>m)continue;
                if(len[xx][yy]>len[cur.F][cur.S]+1){
                    len[xx][yy]=len[cur.F][cur.S]+1;
                    q.push({xx,yy});
                }
            }
	}
}
int main() {
        //freopen("input.txt","rt",stdin);
        //freopen("output.txt","wt",stdout);
        int t;cin>>t;
        while(t--){
            cin>>n>>m;
            vector<vll> len(n+1,vll(m+1,OO));
            fp(i,1,n){
                fp(j,1,m){
                    char ch;cin>>ch;
                    if(ch=='1'){
                        len[i][j]=0;
                        q.push({i,j});
                    }
                }
            }
            BFS(len);
            fp(i,1,n){
                fp(j,1,m){
                    cout<<len[i][j]<<" ";
                }
                cout<<'\n';
            }
        }
}
