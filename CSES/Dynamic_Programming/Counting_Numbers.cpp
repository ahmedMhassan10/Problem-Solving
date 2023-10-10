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
string convert(ll num){
    string s="";
    while (num){
        s=char ('0'+num%10)+s;
        num/=10;
    }
    return s;
}
ll n;
string maxString,minString ;
ll dp[21][11][2][2];
ll solve(int index,int last,bool maximum,bool minimum,int maxi){
    if(index==n)
    {
        return 1;
    }
    if(dp[index][last][maximum][minimum]!=-1)
        return dp[index][last][maximum][minimum];
    char st='0',en='9';
    if(maximum)en=maxString[index];
    if(minimum)st=minString[index];
    ll ans=0;
    for (;st<=en;st++) {
        if((st-'0')==last&&maxi!=0)continue;
        bool tempMini=(st==minString[index]),tempMaxi=(st==maxString[index]);
        maxi=max(maxi,(int)(st-'0'));
        ans=(ans+ solve(index+1,st-'0',tempMaxi&&maximum,tempMini&&minimum,maxi));
    }
    return dp[index][last][maximum][minimum]=ans;
}
void func(int index) {
    cin>>minString>>maxString;
//    maxString= convert(r),minString= convert(l);
    while (maxString.size()!=minString.size()){
        minString="0"+minString;
    }
    n=maxString.size();
    clr(dp,-1);
    ll ans=solve(0,0,'9',1,0);
    cout<<ans;
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