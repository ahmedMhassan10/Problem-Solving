#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define all(v) ((v).begin()), ((v).end())
#define allRev(v) ((v).rbegin()), ((v).rend())
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
#define PI 3.14159265358979323846264338327950
ll ceilSqrt(ll a){
    return ::ceil(sqrtl(a));
}
ll  divC(ll a,ll b){
    return a/b+(a%b!=0);
}
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO =1e15, mod = 1e9+7,mod2=1e9+9, N =3e3+5,M=30,MOD= 998244353, minOO=LLONG_MIN;
///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة
/// :-)
/// a33333333333333333333333333333333333333333333333333333333333333333333333333333333333333
ll dist[N] , n,m;
vector < pair < int , pair < ll, ll> > > edges;
bool negCycle = false;
map<ll,ll>ma;
void Bellman_Ford( ll  src)
{
    for ( int i = 1 ; i <= n ; i++)
        dist[i] = OO;
    dist[src] = 0;
    // O(n * m)
    for(int i= 1 ; i<= n ; i++) {
        for(int j = 0; j < edges.size(); j++) {
            int u = edges[j].S.F, v = edges[j].S.S, w = edges[j].F;
            if(dist[u]!=OO)    // -->> to return the negative cycle
                if (dist[u] + w < dist[v])
                {
                    if(i == n)
                    {
                        negCycle=1,ma[v]++;
                    }
                    dist[v] = dist[u] + w;
                }
        }
    }
}
vector<vll>adj(N);

vector<bool>vis(N);
void dfs(int node,int par){
    vis[node]=1;
    fvec(item,adj[node]){
        if(vis[item])continue;
        dfs(item,node);
    }
}
void func(int inde) {
    cin>>n>>m;
    fo(i,m){
        ll u,v,w;cin>>u>>v>>w;
        w=-w;
        edges.push_back({w,{u,v}});
        adj[u].push_back(v);
    }
    Bellman_Ford(1);
    if(negCycle){
        fvec(item,ma){
            if(vis[item.F]){
                continue;
            }
            dfs(item.F,0);
            if(vis[n]&&dist[item.F]!=OO){
                cout<<"-1\n";
                return;
            }
            vis=vector<bool>(n+1,0);
        }
        cout<<-dist[n];
    }else{
        cout<<-dist[n];
    }
}

int main() {
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
//    cin>>t;
    ll index=1;
    while (t--){
        func(index++);
    }
    return 0;
}