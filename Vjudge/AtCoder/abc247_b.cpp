#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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

void func(int index){
    ll n;cin>>n;
    bool tr=1;
    vector<pair<string,string>>vec(n);
    map<string,int>ma;
    for (int i = 0; i < n; ++i) {
        cin>>vec[i].first>>vec[i].second;
        ma[vec[i].first]++;
        if(vec[i].first==vec[i].second)continue;
        ma[vec[i].second]++;
    }
    for (int i = 0; i < n; ++i) {
        if(ma[vec[i].first]>1&&ma[vec[i].second]>1){
            tr=0;
        }
    }
    if(tr){
        cout<<"Yes\n";
    }else cout<<"No\n";
}
signed main() {
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
//    cin>>t;
    ll index=1;
    while (t--){
        func(index++);
    }
    return 0;
}