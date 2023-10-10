#include <bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()), ((v).end())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < sz(v); ++i)
#define fo(i, n) for (int i = 0; i < (int)(n); ++i)
#define fp(i, j, n) for (int i = (j); i <= (int)(n); ++i)
#define fn(i, j, n) for (int i = (j); i >= (int)(n); --i)
#define fvec(i, vec) for (auto i : vec)
#define pb push_back
#define MP make_pair
#define mine(x, y, z) min(x, min(y, z))
#define maxe(x, y, z) max(x, max(y, z))
#define F first
#define S second
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef unsigned long long ull;
typedef long long ll;
const ll OO = 1e18, mod = 1e9 + 7, N =  105;
ll num,k,d;
ll dp[N][2];
ll solve(ll sum,int tr ){
    if(sum==0){
        if(tr==1)return 1;
        else return 0;
    }
    if(sum<0) return 0;
    if(dp[sum][tr]!=-1)return dp[sum][tr];
    ll ans=0;
    for(int i=1;i<=k;i++){
        if(i>=d)
            ans+=(solve(sum-i,1)+mod)%mod;
        else
            ans+=(solve(sum-i,tr)+mod)%mod;
    }
    //cout<<1;
    ans=(ans+mod)%mod;
    dp[sum][tr]=ans;
    return ans;
}
int main() {
   // freopen("survive.in "," r ",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
  // cin>>t;
    while(t--){
            clr(dp,-1);
            cin>>num>>k>>d;
            cout<<solve(num,0);
    }
}
