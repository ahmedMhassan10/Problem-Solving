#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define clr(v, d)			memset(v, d, sizeof(v))
#define ll long long
#define int long long
typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
const ll OO =1e18, mod = 1e9+7,mod2=1e9+9, N =1e5+5,M=30,MOD= 998244353, minOO=LLONG_MIN;

///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة

/// a33333333333333333333333333333333333333333333333333333333333333333333333333333333333333
vector<int>a(N);

vector< vector<int> > adjList, comps;
vector<int> inStack, lowLink, dfn, comp;
stack<int> stk;
int ndfn;
vector<int>totalCost(N);
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
        ll temp=0;
        comps.push_back(vector<int> ());
        int x = -1;
        while (x != node) {
            x = stk.top(), stk.pop(), inStack[x] = 0;
            comps.back().push_back(x);
            temp+=a[x];
            comp[x] = (comps.size()) - 1;
        }
        totalCost[(comps.size()) - 1]=temp;
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
vector<vector<int>>adjList2(N);
vector<int>dp(N,-1);
ll solve(int node){
    if(dp[node]!=-1)return dp[node];
    dp[node]=totalCost[node];
    ll r=0;
    for (auto item:adjList2[node]) {
        r=max(r, solve(item));
    }
    return dp[node]=dp[node]+r;
}
void func(int index){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    vector<pair<int,int>>edges;
    adjList.clear();
    adjList = vector<vector<int> > (n);
    for(int i=0;i< m;i++) {
        int f, t;
        cin >> f >> t;
        f--, t--;
        edges.push_back({f,t});
        adjList[f].push_back(t);
    }
    scc();
    ll n2=comps.size();
    vector<int>deg(n2);
    for (int i = 0; i < m; ++i) {
        ll st=comp[edges[i].first],en=comp[edges[i].second];
        if(st==en)continue;
        adjList2[st].push_back(en);
        deg[en]++;
    }
    bool tr=0;
    ll totalRes=0;
    for (int i = 0; i < n2; ++i) {
        if(deg[i]==0){
            totalRes=max(totalRes, solve(i));
        }
    }
    cout<<totalRes<<'\n';
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