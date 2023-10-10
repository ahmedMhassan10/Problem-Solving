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
const ll OO =1e18+10, mod = 1e9+7,mod2=1e9+9,  N=2e5+5,M=25,MOD= 998244353, minOO=LLONG_MIN;
const double EPS=1e-6;
const ll maximum=5e4+1;


vector< vector<int> > adjList, comps;
vector<int> inStack, lowLink, dfn, comp;
stack<int> stk;
int ndfn;
vector<bitset<maximum>>dp(maximum);
void tarjan(int node) {
    lowLink[node] = dfn[node] = ndfn++, inStack[node] = 1;
    stk.push(node);

    for(int i=0;i< adjList[node].size();i++) {
        int ch = adjList[node][i];
        if (dfn[ch] == -1) {
            tarjan(ch);
            lowLink[node] = min(lowLink[node], lowLink[ch]);
        } else if (inStack[ch])
            lowLink[node] = min(lowLink[node], dfn[ch]);
    }

    if (lowLink[node] == dfn[node]) {
        comps.push_back(vector<int> ());
        int x = -1;
        while (x != node) {
            x = stk.top(), stk.pop(), inStack[x] = 0;
            comps.back().push_back(x);
            comp[x] = (comps.size()) - 1;
        }
    }
}


void scc() {
    int n = (adjList.size());
    inStack.clear();	inStack.resize(n);
    lowLink.clear();	lowLink.resize(n);
    dfn.clear();		dfn.resize(n, -1);
    ndfn = 0;

    comp.clear(), comp.resize(n);
    comps.clear();

    for(int i=0;i< n;i++)
        if (dfn[i] == -1)
            tarjan(i);
}
vector<int>vis(maximum,0);
vector<vector<int>>adj;
void dfs(int node){
    vis[node]=1;
    dp[node].set(node);
    for(auto item:adj[node]){
        if(vis[item]==0){
            dfs(item);
        }
        dp[node]=dp[node]|dp[item];
    }
}
void func(int index){
    ll n,m;cin>>n>>m;
    ll q;cin>>q;
    adjList.clear();
    adjList=vector<vector<int>>(n);
    for (int i = 0; i < m; ++i) {
        ll u,v;cin>>u>>v;
        u--,v--;
        adjList[u].push_back(v);
    }
    scc();
    adj.clear();
    adj=vector<vector<int>>(comps.size());
    for (int i = 0; i < n; ++i) {
        for (auto item:adjList[i]) {
            if(comp[i]==comp[item])continue;
            adj[comp[i]].push_back(comp[item]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if(vis[comp[i]])continue;
        dfs(comp[i]);
    }
    while (q--){
        ll u,v;cin>>u>>v;
        u--,v--;
        if(dp[comp[u]].test(comp[v])){
            cout<<"YES\n";
        }else cout<<"NO\n";
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