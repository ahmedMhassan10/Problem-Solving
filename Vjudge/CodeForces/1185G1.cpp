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
const ll OO = 1e9, mod = 1e9 + 7, N = 17;
int n,t;
vp vec(N);ll dp[33000][4];
ll solve(int msk,int type){

    ll tot=0;
    fo(i,n){
        if(msk&(1<<i)){
            tot+=vec[i].F;
        }
    }
    if(tot>=t)
        return t==tot;
    if(dp[msk][type]!=-1)return dp[msk][type];
    ll ans=0;
    fo(i,n){
        if((msk&(1<<i))||type==vec[i].S)continue;
        ans=(ans+solve(msk|(1<<i),vec[i].S))%mod;
    }
    return dp[msk][type]= ans;
}
void testCase(){
    cin>>n>>t;
    fo(i,n)cin>>vec[i].F>>vec[i].S;
    clr(dp,-1);
    cout<<solve(0,0);
}
int main() {
       // freopen("survive.in "," r ",stdin);
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int t=1;
        //cin>>t;
        while(t--){
            testCase();
        }
}
