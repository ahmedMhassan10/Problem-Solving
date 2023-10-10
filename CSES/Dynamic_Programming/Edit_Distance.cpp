#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree< pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define clr(v, d)			memset(v, d, sizeof(v))
#define int long long
#define ll long long

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
const int OO =1e18, mod = 1e9+7,mod2=1e9+9, N =5000+5,M=30,MOD= 998244353, minOO=LLONG_MIN;
///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة
/// :-)
/// a33333333333333333333333333333333333333333333333333333333333333333333333333333333333333

string str1,str2;
ll dp[N][N];
ll solve(int fi,int se){
    if(fi==(str1.size())&&se==(str2.size()))
    {
        return 0;
    }
//    if(fi==(str1.size())||se==(str2.size()))
//    {
//        return OO;
//    }
    if(dp[fi][se]!=-1)return dp[fi][se];
    ll s1=OO,s2=OO,ans=OO;
    if(fi<str1.size()&&se<str2.size()){
        if (str1[fi] != str2[se]) {
            ans = 1 + solve(fi + 1, se + 1);
        } else {
            ans = solve(fi + 1, se + 1);
        }
    }
    if(fi<str1.size())
        s1=1+solve(fi+1,se);
    if(se<str2.size())
        s2=1+solve(fi,se+1);
    ans= min(ans,min(s1,s2));
    dp[fi][se]=ans;
    return ans;
}

void func(int index) {
    ::memset(dp,-1, sizeof(dp));
    cin>>str1>>str2;
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