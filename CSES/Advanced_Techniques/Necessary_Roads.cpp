#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
//
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")

#define clr(v, d)			memset(v, d, sizeof(v))
#define ll long long
#define int long long
typedef tree< pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define setp(item) cout<<fixed<<setprecision(item);
#define PI 3.14159265358979323846264338327950
int ceilSqrt(int a){
    return ::ceil(sqrtl(a));
}
int  divC(int a,int b){
    return a/b+(a%b!=0);
}
int gcd(int a, int b) { return ((b == 0) ? a : gcd(b, a % b)); }
int lcm(int a,int b){return (a*b)/gcd(a,b);}
const ll OO =1e18+10, mod = 1e9+7,mod2=1e9+9,  N=1e5+5,M=25,MOD= 998244353, minOO=LLONG_MIN;
const double EPS=1e-6;
const ll maximum=5e4+1;
vector<vector<int>> adjMat(N);
int low[N], dfn[N], num, n,m;
vector<pair<int, int> > bridges;
void art_bridges(int i, int p) {
    low[i] = dfn[i] = num++;
    for (auto j : adjMat[i])
        if (j != p) {
            if (dfn[j] == 0) {
                art_bridges(j, i);
                low[i] = min(low[i], low[j]);
                if (low[j] == dfn[j])  /////(low[j]>dfn[i])
                    bridges.push_back(make_pair(min(i, j), max(i, j)));
            } else
                low[i] = min(low[i], dfn[j]);
        }
}
void run_art_bridges() {
    for(int i=0;i< n;i++)
        low[i] = -1, dfn[i] = 0;
    bridges.clear();

    for(int i=0;i< n;i++)
        if (!dfn[i])
            art_bridges(i, -1);
    sort(bridges.begin(),bridges.end());
}

void func(int index){
    num=1;
    cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        ll u,v;cin>>u>>v;
        u--,v--;
        adjMat[u].push_back(v);
        adjMat[v].push_back(u);
    }
    run_art_bridges();
    cout<<bridges.size()<<endl;
    for (auto item:bridges){
        cout<<item.first+1<<' '<<item.second+1<<endl;
    }
}
signed main() {
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
//    cin>>t;
    ll index=1;
    while (t--){
        func(index++);
    }
    return 0;
}