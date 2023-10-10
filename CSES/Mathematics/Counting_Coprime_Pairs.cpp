#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define all(v) ((v).begin()), ((v).end())
#define invAll(v) ((v).rbegin()), ((v).rend())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
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
const ll OO =1e17, mod = 1e9+7,mod2=1e9+9, N =1e6+5,M=30,MOD=998244353, minOO=-1e17;
///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة
vector<ll> primes(N+5,1);
void seive(){
    fp(i,2,N){
        primes[i]=i;
    }
    primes[0]=0;
    primes[1]=0;
    for( ll i=2;i<=N;i++)
    {
        if(primes[i]==i){
            for(ll j=2*i;j<=N;j+=i){
                primes[j]= min(primes[j],i);
            }
        }
    }

}
void func(int ind) {
    seive();
    ll n;cin>>n;
    vll vec(n);
    fo(i,n)cin>>vec[i];
    sort(all(vec));
    ll res=0;
    vll count(N,0);
    fo(i,n){
        ll nn=vec[i];
        vector<ll>se;
        while (nn>1){
            if(se.size()==0||se.back()!=primes[nn]){
                se.push_back(primes[nn]);
            }
            nn/=primes[nn];
        }
        ll sz=se.size();
        fo(kk,(1<<sz)){
            if(kk==0)continue;
            ll value=1;
            fo(j,sz){
                if((1<<j)&kk)value*=se[j];
            }
            if(__builtin_popcount(kk)%2==0){
                res-=count[value];
            }else{
                res+=count[value];
            }
            count[value]++;
        }
    }
    cout<<(n)*(n-1)/2-res;

}
int main() {
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
//    cin>>t;
    ll ind=1;
    while (t--){
        func(ind++);
    }
    return 0;
}