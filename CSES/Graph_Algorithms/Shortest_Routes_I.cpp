#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v) ((v).begin()), ((v).end())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < siz(v); ++i)
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
typedef pair<ll,ll> pll;
typedef vector<pll> vp;
typedef vector< long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define setp(item) cout<<fixed<<setprecision(item);
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO = 1e18, mod = 1e9+7,mod2=1e9+9, N =2e5+5,M=30,MOD=998244353;

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
        ll node = pq.top().second , distance = -pq.top().first;
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
void testCase()
{
    cin >> n >> m ;
    for ( ll i = 0 ; i < m ;i++)
    {
        ll u, v ,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
    }
    Dijkstra(1);
    fp(i,1,n){
        cout<<dist[i]<<" ";
    }
}
void solve(ll inde) {
        
}


int main() {
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t=1;
//    cin>>t;
    ll index=1;
    while (t--){
//        solve(index++);
        testCase();
    }
    return 0;
}

