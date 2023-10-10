#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define clr(v, d)			memset(v, d, sizeof(v))
#define ll long long
#define int long long
typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define setp(item) cout<<fixed<<setprecision(item);
#define PI 3.14159265358979323846264338327950

int ceilSqrt(int a){
    return ::ceil(sqrtl(a));
}
int  divC(int a,int b){
    return a/b+(a%b!=0);
}
int gcd(int a, int b) { return ((b == 0) ? a : gcd(b, a % b)); }
int lcm(int a,int b){return (a*b)/gcd(a,b);}
const ll OO =1e18, mod = 1e9+7,mod2=1e9+9, N =2e5+5,M=30,MOD= 998244353, minOO=LLONG_MIN;

///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة

/// a33333333333333333333333333333333333333333333333333333333333333333333333333333333333333
// get the minimum  Hamiltonian path
ll n;
ll dp[1<<20][20];
vector<vector<int>>adj(20);
ll solve(int mask,int node){
    if (__builtin_popcount(mask) == n)
            return node==n-1;
    if(node==n-1)return 0;
    if(dp[mask][node]!=-1)
        return dp[mask][node];
    ll ans=0;
    for (auto item:adj[node]) {
        if(mask&(1<<item))continue;
        ans=(ans+solve(mask|(1<<item),item)%mod);
        ans%=mod;
    }
    return dp[mask][node]=ans;
}
void func(int index)
{
    clr(dp,-1);
    cin>>n;
    ll m;
    cin>>m;
    for (int i = 0; i < m; ++i) {
        ll u,v;cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
//        adj[v].push_back(u);
    }
    cout<<solve(1,0);
}

signed main() {
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