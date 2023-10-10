#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v) ((v).begin()), ((v).end())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < sz(v); ++i)
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
typedef vector<pll> vp;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define setp(item) cout<<fixed<<setprecision(item);
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO = 1e18, mod = 1e9+7,mod2=1e9+9, N =1000000+10,M=30,MOD=998244353;
ll n,m;
vll res;
vector<ll> primes(N+1000,1);

void solve(ll index)
{


    fo(i,siz(res))
    {
        if(2*res[i]>n){
            break;
        }else if(2*res[i]==n){
            cout<<n<<" = "<<res[i]<<" + "<<res[i]<<'\n';
            return ;
        }else {
            if (primes[n - res[i]]) {
                cout<<n<<" = "<<res[i]<<" + "<<n-res[i]<<'\n';
                return ;
            }
        }
    }
    cout<<"Goldbach's conjecture is wrong.\n";
    //cout<<'\n';
}

int main() {
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t=1;
    //cin>>t;
    ll index=1;
    primes[0]=0,primes[1]=0;
    for( ll i=2;i<=N;i++)
    {
        if(primes[i]==1){
            for(ll j=i*i;j<=N;j+=i){
                primes[j]= 0;
            }
        }
    }
    fp(i,2,N){
        if(primes[i]==1)
            res.pb(i);
    }
    while(cin>>n){
        if(n==0)break;
        solve(index++);
    }
    return 0;
}

