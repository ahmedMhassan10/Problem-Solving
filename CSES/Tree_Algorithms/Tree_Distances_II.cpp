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
typedef pair<int,int> pi;

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


///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة

ll num;
vector<vector < int > >adj(N);
vector<bool>vis(N,0);
vll dist(N,0);
vll nodes(N,0);

void dfs( int node)
{
    vis[node] = true;
    for ( auto child : adj[node]) {
        if (vis[child] == false) {
            dfs(child);
            nodes[node] += 1 + nodes[child];
            dist[node]+=dist[child];
        }
    }
    dist[node]+=nodes[node];
}

void dfs2( int node)
{
    vis[node] = true;
    for ( auto child : adj[node]) {
        if (vis[child] == false) {
            dist[child]+=(dist[node]-(nodes[child]+1)-dist[child])+(num-nodes[child]-1);
            dfs2(child);
        }
    }
}

void solve(int inde) {
    cin>>num;
    fo(i,num-1){
        ll u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    vis=vector<bool>(N,0);
    dfs2(1);
    fp(i,1,num)cout<<dist[i]<<" ";
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
        solve(index++);
    }
    return 0;
}
