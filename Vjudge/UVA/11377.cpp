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
const ll OO = 1e9, mod = 1e9+7,mod2=1e9+9, N =2000+5,M=23;
ll n , m , k ;
vector<ll>dist(N),valu(N);
vector < pair < ll, ll> > g[N];
void Dijkstra( ll src)
{
    dist.assign(n+1,OO);
    dist[src] = valu[src];
    priority_queue< pair < ll, ll> > pq;
    pq.push({-valu[src],src});
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
                dist[ch.first] = dist[node] + ch.second;
                pq.push({-dist[ch.first],ch.first});
            }
        }
    }
}

int inde=0;
void testCase()
{
  
    cout<<"Case "<<++inde<<":\n";
    cin >> n >> m>>k ;
    fp(i,1,n){g[i].clear();valu[i]=1;}
    fo(i,k){
        ll item;
        cin>>item;
        valu[item]=0;
    }
    for ( ll i = 0 ; i < m ;i++)
    {
        ll u, v ;
        cin >> u >> v ;
        g[u].push_back({v,valu[v]});
        g[v].push_back({u,valu[u]});
    }
    ll q;cin>>q;
    while(q--){
        ll src,en;cin>>src>>en;
        Dijkstra(src);
        if(src==en)cout<<"0\n";
        else if(dist[en]==OO)cout<<"-1\n";
        else cout<<dist[en]<<'\n';
    }
}
int main() {
        //freopen("input.txt","rt",stdin);
        //freopen("output.txt","wt",stdout);
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        ll t;cin>>t;
        while(t--){
            testCase();
            cout<<'\n';
        }
}
