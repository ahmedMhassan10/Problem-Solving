#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define all(v) ((v).begin()), ((v).end())
#define allRev(v) ((v).rbegin()), ((v).rend())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define fo(i, n) for (long long i = 0; i < (long long)(n); ++i)
#define fp(i, j, n) for (long long i = (j); i <= (long long)(n); ++i)
#define fn(i, j, n) for (long long i = (j); i >= (long long)(n); --i)
#define fvec(i, vec) for (auto i : vec)
#define pb push_back
#define MP make_pair
#define mine(x, y, z) min(x, min(y, z))
#define maxe(x, y, z) max(x, max(y, z))
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef vector<pll> vp;
typedef vector< long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define setp(item) cout<<fixed<<setprecision(item);
#define PI 3.14159265358979323846264338327950
ll ceilSqrt(ll a){
    return ::ceil(sqrtl(a));
}
ll  divC(ll a,ll b){
    return a/b+(a%b!=0);
}
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO =1e15, mod = 1e9+7,mod2=1e9+9, N =2e6+5,M=30,MOD= 998244353, minOO=-1e18;
///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة
/// :-)
/// a33333333333333333333333333333333333333333333333333333333333333333333333333333333333333
ll fact[N], inv[N];

ll add ( ll a , ll b, ll mod)
{
    return (a + b) % mod;
}
ll sub ( ll a , ll b, ll mod)
{
    return (a - b +mod) % mod;
}
ll mul ( ll a , ll b, ll mod)
{
    return (1LL * a * b) % mod;
}
ll fop( ll b , ll p, ll mod)
{
    if(!p)
        return 1;
    ll temp = fop(b,p/2,mod)%mod;
    temp = mul(temp,temp,mod);
    if(p&1)
        temp = mul(temp,b,mod);
    return temp%mod;
}
ll nCr( ll n , ll r, ll mod)
{
    return mul(fact[n],mul(inv[n-r],inv[r],mod),mod);
}
ll nPr( ll n , ll r, ll mod)
{
    return mul(nCr(n,r,mod),fact[r],mod);
}

void testCase(ll mod,ll n=N-1) {
    /* fact[0] = inv[0] = 1;
     for ( ll i = 1 ; i <= n ; i++)
     {
         fact[i] = mul(i,fact[i-1],mod);
         inv[i] = fop(fact[i],mod-2,mod);
     }*/
    fact[0] = fact[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    }
    for (int i = 2; i <= n; i++)
        inv[i] = inv[i] * inv[i - 1] % mod;
}
void func(int ind) {
    testCase(mod);
    ll n;cin>>n;
    if(n%2){
        cout<<"0\n";
        return;
    }
    n/=2;
    cout<<sub(nCr(2*n,n,mod), nCr(2*n,n+1,mod),mod);
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
        func(index);
        index++;
    }
    return 0;
}