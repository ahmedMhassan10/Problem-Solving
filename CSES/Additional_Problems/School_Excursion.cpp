#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")

#define clr(v, d)			memset(v, d, sizeof(v))
#define ll long long
#define int long long
typedef tree< pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define setP(item) cout<<fixed<<setprecision(item);
int ceilSqrt(int a){
    return ::ceil(sqrtl(a));
}
int  divC(int a,int b){
    return a/b+(a%b!=0);
}
int gcd(int a, int b) { return ((b == 0) ? a : gcd(b, a % b)); }
int lcm(int a,int b){return (a*b)/gcd(a,b);}
const ll OO =1e18, mod = 1e9+7,mod2=1e9+9,  N=1e5+10,M=25,MOD= 998244353, minOO=LLONG_MIN;
const double EPS=1e-10;
const double PI=acos(-1);
const ll maximum=5000+5;
const int NOT_VISITED = -1;

///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة

vector<int> par(N), sz(N);
bool iscyclic = false;
void init(int n)
{
    for ( int i = 1 ; i <= n ;i++)
        par[i] = i , sz[i] = 1;
}
// O(n) ---> O(n ^ 2)
int findparent( int u)
{
    if(par[u] == u)
        return  u;
    return par[u] = findparent(par[u]);
}

void connect( int u , int v)
{
    u = findparent(u);
    v = findparent(v);
    if ( u == v)
    {
        iscyclic =true;
        return;
    }
    if(sz[v] < sz[u])
        par[v] = u ,sz[u] += sz[v];
    else
        par[u] = v,sz[v] += sz[u];
}
bool isconnected( int u , int v)
{
    return (findparent(u) == findparent(v));
}

void func(int index) {
    ll n,m;cin>>n>>m;
    init(n);
    for (int i = 0; i < m; ++i) {
        ll u,v;
        cin>>u>>v;
        connect(u,v);
    }
    set<int>se;
    for (int i = 1; i <= n ; ++i) {
        se.insert(findparent(i));
    }
    vector<int>w;
    for (auto item:se) {
        w.push_back(sz[item]);
    }
    bitset<N>bs;
    bs[0]=1;
    for (auto item:w) {
        bs=bs|(bs<<item);
    }
    for (int i = 1; i <= n ; ++i) {
        cout<<bs[i];
    }
}
signed main() {
//    freopen("lcm.in","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
//    cin>>t;
    ll index=1;
    while (t--){
        func(index++);
    }
    return 0;
}