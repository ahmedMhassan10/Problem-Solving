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
const ll OO =1e18+10, mod = 1e9+7,mod2=1e9+9,  N=1e6+5,M=25,MOD= 998244353, minOO=LLONG_MIN;
const double EPS=1e-10;
const double PI=acos(-1);
const ll maximum=32768;
const int NOT_VISITED = -1;

///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة


void func(int index) {
    ll n;cin>>n;
    ll log2N=log2(N)+1;
    ll maxi=1<<log2N;
    vector<int>vec(maxi);
    vector<int>freq(maxi);

    for (int i = 0; i < n; ++i) {
        cin>>vec[i];
        freq[vec[i]]++;
    }

    vector<int>F(maxi,0);
    vector<int>F2(maxi,0);
    for (int i = 0; i < maxi; ++i) {
        F[i]=freq[i];
        F2[i]=freq[i];
    }
    for(int i = 0;i < log2N; ++i){
        for(int mask = 0; mask < (maxi); ++mask){
            if(mask & (1<<i)) {
                F[mask] +=  F[mask ^ (1 << i)];
            }
        }
    }
    for(int i = 0;i < log2N; ++i){
        for(int mask = maxi-1; mask >= 0; mask--){

            if(!(mask & (1<<i))) {
                F2[mask]+=  F2[mask ^ (1 << i)];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout<<F[vec[i]]<<" "<<F2[vec[i]]<<" "<<n-F[vec[i]^(maxi-1)]<<endl;  // x|y==x
        // x&y==x
        // x&y!=0
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