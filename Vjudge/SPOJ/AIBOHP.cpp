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
const ll OO = 1e18, mod = 1000000007   , N = 6100+5;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
ll dp[N][N];
string str;

int maxPalinSubSeq(int i,int j){
    if(i==j)
        return 1;
    if(i+1==j && str[i]==str[j])
        return 2;
    if(dp[i][j]!=-1)return dp[i][j];
    if(str[i]==str[j])
        return dp[i][j]=2+maxPalinSubSeq(i+1,j-1);
    else
        return dp[i][j]=max(maxPalinSubSeq(i+1,j),maxPalinSubSeq(i,j-1));
}
int main() {
   // freopen("survive.in "," r ",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>str;clr(dp,-1);
        cout<<siz(str)-maxPalinSubSeq(0,siz(str)-1)<<"\n";
    }
}
