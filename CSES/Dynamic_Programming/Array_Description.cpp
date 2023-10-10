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
const ll OO = 1e15, mod = 1e9+7,mod2=1e9+9, N =1e5+5,M=23;
ll num,m;vll vec(N);
vector<vector<ll>>dp(N,vll(101,-1));
ll solve(ll index,ll prev){
    if(index>=num){
        return 1;
    }
    if(dp[index][prev]!=-1)return dp[index][prev];
    ll s1=0;
    if(vec[index]!=0){
        if(index==0)s1+=solve(index+1,vec[index])%mod;
        else{
            if(abs(vec[index]-prev)<=1)s1+=solve(index+1,vec[index])%mod;
            else return 0;
        }
    }else{
        if(index==0){

            fp(i,1,m)s1+=solve(index+1,i)%mod;

        }else{
            if(prev>1)
                s1+=solve(index+1,prev-1)%mod;

            s1+=solve(index+1,prev)%mod;

            if(prev<m)s1+=solve(index+1,prev+1)%mod;
        }
    }
    return dp[index][prev]=s1%mod;
}
int main() {
        //freopen("input.txt","rt",stdin);
        //freopen("output.txt","wt",stdout);
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>num>>m;
        fo(i,num)cin>>vec[i];
        cout<<solve(0,0);
}
