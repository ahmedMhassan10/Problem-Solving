#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
//
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")

#define clr(v, d)			memset(v, d, sizeof(v))
#define ll long long
#define int long long
typedef tree< pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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
const ll OO =1e18+10, mod = 1e9+7,mod2=1e9+9,  N=1e5+5,M=25,MOD= 998244353, minOO=LLONG_MIN;
const double EPS=1e-10;
const ll maximum=2e6+6;
const int NOT_VISITED = -1;

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
vector<int>dp(70);

void func(int index){

    ll n;cin>>n;
    ll ans=0;
    for (int i = 51; i >= 0 ; i--) {
        ll r= fop(2,i);
        if(r&n){
            ans+=dp[i];
            n-=r;
            ans+=n;
        }
    }
    cout<<ans<<endl;
}
signed main() {
//    freopen("ysys.in","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
//    cin>>t;
    dp[0]=1;
    dp[1]=2;
    ll last=1;
    for ( int i = 2 ; i <= 51 ; ++i ) {
        last*=2;
        dp[i]=dp[i-1]*2+(last-1);
    }
    ll index=1;
    while (t--){
        auto start=chrono::system_clock::now();
        func(index++);
        auto end=chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
//        cout<<elapsed_seconds.count()<<endl;
    }
    return 0;
}