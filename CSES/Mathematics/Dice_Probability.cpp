#include <bits/stdc++.h>
using namespace std;
#define clr(v, d)			memset(v, d, sizeof(v))
#define ll long long
#define int long long
#define ld long double
#define double long double
const ll OO =1e17+10, mod = 1e9+7,mod2=1e9+9,  N=3e5+5,M=25,MOD= 998244353, minOO=LLONG_MIN;

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

vector<vector<double>> dp(101,vector<double>(6*101,-1));
ll n,a,b;
double solve(int idx,int sum){
    if(idx==n)return (sum>=a)&&(sum<=b);
    if(sum>b)return 0;
    if(dp[idx][sum]>=0)
        return dp[idx][sum];
    double res=0;
    for (int i = 1; i <= 6 ; ++i) {
        res= res + (1.0/6)*solve(idx+1,sum+i);
    }
    return dp[idx][sum]=res;
}
void solve() {
    cout<<fixed<<setprecision(6);
    cin>>n>>a>>b;
    cout<<round(solve(0,0)*1e6)/1e6;
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