#include <bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()), ((v).end())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < sz(v); ++i)
#define fo(i, n) for (int i = 0; i < (int)(n); ++i)
#define fp(i, j, n) for (long long i = (j); i <= (long long)(n); ++i)
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
const ll OO = 1e18, mod = 1e9+7,mod2=1e9+9, N =10000+5,M=23;
int vis[N] , deg[N];
vector < pair < int , int > > g[N];
vector < int > ans;
void dfs( int node )
{
  while(!g[node].empty())
    {
        int v = g[node].back().F;
        int idx = g[node].back().S;
        g[node].pop_back();
        if(vis[idx])
            continue;
        vis[idx] = 1 ;
        dfs(v);
    }
    ans.push_back(node);
}
int n , m ;
 void testCase()
{
    ans.clear();clr(vis,0);
    fo(item,n+2)g[item].clear();
    clr(deg,0);
    for ( int i = 0 ; i < m ; i++)
    {
        int u, v;
        cin >> u >> v;
        u++,v++;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
        deg[u]++,deg[v]++;
    }
    for ( int i = 1; i <= n ; i++)
    {
        if(deg[i] % 2 == 1)
        {
            cout << "Not Possible\n";
            return;
        }
    }
    dfs(1);
    if(ans.size() != m+1)
    {
        cout << "Not Possible\n";
        return;
    }
    cout<<"Possible";
    cout << '\n';
}

int main() {
        //freopen("input.txt","rt",stdin);
        //freopen("output.txt","wt",stdout);
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        while(cin>>n>>m){
            if((n+m)==0)break;
            if(m==0)
                cout<<"Not Possible\n";
            else
                testCase();
        }
}
