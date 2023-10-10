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
#define setp(item) cout<<fixed<<setprecision(item);
const ll OO = 1e9, mod = 1000000007   , N =2000+5;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
int main() {
   // freopen("survive.in "," r ",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector <vector<ll>>dp(N,vector<ll>(N));
    int t;cin>>t;
    while(t--){
        string str1,str2;
        cin>>str1>>str2;
        fo(i,N){
            dp[i].assign(N,OO);
            dp[i][0]=i;
            dp[0][i]=i;
        }
        for(int i=1;i<=siz(str1);i++){
            for(int j=1;j<=siz(str2);j++){
                    if(str1[i-1]!=str2[j-1])
                        dp[i][j]=mine(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1);
                    else
                        dp[i][j]=mine(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]);
            }
        }
        cout<<dp[siz(str1)][siz(str2)]<<"\n";
    }
}
