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

void func(int index) {
    ll n;cin>>n;
//    map<ll,ll>ma;
//    ll maxN=0;
//    for (int i = 0; i < n; ++i) {
//        ll temp;cin>>temp;
//        ma[temp]++;
//        maxN=max(maxN,ma[temp]);
//    }
//    ll v=0;
//    for (auto item:ma) {
//        if(item.first%2)
//            v^=item.second;
//    }
//    if(maxN>1) {
//        if (v)cout << "first";
//        else cout << "second";
//    }else{
//        if (v==0)cout << "first";
//        else cout << "second";
//    }
//    cout<<endl;
    ll v=0;
    for (int i = 0; i < n; ++i) {
        ll temp;cin>>temp;
        if(temp%2)v=1;
    }
        if (v)cout << "first\n";
        else cout << "second\n";
}
signed main() {
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
    cin>>t;
    ll index=1;
    while (t--){
        func(index++);
    }
    return 0;
}