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
const ll OO = 1e9, mod = 1e9 + 7,mod2=1e9+9, N = 100+10;
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
int main() {
       // freopen("survive.in "," r ",stdin);
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        string str;cin>>str;
        vll fail(siz(str),0);
        compute_prefix(str,fail);
       // fvec(item,fail)cout<<item<<'\n';
        map<int,bool>ma;
        ll re=fail[siz(str)-1];
        fp(i,1,siz(str)-2){
            ma[fail[i]]=true;
        }
        while(re>0&&!ma[re])
            re=fail[re-1];
        if(re){
                fo(i,re)
                    cout<<str[i];
        }else cout<<"Just a legend\n";
        return 0;
}
