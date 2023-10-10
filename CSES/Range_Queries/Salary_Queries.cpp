#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v) ((v).begin()), ((v).end())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < siz(v); ++i)
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
typedef tree< pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define setp(item) cout<<fixed<<setprecision(item);
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO =LLONG_MAX, mod = 1e9+7,mod2=1e9+9, N =1e6+5,M=30,MOD=998244353, minOO=LLONG_MIN;
///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة

void solve(int inde) {
    ll num,q;cin>>num>>q;
    vll vec(num+1);
    ordered_set se;
    fp(i,1,num){
        cin>>vec[i];
        se.insert({vec[i],i});
    }
    while (q--){
        char ch;cin>>ch;
        if(ch=='?'){
            ll u,v;cin>>u>>v;
            auto s=se.lower_bound({u,0}),e=se.upper_bound({v,OO});
            ll st=0,en=0;
            if(e==se.end()){
                en=num;
            }else{
                en=se.order_of_key(*e);
            }
            if(s==se.end()){
                st=0;
            }else{
                st=se.order_of_key(*s);
            }
            cout<<en-st<<"\n";
        }else{
            ll u,v;cin>>u>>v;
            se.erase(se.find({vec[u],u}));
            vec[u]=v;
            se.insert({vec[u],u});
        }
    }

}

int main() {
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
//    cin>>t;
    ll index=1;
    while (t--){
        solve(index++);
    }
    return 0;
}
