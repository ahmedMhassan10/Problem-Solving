#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
    ll n;cin>>n;
    set<int,greater<int>>vec;
    ll sum=0;
    for (int i = 0; i < n; ++i) {
        vec.insert(i+1);
        sum+=i+1;
    }
    if(sum%2){
       cout<<"NO\n";
        return;
    }
    sum/=2;
    ll fSum=0;
    vector<int>f,s;
    while (vec.size()){
        auto item=*vec.begin();
        if(fSum==sum)break;
        if(fSum+item>sum){
            f.push_back(sum-fSum);
            vec.erase(sum-fSum);
            break;
        }else{
            fSum+=item;
            vec.erase(item);
            f.push_back(item);
        }
    }
    while (vec.size()){
        s.push_back(*vec.begin());
        vec.erase(vec.begin());
    }
    cout<<"YES\n";
    cout<<f.size()<<'\n';
    for (int item:f) {
        cout<<item<<" ";
    }
    cout<<'\n';
    cout<<s.size()<<'\n';
    for (int item:s) {
        cout<<item<<" ";
    }
    cout<<'\n';
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