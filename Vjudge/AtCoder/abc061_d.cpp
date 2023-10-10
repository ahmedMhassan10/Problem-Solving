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
const ll OO = 1e15, mod = 1e9+7,mod2=1e9+9, N =1e4+5,M=23;
ll dist[N] , n,m;
vector < pair < ll , pair < ll , ll > > > edges;
bool negCycle = false;
void Bellman_Ford( ll src)
{
    for ( ll i = 0 ; i <= n+10 ; i++)
        dist[i] = OO;
    dist[src] = 0;
    // O(n * m)
    for(ll i= 1 ; i<= n ; i++) {
        for(ll j = 0; j < edges.size(); j++) {
            ll u = edges[j].S.F, v = edges[j].S.S, w = edges[j].F;
            if (dist[u] + w < dist[v])
            {
                if(i == n&&v==n)
                    negCycle = true;
                dist[v] = dist[u] + w;
            }
        }
    }
}

void testcase(){
    cin >> n >> m ;
    for ( int i = 0 ; i < m ; i++)
    {
        ll u , v , w;
        cin >> u >> v >> w;
        edges.push_back({-w,{u,v}});
    }
    Bellman_Ford(1);
    if(negCycle)cout<<"inf\n";
    else cout<< -1*dist[n] <<'\n';
}
int main() {
        //freopen("input.txt","rt",stdin);
        //freopen("output.txt","wt",stdout);
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    testcase();
}
