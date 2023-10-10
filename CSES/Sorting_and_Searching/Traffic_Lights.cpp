#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree< pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
const int OO =1e15, mod = 1e9+7,mod2=1e9+9, N =2e5+5,M=30,MOD= 998244353, minOO=LLONG_MIN;
///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة
/// :-)
/// a33333333333333333333333333333333333333333333333333333333333333333333333333333333333333
void func(int index) {
    ll n,m;
    cin>>n>>m;
    set<pair<int,int>> os;
    set<pair<int,pair<int,int>>,greater<pair<int,pair<int,int>>>>se;
    os.insert({0,n});
    se.insert({n,{0,n}});
    for (int i = 0; i < m; ++i) {
        ll v;cin>>v;
        auto it=os.upper_bound({v,-1});
        it--;
        auto item=*it;
        os.erase(it);
        se.erase({item.second-item.first,item});
        if(v!=item.first){
            pair<int,int> it1={item.first,v};
            os.insert(it1);
            se.insert({it1.second-it1.first,it1});
        }
        if(v!=item.second){
            pair<int,int> it1={v,item.second};
            os.insert(it1);
            se.insert({it1.second-it1.first,it1});
        }
        cout<<(se.begin())->first<<" ";
    }
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