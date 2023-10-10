#include <iostream>
#include<cmath>
#include<algorithm>
#include<sstream>
#include<cstring>
#include<vector>
#include<stack>
#include <cstdio>
#include <iomanip>
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
const ll OO = 1e9, mod = 1000000007   , N = 2005;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
int dp[N],coun[N],cost[N],num;//cost ->price of each package  ,coun->number of items
ll solve(int first){
    if(first==num){
        return 0;
    }
    if(dp[first]!=-1)return dp[first];

    ll ans= OO,sum=0;
    for(int j=first;j<num;j++){
        sum+=coun[j];
        ans=min(ans,(sum+10)*cost[j]+solve(j+1));
    }
    dp[first]=ans;
    return ans;
}
int main() {
   // freopen("survive.in "," r ",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        clr(dp,-1);
        cin>>num;
        fo(i,num){
            cin>>coun[i]>>cost[i];
        }
        cout<<solve(0)<<"\n";
    }
}
