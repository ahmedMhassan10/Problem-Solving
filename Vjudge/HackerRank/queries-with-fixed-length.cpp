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
const ll OO = 1e9, mod = 1e9 + 7,mod2=1e9+9, N = 5e5+10,M=23;
ll  sp[N][M],a[N],n,lg[N];
void buildSparse()
{
	lg[1]=0;
	for(int i=2;i<=n;i++){
		lg[i]=lg[i/2]+1;
	}
	for(int i=0;i<n;i++){
		sp[i][0]=a[i];
	}
	for(int bit=1;bit<M;bit++){
		for(int i=0;i+ (1<<bit) <=n;i++){
			sp[i][bit]=max(sp[i][bit-1],sp[i+(1<<(bit-1))][bit-1]); //we can use it with gcd ,max;
		}
	}
}
ll qmax(int l,int r){
	ll  dist=lg[r-l+1];
	return max(sp[l][dist],sp[r-(1<<dist)+1][dist]);
}
int main() {
        // freopen("survive.in "," r ",stdin);
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        cin>>n;        int q;cin>>q;

        fo(i,n){
            cin>>a[i];
        }
        buildSparse();

        while(q--){
            int u;cin>>u;
            ll ans=OO;
            fp(i,0,n-u){
                ans=min(ans,qmax(i,i+u-1));
            }
            cout<<ans<<"\n";
        }
        return 0;
}
