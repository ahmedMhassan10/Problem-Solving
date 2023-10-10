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
const ll OO = 1e9, mod = 1e9 + 7, N = 1e5+5;
ll dp[N],n,m;
bool vis[N];
unordered_map<int,vector<int>>vec;
ll solve(int v){
    if(dp[v]!=-1)return dp[v];
    if(siz(vec[v])==0) return dp[v]=0;
    vis[v]=1;
    ll ans=0;
    fvec(item,vec[v]){
        ans=max(ans,solve(item));
    }
    dp[v]=1+ans;
    return dp[v];
}
int main() {
   // freopen("survive.in "," r ",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    clr(dp,-1);
    cin>>n>>m;
    fo(i,m){
        int u,v;cin>>u>>v;
        vec[u].pb(v);
    }
    ll ans=0;
    fp(i,1,n){
       ans=max(ans,solve(i));
    }
    cout<<ans;
}
