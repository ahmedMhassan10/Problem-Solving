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
const ll OO = 1e9, mod = 1e9 + 7,mod2=1e9+9, N = 1e3+5;
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
vll prifx(N),prifx2(N);
void make_hash(string &x) {
    for (int i = 0; i < x.size(); ++i) {
        ll ind = x[i] - 'a' + 1;
        prifx[i] = mul(ind, pw[i],mod);
        prifx2[i] = mul(ind, pw2[i],mod2);
        if (i > 0) {
            prifx[i] = add(prifx[i], prifx[i - 1],mod);
            prifx2[i] = add(prifx2[i], prifx2[i - 1],mod2);
        }
    }
}
pair<ll,ll> get_value(ll st, ll en) {
    if(st==0)
        return {prifx[en],prifx2[en]};
    return {mul(minu(prifx[en],prifx[st-1],mod),inv[st],mod),mul(minu(prifx2[en],prifx2[st-1],mod2),inv2[st],mod2)};
}

int main() {
       // freopen("survive.in "," r ",stdin);
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        pre();
        while(true){
            string str="",str1;getline(cin,str1);
            if(str1=="")break;

            fo(i,siz(str1)){
                if(str1[i]==' ')continue;
                str+=str1[i];
            }

            make_hash(str);
            map<pair<ll,ll>,ll>ma;
            fp(len,1,siz(str)){
                ll ans=0;
                fp(i,0,siz(str)-len){
                    auto val=get_value(i,i+len-1);
                    ma[val]++;
                    ans=max( ma[val],ans);
                  //  cout<<val.F<<" "<<val.S<<" "<<ans<<" "<<len<<" "<<ma[val]<<'\n';
                }
                if(ans>1)cout<<ans<<'\n';
                else{ cout<<'\n';break;}
            }
        }
        return 0;
}
