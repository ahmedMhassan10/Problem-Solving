#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree< pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define clr(v, d)			memset(v, d, sizeof(v))
#define ll long long

#define int long long

#define setp(item) cout<<fixed<<setprecision(item);
#define PI 3.14159265358979323846264338327950
int ceilSqrt(int a){
    return ::ceil(sqrtl(a));
}
int  divC(int a,int b){
    return a/b+(a%b!=0);
}
int gcd(int a, int b) { return ((b == 0) ? a : gcd(b, a % b)); }
int lcm(int a,int b){return (a*b)/gcd(a,b);}
const int OO =1e18, mod = 1e9+7,mod2=1e9+9, N =2e5+5,M=30,MOD= 998244353, minOO=LLONG_MIN;
///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة
/// :-)
/// a33333333333333333333333333333333333333333333333333333333333333333333333333333333333333
ll add ( ll a , ll b, ll mod)
{
    return (a + b) % mod;
}
ll sub ( ll a , ll b, ll mod)
{
    return (a - b +mod) % mod;
}
ll mul ( ll a , ll b, ll mod)
{
    return (1LL * a * b) % mod;
}
ll fop( ll b , ll p, ll mod)
{
    if(!p)
        return 1;
    ll temp = fop(b,p/2,mod)%mod;
    temp = mul(temp,temp,mod);
    if(p&1)
        temp = mul(temp,b,mod);
    return temp%mod;
}
ll  modInverse(ll  n, ll mod){return fop(n, mod - 2, mod);}
ll dp[505][502*502/2];
ll n;
ll solve(int index,int sum){
    if(index==n+1){
        return sum==0;
    }
    if(dp[index][sum]!=-1)return dp[index][sum];
    ll ans= solve(index+1,sum);
    if(sum>=index){
        ans=add(ans, solve(index+1,sum-index),mod);
    }
    return dp[index][sum]=ans;
}
void func(int index) {
    cin>>n;
    ll total=n*(n+1)/2;
    ll res=0;
    if(total%2){
        cout<<0;
        return;
    }
    ::memset(dp,-1,sizeof(dp));
    res= mul(solve(1,total/2), modInverse(2,mod),mod);
    cout<<res;
}
signed main() {
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
//    cin>>t;
    int index=1;
    while (t--){
        func(index++);
    }
    return 0;
}