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
const ll OO =1e18, mod = 1e9+7,mod2=1e9+9,  N=1e6+5,M=25,MOD= 998244353, minOO=LLONG_MIN;
const double EPS=1e-12;
const double PI=acos(-1);
const ll maximum=1e5+3;
const int NOT_VISITED = -1;

///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة

struct FlowEdge {
    int v, u;// from ,to
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj,path;
    int n, m = 0,pathIdx=0,save=0;
    int s, t;
    vector<int> level, ptr,vis,curPath;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
        vis.resize(n);

    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
    void mark(){
        for(int i=1;i<n;i++){
            if(level[i]>=0)
                vis[i]=1;
        }
    }
    vector<pair<int,int>> getCuts(){
        mark();
        vector<pair<int,int>>res;
        for (int i = 1;i < n; ++i) {
            if(vis[i]==0)continue;
            for (auto item:adj[i]) {
                if(edges[item].u==i)
                    continue;
                auto next=edges[item].u;
                if(vis[next]==0){
                    res.push_back({i,next});
                }
            }
        }
        return res;
    }
    int handlePath(int node,int par,int val){
        if(node==s){
            save=0;
        }
        if(node==t){
            path.push_back(vector<int>());
            path[pathIdx].push_back(s);
            for (int i = 0; i < curPath.size(); ++i) {
                path[pathIdx].push_back(curPath[i]);
            }
            pathIdx++;
            save=1;
            return val;
        }
        for (auto item:adj[node]) {
            if(item%2)continue;
            auto from =edges[item].v,to=edges[item].u;
            if(to==par)continue;
            if(edges[item].flow){
                curPath.push_back(to);
                ll val2= handlePath(to,from,min(val,edges[item].flow));
                curPath.pop_back();
                if(save){
                    edges[item].flow-=val2;
                    if(node==s)
                        save=0;
                    else
                        return val2;
                }
            }
        }
        return 0;
    }
};

void func(int index) {
    ll n,m;cin>>n>>m;
    ll start=1,end=n;
    Dinic dinic=Dinic(n+1,start,end);

    for (int i = 0; i < m; ++i) {
        ll u,v;cin>>u>>v;
        dinic.add_edge(u,v,1);
    }
    cout<<dinic.flow()<<endl;
    dinic.handlePath(start,0,OO);
    for (int i = 0; i < dinic.path.size(); ++i) {
        cout<<dinic.path[i].size()<<endl;
        for (int j = 0; j < dinic.path[i].size(); ++j) {
            cout<<dinic.path[i][j]<<" ";
        }
        cout<<endl;
    }
}
signed main() {
    //`freopen("zanzibar.in","rt",stdin);
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