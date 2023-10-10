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

map<int,vector<int>> adjlist; // num of node    ///imp make vii a(n+1) and adjlist=a;   ///******

bool isBipartite(int V)/////  num of nodes   not start
{
    // vector to store colour of vertex
    // assigning all to -1 i.e. uncoloured
    // colours are either 0 or 1
    // for understanding take 0 as red and 1 as blue
    vector<int> col(V+1, -1);

    // queue for BFS storing {vertex , colour}
    queue<pair<int, int> > q;

    //loop incase graph is not connected
    for (int i = 1; i <= V; i++) {

        //if not coloured
        if (col[i] == -1) {

            //colouring with 0 i.e. red
            q.push({ i, 0 });
            col[i] = 0;

            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();

                //current vertex
                int v = p.first;
                //colour of current vertex
                int c = p.second;

                //traversing vertexes connected to current vertex
                for (int j : adjlist[v]) {

                    //if already coloured with parent vertex color
                    //then bipartite graph is not possible
                    if (col[j] == c)
                        return 0;

                    //if uncoloured
                    if (col[j] == -1) {
                        //colouring with opposite color to that of parent
                        col[j] = (c) ? 0 : 1;
                        q.push({ j, col[j] });
                    }
                }
            }
        }
    }
    //if all vertexes are coloured such that
    //no two connected vertex have same colours
    return 1;
}
int main() {
        // freopen("survive.in "," r ",stdin);
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int t;cin>>t;
        int index=1;
        while(t--){
                cout<<"Scenario #"<<index++<<":\n";
            adjlist.clear();
            ll num,m;cin>>num>>m;
            fo(i,m){
                ll u,v;cin>>u>>v;
                adjlist[u].pb(v);
                adjlist[v].pb(u);
            }
            if(isBipartite(num))
            {
                cout<<"No suspicious bugs found!\n";
            }else{
                cout<<"Suspicious bugs found!\n";
            }
        }
}
