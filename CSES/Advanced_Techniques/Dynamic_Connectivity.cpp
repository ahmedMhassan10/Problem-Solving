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
const ll OO =1e18, mod = 1e9+7,mod2=1e9+9,  N=2e5+5,M=25,MOD= 998244353, minOO=LLONG_MIN;
const double EPS=1e-10;
const double PI=acos(-1);
const ll maximum=1e5+3;
const int NOT_VISITED = -1;

///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة

struct DSU{
    vector<int> par, sz;
    stack<pair<int,int>>rB;// node ,parent
    ll comp=0;
    void init(int n)
    {
        par.resize(n+1);
        sz.resize(n+1);
        comp=n;
        while (rB.size())
            rB.pop();
        for ( int i = 0 ; i <= n ;i++)
            par[i] = i , sz[i] = 1;
    }
    int findparent( int u)
    {
        if(par[u] == u)
            return  u;
        return  findparent(par[u]);
    }
    void connect( int u , int v)
    {
        u = findparent(u);
        v = findparent(v);
        if ( u == v)
        {
            return;
        }
        comp--;
        if(sz[v] < sz[u])
        {
            rB.push({v,par[v]});
            par[v] = u ,sz[u] += sz[v];
        }
        else
        {
            rB.push({u,par[u]});
            par[u] = v,sz[v] += sz[u];
        }
    }
    void addCheck(){
        rB.push({-1,-1});
    }
    void roll_back(){
        if(rB.empty())
            return ;
        auto item=rB.top();
        while (item.first!=-1) {
            rB.pop();
            par[item.first] = item.second;
            comp++;
            if(rB.empty())break;
            item=rB.top();
        }
        if(rB.size()){
            rB.pop();
        }
    }
};
struct query{
    int ch;
    ll u,v;
};
DSU dsu;
vector<vector<int>>seg(N<<2);
vector<query> queries(N);
vector<int> answer(N,-1);
void update(int node,int l,int r,int st,int en,int qIdx){
    if(st>r||l>en)return;
    if(st<=l&&r<=en){
        seg[node].push_back(qIdx);
        return;
    }
    ll mid=(l+r)/2;
    update(2*node,l,mid,st,en,qIdx);
    update(2*node+1,mid+1,r,st,en,qIdx);
}
void dfs(int node,int l,int r){
    dsu.addCheck();
    for(auto item:seg[node]){
        if(queries[item].ch==1)
            dsu.connect(queries[item].u,queries[item].v);
    }
    if(l==r){
        answer[l]=dsu.comp;
    }else{
        ll md=(l+r)/2;
        dfs(2*node,l,md);
        dfs(2*node+1,md+1,r);
    }
    dsu.roll_back();
}
void func(int index) {
    ll n,mm,m;cin>>n>>mm>>m;// call update for m
    dsu.init(n);
    m+=mm;
    map<pair<int,int>,pair<int,int>>ma;

    for (int i = 1; i <= mm; ++i) {
        ll u,v;cin>>u>>v;
        queries[i]={1,min(u,v),max(u,v)};
        ma[{min(u,v),max(u,v)}]={1,i};
    }
    for (int i = mm+1; i <= m ; ++i) {
        int ch;cin>>ch;
        ll u,v;cin>>u>>v;
        queries[i]={ch,min(u,v),max(u,v)};
    }

    for (int i = mm+1; i <= m ; ++i) {
        if(queries[i].ch==1){
            ma[{queries[i].u,queries[i].v}]={i,i};
        }else{
            update(1,1,m,ma[{queries[i].u,queries[i].v}].first,i-1,ma[{queries[i].u,queries[i].v}].second);
            ma.erase({queries[i].u,queries[i].v});
        }
    }
    for (auto item:ma) {
        update(1,1,m,item.second.first,m,item.second.second);
    }
    dfs(1,1,m);
    for (int i = mm; i <= m ; ++i) {
        cout<<answer[i]<<" ";
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