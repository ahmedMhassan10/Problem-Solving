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
const ll OO = 1e9, mod = 1e9+7,mod2=1e9+9, N =1e4+5,M=23;

ll n ,m ;
vector<vll>dist(N,vll(2));
vector<ll>par(N);
vector<pair < ll, ll>>g[N];

void Dijkstra( ll src)
{
    dist[1][0] = 0;
    priority_queue< pair<ll,pair < ll, ll>> > pq;
    pq.push({0,{0,1}});
    while(!pq.empty())
    {
        ll node = pq.top().second.S,rem=pq.top().second.F, distance = -pq.top().first;
        pq.pop();
        for(auto ch : g[node])
        {
                 if(dist[node][rem] + ch.second < dist[ch.first][(rem+1)%2])
                {
                    dist[ch.first][(rem+1)%2] = dist[node][rem] + ch.second;
                    pq.push({-dist[ch.first][(rem+1)%2],{(rem+1)%2,ch.first}});
                }
        }
    }
}
void testCase()
{
    fp(i,0,n){
        g[i].clear();
        dist[i][0]=OO;
        dist[i][1]=OO;
        par[i]=0;
    }
    for ( ll i = 0 ; i < m ;i++)
    {
        ll u, v ,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    Dijkstra(1);
    if(dist[n][0]==OO)cout<<"-1\n";
    else cout<<dist[n][0]<<'\n';
}


int main() {
        //freopen("input.txt","rt",stdin);
        //freopen("output.txt","wt",stdout);
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        //int t;cin>>t;
        while(cin>>n>>m){
                if(n+m ==0)break;
            testCase();
        }
}
