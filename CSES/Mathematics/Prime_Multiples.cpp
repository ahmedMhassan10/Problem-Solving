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
const ll OO =1e17, mod = 1e9+7,mod2=1e9+9, N =1e7+5,M=30,MOD=998244353, minOO=-1e17;
///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة
ll fop(ll base, ll exp)
{
        if (exp == 0)
        return 1;
        ll ans = fop(base, exp / 2);
        ans = (ans * ans) % mod;
        if (exp % 2 != 0)
        ans = (ans * (base % mod)) % mod;
        return ans;
}
void func(int ind) {
    ll n,k;cin>>n>>k;
    ll res=0;
    vll vec(k);
    fo(i,k)cin>>vec[i];
    fo(i,fop(2,k)){
        if(i==0)continue;
        ll val=n;
        ll odd=0;
        fo(j,k){
            if(fop(2,j) & i){
                odd++;
                val/=vec[j];
            }
        }
        if(odd%2==1){
            res+=val;
        }else{
            res-=val;
        }
    }
    cout<<res<<'\n';

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