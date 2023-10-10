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
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef unsigned long long ull;
typedef long long ll;
const ll OO = 1e9, mod = 1e9+7 , N = 2e5+5;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
int main() {
   // freopen("survive.in "," r ",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    setprecision(10);
    int t=1;
   //cin>>t;
    while(t--){
            int n,k;cin>>n>>k;
            bool prime[n+5];
            memset(prime , true, sizeof prime );
            prime[0] = prime[1] = false;
            for (int i = 2; i * i <= n; i++)
            if ( prime[i])
                for (int j = i * i; j <= n; j += i)
                    prime[j] = false;
            vector<int>vec;
            map<int,int>ma;
            fp(i,1,n)
                if(prime[i]){vec.pb(i);ma[i-1]=1;}
            fo(i,vec.size()-1){
                if(ma[vec[i]+vec[i+1]]==1)k--;
            }
            if(k>0)cout<<"NO\n";
            else cout<<"YES\n";
    }
}
