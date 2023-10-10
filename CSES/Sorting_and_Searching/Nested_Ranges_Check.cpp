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
const ll OO = 1e18, mod = 1e9+7,mod2=1e9+9, N =3e5+5,M=30,MOD=998244353;


///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة
struct query {
    ll l, r, idx;
};

bool cmp(query &a, query &b) {
    if (a.l  != b.l )
        return a.l  < b.l ;
    return a.r > b.r;
}

void solve(int inde) {
    ll num;cin>>num;
    vector<query>vec(num);
    fo(i,num){
        cin>>vec[i].l>>vec[i].r;
        vec[i].idx=i;
    }
    vll containIt(num),inIt(num);
    sort(all(vec),cmp);
    ordered_set se;
    fo(i,num){
        se.insert({vec[i].r,-1*i});
        containIt[vec[i].idx]=se.size()-se.order_of_key({vec[i].r,-1*i})-1;
    }
    se.clear();
    fn(i,num-1,0){
        se.insert({vec[i].r,-1*i});
        inIt[vec[i].idx]=se.order_of_key({vec[i].r,-1*i});
    }
    fvec(item,inIt){
        if(item>0){
            cout<<"1 ";
            continue;
        }
        cout<<item<<" ";
    }
    cout<<'\n';
    fvec(item,containIt){
        if(item>0){
            cout<<"1 ";
            continue;
        }
        cout<<item<<" ";
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
