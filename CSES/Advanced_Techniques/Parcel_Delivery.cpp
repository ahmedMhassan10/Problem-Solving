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
const ll OO =1e18, mod = 1e9+7,mod2=1e9+9,  N=2e6+5,M=25,MOD= 998244353, minOO=LLONG_MIN;
const double EPS=1e-10;
const double PI=acos(-1);
const ll maximum=1e6;
const int NOT_VISITED = -1;

///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة
struct Edge
{
    int from, to, capacity, cost;
};
struct rank2{
    int val, idx;
};
vector<vector<rank2>>adj, cost, capacity;


void shortest_paths(int n, int v0, vector<int>& d, vector<pair<int,int>>& p) {
    d.assign(n, OO);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, {-1,-1});

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v=0 ;v< adj[u].size();v++) {
            auto ch=adj[u][v].val;
            if (capacity[u][v].val > 0 && d[ch] > d[u] + cost[u][v].val) {
                d[ch] = d[u] + cost[u][v].val;
                p[ch] = {v,adj[u][v].idx};
                if (!inq[ch]) {
                    inq[ch] = true;
                    q.push(ch);
                }
            }
        }
    }
}

int min_cost_flow(int n, vector<Edge> edges, int K, int s, int t) {
    adj.assign(n, vector<rank2>());
    cost.assign(n, vector<rank2>());
    capacity.assign(n, vector<rank2>());
    ll idx=0;
    for (Edge e : edges) {
        adj[e.from].push_back({e.to,idx});
        cost[e.from].push_back( {e.cost,idx});
        capacity[e.from].push_back({e.capacity,idx});
        idx++;
    }
    int flow = 0;
    int cost = 0;
    vector<int> d;
    vector<pair<int,int>>p;
    while (flow < K) {
        shortest_paths(n, s, d, p);
        if (d[t] == OO)
            break;
        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s) {

            auto item=edges[p[cur].second];
            auto item1=p[cur];
            auto parent=edges[p[cur].second].from;
            auto temp=capacity[parent][p[cur].first];
            f = min(f, capacity[parent][p[cur].first].val);
            cur = parent;
        }
        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            auto parent=edges[p[cur].second].from;
            capacity[parent][p[cur].first].val -= f;
//            capacity[cur][p[cur].first+1].val += f;

            edges[p[cur].second].capacity -= f;
            edges[p[cur].second+1].capacity += f;

            cur = parent;
        }
    }
    if (flow < K)
        return -1;
    else
        return cost;
}
void func(int index) {
    ll n,m,k;cin>>n>>m>>k;
    vector<Edge>edges;
    for (int i = 0; i < m; ++i) {
        ll u,v,f,c;cin>>u>>v>>f>>c;
        edges.push_back({u,v,f,c});
        edges.push_back({v,u,0,-c});
    }
    cout<<min_cost_flow(n*2+10,edges,k,1,n);
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