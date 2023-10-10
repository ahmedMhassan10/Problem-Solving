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
const ll OO = 1e15, mod = 1e9 + 7,mod2=1e9+9, N =100000 ,M=23;

ll n ,m ;
vector<ll>dist(N),par(N);
vector < pair < ll, ll> > g[N];

void Dijkstra( ll src)
{
    dist.assign(n+1,OO);
    par.assign(n+1,-1);
    dist[src] = 0;
                    //  distance node
    priority_queue< pair < ll, ll> > pq;
    pq.push({0,src});
    while(!pq.empty())
    {
        int node = pq.top().second , distance = -pq.top().first;
        pq.pop();
        if(distance > dist[node])
            continue;
        for(auto ch : g[node])
        {
            if(dist[node] + ch.second < dist[ch.first])
            {
		par[ch.first]=node;
                dist[ch.first] = dist[node] + ch.second;
                pq.push({-dist[ch.first],ch.first});
            }
        }
    }
}
void getpath(ll num){
	vector<ll>vec;
	while(num!=-1){
		vec.pb(num);
		num=par[num];
	}
	fn(i,siz(vec)-1,0){
		cout<<vec[i]<<" ";
	}

}
void testCase()
{
    cin >> n >> m ;
    fo(i,n+1){
        g[i].clear();
    }

    ll st,en;cin>>st>>en;
    for ( ll i = 0 ; i < m ;i++)
    {
        int u, v ,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    Dijkstra(st);
    if(dist[en]==OO)cout<<"NONE\n";
    else cout<<dist[en]<<'\n';
}

int main() {
        //freopen("input.txt","rt",stdin);
        //freopen("output.txt","wt",stdout);
        int t;cin>>t;
        while(t--){
            testCase();

        }
}
