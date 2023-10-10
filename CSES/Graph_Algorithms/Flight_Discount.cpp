#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define all(v) ((v).begin()), ((v).end())
#define invAll(v) ((v).rbegin()), ((v).rend())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define fo(i, n) for (long long i = 0; i < (long long)(n); ++i)
#define fp(i, j, n) for (long long i = (j); i <= (long long)(n); ++i)
#define fn(i, j, n) for (long long i = (j); i >= (long long)(n); --i)
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
typedef pair<int,int> pi;
typedef vector<pll> vp;
typedef vector< long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define setp(item) cout<<fixed<<setprecision(item);
#define div(a,b) a/b+(a%b!=0)
#define PI 3.14159265358979323846264338327950

ll ceilSqrt(ll a){
    return ::ceil(sqrtl(a));
}
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO =1e17, mod = 1e9+7,mod2=1e9+9, N =2e5+5,M=30,MOD= 998244353, minOO=-1e17;
///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة
/// :-)
/// a33333333333333333333333333333333333333333333333333333333333333333333333333333333333333
ll n;
vector<vector < pair < ll, ll> >> g(N),gg(N);
void Dijkstra( ll src,vll&dist,vector<vector < pair < ll, ll> >> &g)
{
    dist.assign(n+1,OO);
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
                dist[ch.first] = dist[node] + ch.second;
                pq.push({-dist[ch.first],ch.first});
            }
        }
    }
}
struct edge{
    ll st,en,w;
};
void func(int ind) {
    ll m;
    vector<edge>edges;
    cin >> n >> m ;
    for ( ll i = 0 ; i < m ;i++)
    {
        ll u, v ,w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
        g[u].push_back({v,w});
        gg[v].push_back({u,w});

    }
    vll fDist(n+4,0),sDist(n+4,0);
    Dijkstra(1,fDist,g);
    Dijkstra(n,sDist,gg);
    ll res=min(fDist[n],sDist[1]);
    fvec(item,edges){
        res=min(res,fDist[item.st]+sDist[item.en]+item.w/2);
//        res=min(res,sDist[item.st]+fDist[item.en]+item.w/2);
    }
    cout<<res<<'\n';
}
signed main() {
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
//    cin>>t;
    ll ind=1;
    while (t--){
        func(ind++);
    }
    return 0;
}