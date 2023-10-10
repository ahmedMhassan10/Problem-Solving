#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define clr(v, d)			memset(v, d, sizeof(v))
#define ll long long
#define int long long
const ll OO =1e18, mod = 1e9+7,mod2=1e9+9,  N=2e5+5,M=30,MOD= 998244353, minOO=LLONG_MIN;
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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

///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة

/// a33333333333333333333333333333333333333333333333333333333333333333333333333333333333333


int getMex(set<int>&se){
    ll v=0;
    while (se.find(v)!=se.end())v++;
    return v;
}
ll dp[10000];
int solve(int idx){
    if (idx==0||idx==1)return 0;
    if(dp[idx]!=-1)return dp[idx];
    set<int>se;
    for (int i = 1; i <=idx ; ++i) {
        if(i!=idx&&(idx-i)!=i){
            se.insert(solve(idx-i)^ solve(i));
        }
    }
    return dp[idx]= getMex(se);
}
void func(int index) {
    ll n;cin>>n;
    if(n<1500){
        if(solve(n)==0){
            cout<<"second\n";
        }else cout<<"first\n";
    }else cout<<"first\n";
//    for (int n = 0; n < 10000; ++n) {
//        if(solve(n)==0)
//        cout<<n<<" ---> "<<solve(n)<<endl;
//    }
//    ll n;cin>>n;
//    if(n%2==0)cout<<"first\n";
//    else cout<<"second\n";
}
signed main() {
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
    clr(dp,-1);
    cin>>t;
    ll index=1;
    while (t--){
        func(index++);
    }
    return 0;
}