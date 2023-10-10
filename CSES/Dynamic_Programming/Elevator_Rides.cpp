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
ll n,x;
vector<int>vec(22);
pair<int,int> dp[1<<21];
pair<int,int>solve(int mask){
    if(__builtin_popcount(mask)==n){
        return {1,0};
    }
    pair<int,int>p={-1,-1};
    if(dp[mask] != p){
        return dp[mask];
    }
    pair<int,int>res={OO,OO};
    for (int i = 0; i < n; ++i) {
        if(mask& 1<<i)continue;
        pair<int,int>temp=solve(mask|1<<i);
        if(vec[i]+temp.second<=x){
            res=min(res,{temp.first,vec[i]+temp.second});
        }else res=min(res,{1+temp.first,min(vec[i],temp.second)});
    }
    return dp[mask]=res;
}
void func(int index) {
    cin>>n;cin>>x;
    for (int i = 0; i < n; ++i) {
        cin>>vec[i];
    }
    ::memset(dp,-1, sizeof(dp));
    cout<<solve(0).first;
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