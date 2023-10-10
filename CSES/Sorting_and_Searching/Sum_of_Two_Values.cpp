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
typedef tree< pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define setp(item) cout<<fixed<<setprecision(item);
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO = 1e12, mod = 1e9+7,mod2=1e9+9, N =8e5+4,M=23;

int main() {
        //freopen("input.txt","rt",stdin);
        //freopen("output.txt","wt",stdout);
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        ll num,x;cin>>num>>x;
        vector<pll>vec(num);
        fo(i,num){
            cin>>vec[i].F;
            vec[i].S = i;
        }
        sort(all(vec));
        fo(i,num){
            ll st=i+1,en=num-1;
            if(vec[i].F>x)break;
            while(st<=en){
                ll mid=(st+en)/2;
                if(vec[mid].F == x-vec[i].first ){
                    cout<<min(vec[mid].S,vec[i].S)+1<<" "<<max(vec[mid].S,vec[i].S)+1;
                    return 0;
                }else if(vec[mid].F> x-vec[i].first){
                    en=mid-1;
                }else{
                    st=mid+1;
                }
            }
        }
        cout<<"IMPOSSIBLE";
        return 0;
}
