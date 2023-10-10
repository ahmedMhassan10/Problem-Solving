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
const ll OO = 1e10, mod = 1e9 + 7,mod2=1e9+9, N =1e5 +5,M=23;

map<ll, vector < int > >adj;
map<ll,bool> vis2;
bool cycle = false;
void cyclic( int node , int par)
{
    vis2[node] = true;
    for (auto child : adj[node])
       {
        if(vis2[child] == false)
            cyclic(child,node);
        else if (child != par)
            cycle = true;
    }
}
int main() {
        // freopen("survive.in "," r ",stdin);
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int num,m;cin>>num>>m;
        fo(i,m){
            ll u,v;cin>>u>>v;
            adj[u].pb(v);adj[v].pb(u);
        }
        cyclic(1,0);
        fp(i,1,num){
            if(vis2[num]==false){
                cout<<"NO\n";
                return 0;
            }

        }
        if(cycle){
            cout<<"NO\n";
        }else cout<<"YES\n";
}
