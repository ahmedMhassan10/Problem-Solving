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
const ll OO = 1e5+5, mod = 1e9 + 7, N = 105;
ll dp[N][OO],num,k;
bool vis[N][OO];
ll valu[N],wei[N];
ll solve(ll index,ll w){
    if(index==num)return 0;
   if(vis[index][w])return dp[index][w];
    vis[index][w]=1;
    ll s1=0,s2=0;
    s1=solve(index+1,w);
    if(w>=wei[index])
        {s2=solve(index+1,w-wei[index])+valu[index];}
    ll ans =max(s1,s2);
    dp[index][w]=ans;
    return ans;
}
int main() {
   // freopen("survive.in "," r ",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>  num>>k;
    fo(i,num){
        cin>>wei[i]>>valu[i];
    }
   cout<< solve(0,k);
}
