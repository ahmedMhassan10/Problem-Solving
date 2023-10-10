#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
//
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")

#define clr(v, d)			memset(v, d, sizeof(v))
#define ll long long
#define int long long
typedef tree< pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define setp(item) cout<<fixed<<setprecision(item);
int ceilSqrt(int a){
    return ::ceil(sqrtl(a));
}
int  divC(int a,int b){
    return a/b+(a%b!=0);
}
int gcd(int a, int b) { return ((b == 0) ? a : gcd(b, a % b)); }
int lcm(int a,int b){return (a*b)/gcd(a,b);}
const ll OO =1e18+10, mod = 1e9+7,mod2=1e9+9,  N=1e5+5,M=25,MOD= 998244353, minOO=LLONG_MIN;
const double EPS=1e-10;
const double PI=acos(-1);
const ll maximum=500+6;
const int NOT_VISITED = -1;

vector<int>leaves;
vector<vector<int>>adj(N);
void dfs(int node,int par){
    for (auto item:adj[node]) {
        if(item==par)continue;
        dfs(item,node);
    }
    if(adj[node].size()==1)
    leaves.push_back(node);
}
void func(int index){
   ll n;cin>>n;
    for (int i = 1; i < n; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    vector<pair<int,int>>res;
    for (int i = 0; i < leaves.size()/2; ++i) {
        res.push_back({leaves[i],leaves[i+leaves.size()/2]});
    }
    if(leaves.size()%2){
        res.push_back({leaves[leaves.size()/2],leaves.back()});
    }
    cout<<res.size()<<endl;
    for (auto [u,v]:res) {
        cout<<u<<" "<<v<<endl;
    }
}
signed main() {
//    freopen("ysys.in","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
//    cin>>t;
    ll index=1;
    while (t--){
        auto start=chrono::system_clock::now();
        func(index++);
        auto end=chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
//        cout<<elapsed_seconds.count()<<endl;
    }
    return 0;
}