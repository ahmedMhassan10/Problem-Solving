#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define clr(v, d)			memset(v, d, sizeof(v))
#define ll long long

#define int long long
typedef tree< pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
const ll OO =1e18, mod = 1e9+7,mod2=1e9+9, N =5000+5,M=30,MOD= 998244353, minOO=LLONG_MIN;

///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة

/// a33333333333333333333333333333333333333333333333333333333333333333333333333333333333333
vector<vector<int>> mul(vector<vector<int>> &a, vector<vector<int>> &b) {
    int n = a.size(), m = b[0].size(), f = b.size();
    vector<vector<int>> c(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < f; k++)
            {
                c[i][j] += ((a[i][k]* b[k][j])%mod);
                c[i][j]%=mod;
            }
    return c;
}
vector<vector<int>> idendity(int n) {
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) arr[i][i] = 1;
    return arr;
}
vector<vector<int>> expo(vector<vector<int>> a, int x) {
    int n = a.size();
    if (x <= 0) return idendity(n);
    if (x == 1) return a;
    vector<vector<int>> newMat = expo(a, x / 2);
    vector<vector<int>> ans = mul(newMat, newMat);
    if (x % 2 == 1) ans = mul(ans, a);
    return ans;
}
void func(int index){
    ll n,m,k;cin>>n>>m>>k;
    vector<vector<int>>a(n,vector<int>(n));
    for (int i = 0; i < m; ++i) {
        ll u,v;cin>>u>>v;
        u--,v--;
        a[u][v]++;
    }
    a= expo(a,k);
    cout<<a[0][n-1];
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