#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v) ((v).begin()), ((v).end())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < siz(v); ++i)
#define fo(i, n) for (int i = 0; i < (int)(n); ++i)
#define fp(i, j, n) for (long long i = (j); i <= (long long)(n); ++i)
#define fn(i, j, n) for (int i = (j); i >= (int)(n); --i)
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
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO = 1e18, mod = 1e9+7,mod2=1e9+9, N =1e6+5,M=30,MOD=998244353;
///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة

vector<ll> prime(N+2,1);
vll primes;
ll numDiv(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = 1; // start from ans = 1
    while (PF * PF <= N) {
        ll power = 0; // count the power
        while (N % PF == 0) { N /= PF; power++; }
        ans *= (power + 1); // according to the formula
        PF = primes[++PF_idx];
    }
    if (N != 1) ans *= 2; // (last factor has pow = 1, we add 1 to it)
    return ans;
}
void solve(int inde) {
    ll num;cin>>num;
    cout<<numDiv(num)<<'\n';
}

int main() {
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
    prime[0]=0;
    prime[1]=0;
    for( ll i=2;i*i<=N;i++)
    {
        if(prime[i]==1){
            for(ll j=i*i;j<=N;j+=i){
                prime[j]= 0;
            }
        }
    }
    fp(i,1,N){
        if(prime[i]){
            primes.push_back(i);
        }
    }
    cin>>t;
    ll index=1;
    while (t--){
        solve(index++);
    }
    return 0;
}
