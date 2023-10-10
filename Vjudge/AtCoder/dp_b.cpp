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
#define maxe(x, y, z) max(x, min(y, z))
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
const ll OO = 1e17, mod = 1e9 + 7, N = 1e5+5;
ll dp[N],num,k;
bool vis[N];
vector<ll>vec(N);
ll solve(ll index){
    if(index<=0)return 0;
    if(vis[index])return dp[index];
    ll s1=OO,ans=OO;
    vis[index]=1;
    fp(i,1,k){
        if(index-i>=0){
            s1=abs(vec[index]-vec[index-i])+solve(index-i);
            ans=min(ans,s1);
        }
    }
    dp[index]=ans;
     return ans;
}
int main() {
   // freopen("survive.in "," r ",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>num>>k;
    fo(i,num){cin>>vec[i];}
    cout<<solve(num-1)<<'\n';
}
