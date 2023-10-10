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
const ll OO = 1e18, mod = 1e9+7,mod2=1e9+9, N =500+5,M=30,MOD=998244353;
ll dist[N][N],n;
void floyed_warshal(){
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
void testcase(){
    cin>>n;
    ll m;cin>>m;
    ll q;cin>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)
                dist[i][j]=OO;
            else dist[i][j]=0;
    for(int i=0;i<m;i++){
        ll u,v,w;cin>>u>>v>>w;
        dist[u][v]=min(w,dist[u][v]);
        dist[v][u]=min(w,dist[v][u]);
    }
    floyed_warshal();
    while (q--){
        ll u,v;cin>>u>>v;
        if(dist[u][v]==OO)
        {
            cout<<"-1\n";
        }else cout<<dist[u][v]<<'\n';
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
        testcase();
    }
    return 0;
}

