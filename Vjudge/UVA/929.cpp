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
const ll OO = 1e9, mod = 1e9+7,mod2=1e9+9, N =1000 ,M=23;
vector<int>dx={0,0,-1,1};
vector<int>dy={1,-1,0,0};
ll dist[N][N];
ll n,m;
ll adj[N][N];
void Dijkstra( )
{
    fo(i,n)fo(j,m)dist[i][j]=OO;
    dist[0][0] = adj[0][0];
    priority_queue< pair<ll, pair< ll, ll>> > pq;
    pq.push({-adj[0][0],{0,0}});
    while(!pq.empty())
    {
        pair<ll,ll> node = pq.top().second ; ll distance = -pq.top().first;
        pq.pop();
        if(node.F==n-1&& node.S==m-1)break;
        if(distance > dist[node.F][node.S])
            continue;
        fo(i,4)
        {
            ll xx=node.F+dx[i],yy=node.S+dy[i];
            if(xx<0||xx>=n||yy<0||yy>=m)continue;

            if(dist[node.F][node.S] +adj[xx][yy]  < dist[xx][yy])
            {
                dist[xx][yy] = dist[node.F][node.S] +adj[xx][yy];
                pq.push({-dist[xx][yy],{xx,yy}});
            }
        }
    }
}
int main() {
        //freopen("input.txt","rt",stdin);
        //freopen("output.txt","wt",stdout);
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        ll t;cin>>t;
        while(t--){
            cin>>n>>m;
            fo(i,n){
                fo(j,m)cin>>adj[i][j];
            }
            Dijkstra();
            if(dist[n-1][m-1]==OO)cout<<"-1\n";
            else
            cout<<dist[n-1][m-1]<<'\n';
        }
}
