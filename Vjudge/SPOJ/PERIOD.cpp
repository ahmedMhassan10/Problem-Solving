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
const ll OO = 1e9, mod = 1e9 + 7,mod2=1e9+9, N = 1e6+1;
void compute_prefix(string &s,vll &fail){
    fp(i,1,siz(s)-1){
        int j=fail[i-1];
        while(j>0&& s[i]!=s[j])
            j=fail[j-1];
        if(s[i]==s[j])
            fail[i]=j+1;
        else fail[i]=0;
    }
}
void kmp(string &s,string &pat){
    ll k=0;
    ll n=siz(s),m=siz(pat);
    vll fail(n);

    compute_prefix(pat,fail);

    fo(i,n){
        while(k>0 &&pat[k]!=s[i]){
            k=fail[k-1];
        }
        if(pat[k]==s[i])
            k++;
        if(k==m){
            cout<<i-k+1<<'\n';
            k=fail[k-1];
        }
    }
}
int main() {
       // freopen("survive.in "," r ",stdin);
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int t;cin>>t;
        fp(nn,1,t){
            cout<<"Test case #"<<nn<<'\n';
            ll num;cin>>num;
            string str;cin>>str;
            vll fail(siz(str));
            compute_prefix(str,fail);
            fp(i,2,num){
                if(i%(i-fail[i-1])==0&&i/(i-fail[i-1])>1){
                    cout<<i<<" "<<i/(i-fail[i-1])<<'\n';
                }
            }
            if(nn<t)cout<<'\n';
        }
        return 0;
}
