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
int ceilSqrt(int a){
    return ::ceil(sqrtl(a));
}
int  divC(int a,int b){
    return a/b+(a%b!=0);
}
int gcd(int a, int b) { return ((b == 0) ? a : gcd(b, a % b)); }
int lcm(int a,int b){return (a*b)/gcd(a,b);}
const ll OO =1e18+10, mod = 1e9+7,mod2=1e9+9,  N=1e5+5,M=25,MOD= 998244353, minOO=LLONG_MIN;
const double EPS=1e-10;
const double PI=acos(-1);
const ll maximum=2500+6;
const int NOT_VISITED = -1;

vector<vector<int>>adj(N);
vector<int>lvl(N);
vector<bool>vis(N);
ll cycle=OO;
vector<bool>inStack(N);
void dfs(int node,int par){
    lvl[node]=lvl[par]+1;
    vis[node]=1;
    inStack[node]=1;
    for (auto item:adj[node]) {
        if(item==par)continue;
        if(inStack[item]){
            cycle=min(cycle, abs(lvl[item]-lvl[node])+1);
            continue;
        }else if(vis[item])continue;
        dfs(item,node);
    }
    inStack[node]=0;
}
void bfs(int st){
    queue<pair<int,int>>q;
    lvl[0]=-1;
    q.push({st,0});
    while (q.size()){
        ll node=q.front().first;
        ll par=q.front().second;
        q.pop();
        if(vis[node])continue;
        lvl[node]=lvl[par]+1;
        vis[node]=1;
        for (auto item:adj[node]) {
            if(par==item)continue;
            if(vis[item]){
                cycle=min(cycle, (lvl[item]+lvl[node])+1);
            }else q.push({item,node});
        }
    }
}
void func(int index){
   ll n;cin>>n;
   ll m;cin>>m;
    for (int i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n ; ++i) {
        vis=vector<bool>(maximum);
        inStack=vector<bool>(maximum);
        lvl=vector<int>(maximum);
//        dfs(i,0);
        bfs(i);
    }
    if(cycle==OO){
        cout<<"-1\n";
    }else cout<<cycle<<endl;
}
signed main() {
//    freopen("ysys.in","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
//    cin>>t;
    ll index=1;
    while (t--){
        auto start=chrono::system_clock::now();
        func(index++);
        auto end=chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
//        cout<<elapsed_seconds.count()<<endl;
    }
    return 0;
}