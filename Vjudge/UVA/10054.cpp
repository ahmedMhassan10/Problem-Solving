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
#define maxe(x, y, z) max(x, min(y, z))
#define F first
#define S second
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef unsigned long long ull;
typedef long long ll;
const ll OO = 1e5, mod = 1e9 + 7, N = 1e5;


ll vis[N] , deg[N],m,n=55;
vector < pair < ll , ll > > g[N];
vector < ll > ans;
void dfs( ll node)
{
  while(!g[node].empty())
    {
        ll v = g[node].back().F;
        ll idx = g[node].back().S;
        g[node].pop_back();
        if(vis[idx])
            continue;
        vis[idx] = 1 ;
        dfs(v);
    }
    ans.push_back(node);
}
 void testCase(int item)
{
    cout<<"Case #"<<item<<'\n';
    ans.clear();
    fo(i,51)
        g[i].clear();
    clr(vis,0);
    clr(deg,0);
    cin >> m;
    set<int>s;
    for ( int i = 1 ; i <= m ; i++)
    {
        ll u, v;
        cin >> u >> v;
        s.insert(u);s.insert(v);
        g[u].push_back({v,i});
        g[v].push_back({u,i});
        deg[u]++,deg[v]++;
    }
    fvec(i,s)
    {
        if(deg[i] % 2 == 1)
        {
            cout << "some beads may be lost\n";
            return;
        }
    }
    dfs(*s.begin());
    if(ans.size() != m+1)
    {
        cout << "some beads may be lost\n";
        return;
    }
    for ( int i = 1 ; i <=m; i++){
        cout << ans[i-1] << " "<<ans[i];
        cout << "\n";
    }
}
int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1;cin>>t;
  for(int i=1;i<=t;i++){
        if(i>1)  cout<<'\n';
        testCase(i);
  }
}
