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
const ll OO = 1e18, mod = 1e9 + 7, N =  2005;
ll num,k;
ll dp[N][N];
ll solve(int index,int counter){
        if(counter==0)return 1;
       if(dp[index][counter]!=-1)return dp[index][counter];

        ll ans=0;
        for(int i=index;i<=num;i+=index){
                if(i%index==0)
                    ans+=solve(i,counter-1);
        }
        ans=(ans+mod)%mod;
        dp[index][counter]=ans;
        return ans;
}
int main() {
   // freopen("survive.in "," r ",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
            clr(dp,-1);
            cin>>num>>k;
            cout<<solve(1,k);
}
