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

/// a33333333333333333333333333333333333333333333333333333333333333333333333333333333333333
ll dp[1002][1<<11];
ll n,m;
ll add ( ll a , ll b, ll mod)
{
    return (a + b) % mod;
}
// from https://cses.fi/paste/aa7f764ca1d62a2e18cc36/
void calc(vector<int>&g,int mask,int i,int next){
    if(i>=n){
        g.push_back(next);
        return;
    }
    if(mask&(1<<i))
        calc(g,mask,i+1,next);
    else{
        ll item=mask&(1<<(i+1));
        bool tr=i<n-1;
        bool tr1=((mask&(1<<(i+1)))==0);
        bool tr3=tr&&tr1;
        if(tr3){
            calc(g,mask,i+2,next);
        }
        calc(g,mask|(1<<i),i+1,next|(1<<i));
    }
}
ll solve(int col,int mask){
    if(col>=m){
        return mask==0;
    }
    if(dp[col][mask]!=-1)
        return dp[col][mask];
    ll ans=0;
    vector<int>g;
    calc(g,mask,0,0);
    for(auto item:g){
        ans= add(ans, solve(col+1,item),mod);
    }
    return dp[col][mask]=ans;
}
void func(int index) {
    ::memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    cout<<solve(0,0);
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