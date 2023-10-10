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
const int OO =1e18, mod = 1e9+7,mod2=1e9+9, N =2e5+5,M=30,MOD= 998244353, minOO=LLONG_MIN;
///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة
/// :-)
/// a33333333333333333333333333333333333333333333333333333333333333333333333333333333333333
ll sp[N][M] , a[N] , lg[N]  ,n;
void buildSparse(){/// one based
    lg[1] = 0 ;
    for(ll i =2;i <=n ; i++){
        lg[i] = lg[i/2]+1;
    }
    for(ll i = 0 ; i< n; i++){
        sp[i][0] = a[i] ;
    }
    for(ll i = 1;i<M ; i++){
        for(int j = 0 ; j + (1<<i)<= n ;j++){
            sp[j][i] = max(sp[j][i-1], sp[j+(1<<(i-1))][i-1]);
        }
    }
}
ll queryMX(ll l , ll r)
{
    if(l>r)
        return 0;
    ll j = lg[r-l+1];
    return max(sp[l][j],sp[r-(1<<j)+1][j]);
}
void func(int index) {
    cin>>n;
    ll st,en;cin>>st>>en;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        if(i)a[i]+=a[i-1];
    }
    buildSparse();
    ll res=-OO;
    for (int i = 0; i < n; ++i) {
        if(i+st-1==n)break;
        ll v=0;
        if(i)v=a[i-1];
        res=max(res, queryMX(i+st-1,min(n-1,i+en-1))-v);
    }
    cout<<res;
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