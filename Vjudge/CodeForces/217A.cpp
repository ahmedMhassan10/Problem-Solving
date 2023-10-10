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
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef unsigned long long ull;
typedef long long ll;
const ll OO = 1e5+3, mod = 1e8 , N = 105;

map<pair<int,int>, vector < pair<int,int> > >adj;
map<pair<int,int>,bool> vis;
void dfs( pair<int,int> node)
{
    vis[node] = true;
    for ( auto child : adj[node])
        if(vis[child] == false)
            dfs(child);
}

int main() {
   // freopen("survive.in "," r ",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int num;cin>>num;
    map<int,pair<int,int>>mx,my;
    vector<pair<int,int>>vec;
    int x,y;
    fo(i,num){
       cin>>x>>y;
       vec.pb({x,y});
        if(mx[x]!=make_pair(0,0)){
            adj[{x,y}].pb(mx[x]);
            adj[mx[x]].pb({x,y});
        }
        else mx[x]={x,y};
        if(my[y]!=make_pair(0,0)){adj[{x,y}].pb(my[y]);
            adj[my[y]].pb({x,y});
        }
        else my[y]={x,y};
    }
    dfs(vec[0]);
    ll ans=0;
    fo(i,num){
        if(!vis[vec[i]]){
            dfs(vec[i]);
            ans++;
        }
    }
    cout<<ans;
}
