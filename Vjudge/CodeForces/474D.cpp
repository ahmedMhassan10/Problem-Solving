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
const ll OO = 1e5+3, mod = 1e9 + 7, N = 1e5+5;
ll dp[N+1],num,k;
int solve(int index){
    if(index==0)return 1;
    if(index<0)return 0;
    if(dp[index]!=-1)return dp[index];
    ll s1=0,s2=0;
    s1+=solve(index-1)%mod;
    s2+=solve(index-k)%mod;
    ll ans=s1+s2; dp[index]=(ans+mod)%mod;
    return dp[index];
}
int main() {
   // freopen("survive.in "," r ",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    clr(dp,-1);
    cin>>num>>k;
    solve(N-2);
    dp[0]=0;
    fp(i,1,N-2){
        dp[i]+=dp[i-1];
        dp[i]=(mod+dp[i])%mod;
    }
    while(num--){
        int u,v;cin>>u>>v;
        ll ans=(mod+dp[v]-dp[u-1])%mod;
        cout<<ans<<"\n";
    }
}