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
const ll OO =1e18, mod = 1e9+7,mod2=1e9+9,  N=3e5+5,M=25,MOD= 998244353, minOO=LLONG_MIN;
const double EPS=1e-10;
const double PI=acos(-1);
const ll maximum=5000+10;
const int NOT_VISITED = -1;

///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة
ll dp[maximum][maximum];
ll mid[maximum][maximum];
ll a[maximum];

int solve(int i,int j)
{
    if(i >= j)
    {
        return 0;
    }
    if(dp[i][j] != -1)
        return dp[i][j];

    ll res = OO;

    int m1 = mid[i][j-1];
    int m2 = mid[i+1][j];

    for(int k=m1;k<=min(j-1,m2);k++)
    {
        int tmp = solve(i,k) + solve(k+1,j);
        if(tmp < res)
        {
            res = tmp;
            mid[i][j] = k;
        }
    }
    res += a[j] - a[i-1]; // cost function
    return dp[i][j]=res;
}
void func(int index) {
    ll n;cin>>n;
    clr(dp,-1);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    for (int i = 0; i < n ; ++i) {
        for (int j = i; j <= n ; ++j) {
            mid[j][i]=j;
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            solve(i,j);
        }
    }
    cout<<solve(0,n-1)<<endl;
}

signed main() {
//    freopen("lcm.in","rt",stdin);
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