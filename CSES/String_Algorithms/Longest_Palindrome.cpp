#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")

#define clr(v, d)			memset(v, d, sizeof(v))
#define ll long long
#define int long long
typedef tree< pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define setP(item) cout<<fixed<<setprecision(item);
int ceilSqrt(int a){
    return ::ceil(sqrtl(a));
}
int  divC(int a,int b){
    return a/b+(a%b!=0);
}
int gcd(int a, int b) { return ((b == 0) ? a : gcd(b, a % b)); }
int lcm(int a,int b){return (a*b)/gcd(a,b);}
const ll OO =1e18+10, mod = 1e9+7,mod2=1e9+9,  N=2e5+5,M=25,MOD= 998244353, minOO=LLONG_MIN;
const double EPS=1e-10;
const double PI=acos(-1);
const ll maximum=2500+6;
const int NOT_VISITED = -1;
void manacher(string s,vector<int>&dp) {
    int n = s.size();
    dp=vector<int>(n+5);
    s = "$" + s + "^";
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        dp[i] = max((ll)0, min(r - i, dp[l + (r - i)]));
        while(s[i - dp[i]] == s[i + dp[i]]) {
            dp[i]++;
        }
        if(i + dp[i] > r) {
            l = i - dp[i], r = i + dp[i];
        }
    }

}
void manacher_odd(string s,vector<int>&dp){
    manacher(s,dp);
    for (int i = 0; i < dp.size(); ++i) { // dp[i]= (len+1)/2
        dp[i]=max((ll)0,2*dp[i]-1);
    }
}
void manacher_even(string s,vector<int>&dp){
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    t+="#";
    manacher(t ,dp);
    vector<int>dp2;
    for (int i = 1; i < dp.size() ; i+=2) {
        ll v=2*dp[i]-2;
        v=v/2;
        dp2.push_back(v);
    }
    dp=dp2;
}
void func(int index){
    string str;cin>>str;
    vector<int>dp;
    manacher_odd(str,dp);
    vector<int>dp2;
    manacher_even(str,dp2);
    str="#"+str;
    ll maxODD=*max_element(dp.begin(),dp.end());
    ll maxEVEN=*max_element(dp2.begin(),dp2.end());
    if(maxEVEN<maxODD){
        for (int i = 1; i < dp.size(); ++i) {
            if(dp[i]==maxODD){
                ll start=i-dp[i]/2;
                for (int j = start; j < start+maxODD ; ++j) {
                    cout<<str[j];
                }
                return;
            }
        }
    }else{
        for (int i = 1; i < dp2.size(); ++i) {
            if(dp2[i]==maxEVEN){
                ll start=i-dp2[i]/2+1;
                for (int j = start; j < start+maxEVEN ; ++j) {
                    cout<<str[j];
                }
                return;
            }
        }
    }

}

signed main() {
//    freopen("ysys.in","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
//    cin>>t;
    ll index=1;
    while (t--){
        func(index++);
    }
    return 0;
}