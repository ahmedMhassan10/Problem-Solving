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
const ll OO = 1e9, mod = 998244353  , N = 4005;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

ll dp [N];
int main() {
   // freopen("survive.in "," r ",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    clr(dp,0);
    int num,a,b,c;cin>>num>>a>>b>>c;
    for(int i=0;i<=num;i++){
        if(i-a>=0&&(i%a==0||dp[i-a]>0)){
            dp[i]=max(dp[i],1+dp[i-a]);
        }
        if(i-b>=0&&(i%b==0||dp[i-b]>0)){
            dp[i]=max(dp[i],1+dp[i-b]);
        }
        if(i-c>=0&&(i%c==0||dp[i-c]>0)){
            dp[i]=max(dp[i],1+dp[i-c]);
        }
    }
    cout<<dp[num];
}
