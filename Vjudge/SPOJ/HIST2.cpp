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
typedef vector<pair<int,int>> vp;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef unsigned long long ull;
typedef long long ll;
#define setp(item) cout<<fixed<<setprecision(item);
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO = 1e9, mod = 1e9 + 7, N = 18;

int n;
vi  vec(N);
vector<vp>dp;
pair<int,int>solve(int cur,int msk){
        if(msk==(1<<n)-1){
            return {vec[cur],1};
        }
        if(dp[cur][msk].F!=-1)return dp[cur][msk];
        fo(i,n){
            if(msk &1<<i)continue;
            if(dp[cur][msk].F<solve(i,msk|(1<<i)).F+abs(vec[cur]-vec[i])){
                dp[cur][msk]=solve(i,msk|(1<<i));
                dp[cur][msk].F+=abs(vec[cur]-vec[i]);
            }else if(dp[cur][msk].F==solve(i,msk|(1<<i)).F+abs(vec[cur]-vec[i]))
                {
                    dp[cur][msk].S+=solve(i,msk|(1<<i)).S;
                }
        }
        return dp[cur][msk];
}
void solve(){
    vec[n]=0;
    fo(i,n){
        cin>>vec[i];
    }
    cout<<solve(n,0).F+2*n<<" "<<solve(n,0).S<<'\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cout.tie(0);
    ll t=1;
    while(cin>>n&&n){
        vec.clear();
        dp.assign(N,vp(33000,{-1,-1}));
        solve();
    }

}
