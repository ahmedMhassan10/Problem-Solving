#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree< pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define clr(v, d)			memset(v, d, sizeof(v))
#define ll long long

#define int long long

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
const int OO =1e18, mod = 1e9+7,mod2=1e9+9, N =2e5+5,M=30,MOD= 998244353, minOO=LLONG_MIN;

///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة

/// a33333333333333333333333333333333333333333333333333333333333333333333333333333333333333
vector<vector<int>>dp(M,vector<int>(N));
vector<int>len(N);
vector<int>vis(N);
void dfs(int node){
    vis[node]=1;
    if(vis[dp[0][node]]==0){
        dfs(dp[0][node]);
    }
    len[node]=len[dp[0][node]]+1;
}
int findKthAncestor(int x, int d) {
    if (d <=0) return x;
    int i = 0;
    while(d > 0) {
        if (d&1)
            x = dp[i][x];
        d>>=1;
        i++;
    }
    return x;
}
void func(ll index) {
    ll n,q;cin>>n>>q;
    for (int i = 1; i <=n ; ++i) {
        cin>>dp[0][i];
    }
    for (int i = 1; i < M; ++i) {
        for (int j = 1; j <=n ; ++j) {
            dp[i][j]=dp[i-1][dp[i-1][j]];
        }
    }
    for (int i = 1; i <=n ; ++i) {
        if(vis[i])continue;
        dfs(i);
    }
    while (q--)
    {
        ll x,y;cin>>x>>y;
        ll z= findKthAncestor(x,len[x]);
        ll t1= findKthAncestor(x,len[x]-len[y]);
        ll t2= findKthAncestor(z,len[z]-len[y]);
        if(t1==y){
            cout<<len[x]-len[y]<<'\n';
        }else if(t2==y){
            cout<<len[z]+len[x]-len[y]<<'\n';
        }else cout<<"-1\n";
    }
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