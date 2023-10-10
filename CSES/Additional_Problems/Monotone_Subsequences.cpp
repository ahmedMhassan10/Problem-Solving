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
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define setP(item) cout<<fixed<<setprecision(item);
int ceilSqrt(int a){
    return ::ceil(sqrtl(a));
}
int  divC(int a,int b){
    return a/b+(a%b!=0);
}
int gcd(int a, int b) { return ((b == 0) ? a : gcd(b, a % b)); }
int lcm(int a,int b){return (a*b)/gcd(a,b);}
const ll OO =1e18, mod = 1e9+7,mod2=1e9+9,  N=1e6+10,M=25,MOD= 998244353, minOO=LLONG_MIN;
const double EPS=1e-10;
const double PI=acos(-1);
const ll maximum=1000+10;
const int NOT_VISITED = -1;

///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة

void func(int index) {
    ll n,k;cin>>n>>k;
    if(k*k<n){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    ll curK=0;
    vector<int>temp;
    vector<int>res;
    for (int i = 1; i <= n ; ++i) {
        if(curK==k){
            for (int j = temp.size()-1; j >=0 ; j--) {
                res.push_back(temp[j]);
            }
            curK=1;
            temp.clear();
            temp.push_back(i);
        }else{
            temp.push_back(i);
            curK++;
        }
    }
    for (int i = temp.size()-1; i >=0 ; i--) {
        res.push_back(temp[i]);
    }
    for (int i = 0; i < res.size(); ++i) {
        cout<<res[i]<<' ';
    }
    cout<<endl;
}
signed main() {
//    freopen("lcm.in","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    cin>>t;
    ll index=1;
    while (t--){
        func(index++);
    }
    return 0;
}