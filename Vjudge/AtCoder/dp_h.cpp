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
const ll OO = 1e5+5, mod = 1e9 + 7, N = 1e3+1;
vs vec(N);
ll row,col;
ll dp[N][N];
ll solve(int x,int y){
    if(x==row-1&&y==col-1)return 1;
    if(dp[x][y]!=-1)return dp[x][y];
    ll ans=0;
    if(x<row-1&&vec[x+1][y]=='.')
        ans+=(solve(x+1,y)+mod)%mod;
    if(y<col-1&&vec[x][y+1]=='.')
        ans+=(solve(x,y+1)+mod)%mod;
    ans=dp[x][y]=(ans+mod)%mod;
    return ans;
}
int main() {
   // freopen("survive.in "," r ",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    clr(dp,-1);
    cin>>row>>col;
    fo(i,row)cin>>vec[i];
    cout<<solve(0,0);
}
