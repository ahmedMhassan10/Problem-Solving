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
    multiset<pair<int,int>>se;
    ll n;cin>>n;
    ll res=0;
    vector<pair<int,pair<int,int>>>input(n);
    vector<int>vec(n);
    for (int i = 0; i < n; ++i) {
        cin>>input[i].first>>input[i].second.first;
        input[i].second.second=i;
    }
    sort(input.begin(),input.end());
    for (int i = 0; i < n; ++i) {
        ll st=input[i].first,en=input[i].second.first;
        ll ind=input[i].second.second;
        auto it=se.lower_bound({st,0});
        if(it==se.begin()){
            res++;
            vec[ind]=res;
            se.insert({en,res});
        }else{
            it--;
            ll cur=it->second;
            vec[ind]=cur;
            se.erase(it);
            se.insert({en,cur});
        }
    }
    cout<<res<<'\n';
    for (int i = 0; i < n; ++i) {
        cout<<vec[i]<<" ";
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