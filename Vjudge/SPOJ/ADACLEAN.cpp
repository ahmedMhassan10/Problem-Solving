#include <bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()), ((v).end())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < sz(v); ++i)
#define fo(i, n) for (int i = 0; i < (int)(n); ++i)
#define fp(i, j, n) for (int i = (j); i <= (int)(n); ++i)
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
typedef vector<pair<ll,ll>> vp;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
#define setp(item) cout<<fixed<<setprecision(item);
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO = 1e9, mod = 1e9 + 7,mod2=1e9+9, N = 1e6+5;
vi  pw(N);
vi inv(N);
vi  pw2(N);
vi inv2(N);
ll add(ll a, ll b,ll mod) {
    return ((a % mod + b % mod) + mod) % mod;
}

ll mul(ll a, ll b,ll mod) {
    return ((a % mod * b % mod) + mod) % mod;
}

ll minu(ll a, ll b,ll mod) {
    return ((a % mod - b % mod) + mod) % mod;
}

ll fastp(ll a, ll b,ll mod) {
    if (b == 0)return ll(1);
    ll temp = fastp(a, b / 2,mod);
    ll total = mul(temp, temp,mod);
    if (b % 2 == 1) {
        total = mul(total, a,mod);
    }
    return total;
}

void pre() {
    pw[0] = 1;
    inv[0] = 1;
    pw2[0] = 1;
    inv2[0] = 1;
    ll mul_inv = fastp(29, mod - 2,mod);
    ll mul_inv2=fastp(31, mod2 - 2,mod2);
    for (int i = 1; i < N; ++i) {
        pw[i] = mul(pw[i - 1], 29,mod);
        inv[i] = mul(inv[i - 1], mul_inv,mod);
        pw2[i] = mul(pw2[i - 1], 31,mod2);
        inv2[i] = mul(inv2[i - 1], mul_inv2,mod2);
    }
}

void make_hash(string &x, vi &prifx , vi &pw ,vi &inv,ll mod) {
    for (int i = 0; i < x.size(); ++i) {
        ll ind = x[i] - 'a' + 1;
        prifx[i] = mul(ind, pw[i],mod);
        if (i > 0) {
            prifx[i] = add(prifx[i], prifx[i - 1],mod);
        }
    }
}
ll get_value(ll st, ll en, vi &prifx, vi &pw ,vi &inv,ll mod) {
    if(st==0)
        return prifx[en];
    return mul(minu(prifx[en],prifx[st-1],mod),inv[st],mod);
}
int main() {
       // freopen("survive.in "," r ",stdin);
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int t;cin>>t;
        pre();
        while(t--){
            int num,k;cin>>num>>k;
            set<pair<int,int>>s;
            string str;cin>>str;
            vi prefix(siz(str)+5);
            vi prefix2(siz(str)+5);
            make_hash(str,prefix,pw,inv,mod);
            make_hash(str,prefix2,pw2,inv2,mod2);
            fp(i,0,siz(str)-k){
                int valu=get_value(i,i+k-1,prefix,pw,inv,mod);
                int valu2=get_value(i,i+k-1,prefix2,pw2,inv2,mod2);
                s.insert({valu,valu2});
            }
            cout<<s.size()<<"\n";
        }
        return 0;
}
