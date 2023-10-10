#include <bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()), ((v).end())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < sz(v); ++i)
#define fo(i, n) for (int i = 0; i < (int)(n); ++i)
#define fp(i, j, n) for (int i = (j); i <= (int)(n); ++i)
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
typedef vector<pair<ll,ll>> vp;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
#define setp(item) cout<<fixed<<setprecision(item);
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO = 1e9, mod = 1e9 + 7,mod2=1e9+9, N = 5e5+10,M=25;


int n , ancestor[N][M], lvl[N];
vector < int > g[N];

void dfs( int node , int par)
{
    lvl[node] = lvl[par] + 1;
    ancestor[node][0] = par;
    for ( int j = 1 ; j < M ; j++)
    {
        int p = ancestor[node][j-1];
        ancestor[node][j] = ancestor[p][j-1];
    }
    for(auto ch : g[node])
    {
        if(ch == par)
            continue;
        dfs(ch,node);
    }
}

int findKthAncestor( int u , int k)
{
    for ( int j = M-1 ; j >= 0 ; j--)
        if(k&(1<<j))
            u = ancestor[u][j];
    return u;
}

int getLCA( int u , int v)
{
    if(lvl[u] < lvl[v])
        swap(u,v);
    u = findKthAncestor(u,lvl[u]-lvl[v]);
    if ( u == v)
        return u;
    for ( int i = M-1 ; i>= 0 ;i--)
    {
        if(ancestor[u][i] == ancestor[v][i])
            continue;
        u = ancestor[u][i];
        v = ancestor[v][i];
    }
    return ancestor[u][0];
}
void solve(int n){
    fp(i,1,n-1){
        int u,v;cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,1);
    int q;cin>>q;
    while(q--){
        int u,v;cin>>u>>v;
        if(lvl[u]>lvl[v])swap(u,v);
        int mid=getLCA(u,v);
        if(mid==u){
            int dist=lvl[u]+lvl[v];
            if(dist%2==0){
                cout<<"The fleas meet at "<< findKthAncestor(v,lvl[v]-dist/2) <<".\n";
            }else {
                cout<<"The fleas jump forever between "<<findKthAncestor(v,lvl[v]-dist/2) <<" and "<< findKthAncestor(v,lvl[v]-dist/2-1)<<".\n";
            }
        }else{
            if(lvl[u]==lvl[v])
                cout<<"The fleas meet at "<< mid <<".\n";
            else {
                int dist=lvl[u]+lvl[v]-2*lvl[mid];
                if(dist%2==0){
                    cout<<"The fleas meet at "<< findKthAncestor(v,dist/2) <<".\n";
                }else{
                    cout<<"The fleas jump forever between "<<findKthAncestor(v,dist/2+1) <<" and "<< findKthAncestor(v,dist/2)<<".\n";
                }
            }
        }
    }
}
int main() {
        // freopen("survive.in "," r ",stdin);
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

        while(cin>>n){
           
            clr(g,0);clr(lvl,0);clr(ancestor,0); if(n==0)break;
            solve(n);
        }
        return 0;
}
