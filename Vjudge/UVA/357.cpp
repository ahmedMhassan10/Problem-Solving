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
const ll OO = 1e5+5, mod = 1e9 + 7, N =  30000+5;
vector<int>vec={50,25,10,5,1};
ll num;
ll dp[6][N];
ll solve(ll index,ll sum){
    if(sum==num||index>=4)return 1;
    else if(sum>num)return 0;
    if(dp[index][sum]!=-1)return dp[index][sum];
    ll s1=0,s2=0;
    if(sum+vec[index]<=num)
    s1+=solve(index,sum+vec[index]);
    s2+=solve(index+1,sum);
    ll ans= s1+s2;
    dp[index][sum]=ans;
    return ans;
}
int main() {
   // freopen("survive.in "," r ",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(cin>>num ){
        clr(dp,-1);
         //cin>>num;
        ll ans=0;
        ans=solve(0,0);
        if(ans!=1)
        cout<<"There are "<<ans<< " ways to produce "<<num<<" cents change.\n";
        else
            cout<<"There is only 1 way to produce "<<num<<" cents change.\n";
    }
}
