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
const ll OO = 1e9, mod = 1e9 + 7, N = 15;
int n,m,q;
vp vec(N);
ll dp[15][1500];
ll solve(int index,int msk){
    if(__builtin_popcount(msk) == q)
        return abs(vec[0].S-vec[index].S)+abs(vec[0].F-vec[index].F);
    if(dp[index][msk]!=-1)return dp[index][msk];
    ll ans=OO;
    fp(i,1,q){
        if(msk&1<<(i-1))continue;
        ans =min(ans,abs(vec[i].S-vec[index].S)+abs(vec[i].F-vec[index].F)+solve(i,msk|1<<(i-1)));
    }
    return dp[index][msk]=ans;
}
void testCase(){
    vec.clear();
    clr(dp,-1);
    cin>>n>>m;
    cin>>vec[0].F>>vec[0].S;
    cin>>q;
    fp(i,1,q){
        cin>>vec[i].F>>vec[i].S;
    }
    cout << "The shortest path has length ";
    cout << solve(0,0) << "\n";
}
int main() {
       // freopen("survive.in "," r ",stdin);
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int t;cin>>t;
        while(t--){
            testCase();
        }
}
