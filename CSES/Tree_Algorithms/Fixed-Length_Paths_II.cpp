#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;


#define clr(v, d)			memset(v, d, sizeof(v))
#define ll long long
#define int long long
#define ld long double
typedef tree< pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define setP(item) cout<<fixed<<setprecision(item);
int ceilSqrt(int a){
    return ::ceil(sqrtl(a));
}
int  divC(int a,int b){
    return a/b+(a%b!=0);
}
int gcd(int a, int b) { return ((b == 0) ? a : gcd(b, a % b)); }
int lcm(int a,int b){return (a*b)/gcd(a,b);}
const ll OO =1e18+10, mod = 1e9+7,mod2=1e9+9,  N=2e5+5,M=25,MOD= 998244353, minOO=LLONG_MIN;
const double EPS=1e-10;
const double PI=acos(-1);
const ll maximum=2500+6;
const int NOT_VISITED = -1;


#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
//#pragma GCC target("popcnt")
struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    int sum(int l, int r) {
        if(l>r)return 0;
        return sum(r) - sum(l - 1);
    }
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int n, k1,k2;
vector<int> g[N];
int sz[N];
ll ans = 0;
bool processed[N];

int get_subtree_sizes(int node, int parent = 0) {
    sz[node] = 1;
    for (int i : g[node])
        if (!processed[i] && i != parent)
            sz[node] += get_subtree_sizes(i, node);
    return sz[node];
}

int get_centroid(int desired, int node, int parent = 0) {
    for (int i : g[node])
        if (!processed[i] && i != parent && sz[i] >= desired)
            return get_centroid(desired, i, node);
    return node;
}
void sol(int node,int par,int dep,vector<int>&dis){
    if(dep>k2)return;
    dis.push_back(dep);
    for (auto item:g[node]) {
        if(processed[item]||item==par)continue;
        sol(item,node,dep+1,dis);
    }
}
void centroid_decomp(int node = 1) {
    int val=get_subtree_sizes(node);
    int centroid = get_centroid(val >> 1, node);
    processed[centroid] = true;
    FenwickTree fenTree=FenwickTree((val)*3);
    fenTree.add(0,1);
    vector<int>dis;
    for (int i : g[centroid])
        if (!processed[i]) {
            dis.clear();
            sol(i,centroid,1,dis);
            for (auto item:dis) {
                ans += fenTree.sum(max(0ll,k1-item),min(val,k2-item));
            }
            for (auto item:dis) {
                fenTree.add(item,1);
            }
        }
    for (int i : g[centroid])
        if (!processed[i])
            centroid_decomp(i);
}
void solve() {
    cin>>n>>k1>>k2;
    for(int i=0;i<n-1;i++){
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    centroid_decomp();
    cout<<ans;
}
signed main() {
//    freopen("ysys.in","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
//    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}