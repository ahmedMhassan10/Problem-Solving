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
ll fop( ll b , ll p)
{
    if(!p)
        return 1;
    ll temp = fop(b,p/2);
    temp =(temp*temp);
    if(p&1)
        temp = (temp*b);
    return temp;
}
void func(int index) {
    ll n;cin>>n;
    ll val=1;
    for (int i = 9; ; i*=10) {
        ll v=i*val;
        if(n<=v){
            break;
        } else{
            n-=v;
        }
        val++;
    }
    n--;
    ll v=n/val;
    ll v2=n%val;
    ///hintttttttt
    int ans = fop(10, val-1) + v;
    string s = to_string(ans);
    cout<<s[v2]<<endl;
}
signed main() {
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    cin>>t;
    int index=1;
    while (t--){
        func(index++);
    }
    return 0;
}