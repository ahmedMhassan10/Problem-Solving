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
const ll maximum=2e6+6;
const int NOT_VISITED = -1;
vector<vector<int>>adj(N);
struct edge{
    ll u,v;
};
vector<int>lvl(N);
vector<bool>vis(N);
void bfs(int node){
    queue<pair<int,int>>q;
    q.push({node,0});
    while (q.size()){
        ll no=q.front().first,level=q.front().second;
        q.pop();
        if(vis[no])continue;
        vis[no]=1;
        lvl[no]=level;
        for (auto item:adj[no]) {
            if(vis[item])continue;
            q.push({item,level+1});
        }
    }
}
void func(int index){
    ll n,m;cin>>n>>m;
    vector<edge>edges(m);
    for (int i = 0; i < m; ++i) {
        ll u,v;cin>>u>>v;
        edges[i]={min(u,v),max(u,v)};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    for (int i = 0; i < m; ++i) {
        if(lvl[edges[i].u]<=lvl[edges[i].v]){
            cout<<edges[i].u<<' '<<edges[i].v<<endl;
        }else cout<<edges[i].v<<" "<<edges[i].u<<endl;
    }
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