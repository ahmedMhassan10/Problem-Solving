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
typedef tree< pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define setp(item) cout<<fixed<<setprecision(item);
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO =1e18, mod = 1e9+7,mod2=1e9+9, N =2e5+5,M=30,MOD=998244353, minOO=LLONG_MIN;
///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة
int n, k;
vector<int> g[N];
int sz[N];

ll ans = 0;
int cnt[200001]{1}, mx_depth;
bool processed[200001];

int get_subtree_sizes(int node, int parent = 0) {
    sz[node] = 1;
    for (int i : g[node]) if (!processed[i] && i != parent)
            sz[node] += get_subtree_sizes(i, node);
    return sz[node];
}

int get_centroid(int desired, int node, int parent = 0) {
    for (int i : g[node])
        if (!processed[i] && i != parent && sz[i] >= desired)
            return get_centroid(desired, i, node);
    return node;
}

void get_cnt(int node, int parent, bool filling, int depth = 1) {
    if (depth > k) return;
    mx_depth = max(mx_depth, depth);
    if (filling)
        cnt[depth]++;
    else
        ans += cnt[k - depth];
    for (int i : g[node])
        if (!processed[i] && i != parent)
            get_cnt(i, node, filling, depth + 1);
}

void centroid_decomp(int node = 1) {
    int centroid = get_centroid(get_subtree_sizes(node) >> 1, node);
    processed[centroid] = true;
    mx_depth = 0;
    for (int i : g[centroid])
        if (!processed[i]) {
            get_cnt(i, centroid, false);
            get_cnt(i, centroid, true);
        }
    fill(cnt + 1, cnt + mx_depth + 1, 0);
    for (int i : g[centroid])
        if (!processed[i])
            centroid_decomp(i);
}
void func(int inde) {
    ll num;cin>>num>>k;
    fo(i,num-1){
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    centroid_decomp();
    cout<<ans<<'\n';
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