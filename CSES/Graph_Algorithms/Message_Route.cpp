#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v) ((v).begin()), ((v).end())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < siz(v); ++i)
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
typedef pair<ll,ll> pll;
typedef vector<pll> vp;
typedef vector< long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define setp(item) cout<<fixed<<setprecision(item);
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO = 1e18, mod = 1e9+7,mod2=1e9+9, N =1e5+5,M=30,MOD=998244353;
vi par(N,-1);
vector<vector<int>>adjList(N);
vector<ll> len(N, OO);
void BFS(int s) {
    queue<int> q;
    q.push(s), len[s] = 1;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        fvec(i, adjList[cur])
            if (len[i] == OO){
                q.push(i);
                len[i] =len[cur]+1;
                par[i]=cur;
            }
    }
}
void solve(ll inde) {
    ll n,m;cin>>n>>m;
    fo(i,m){
        ll u,v;cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    BFS(1);
    if(len[n]==OO){
        cout<<"IMPOSSIBLE";
    }else{
        cout<<len[n]<<'\n';
        ll st=n;
        vll res;
        while (st!=-1){
            res.push_back(st);
            st=par[st];
        }
        reverse(all(res));
        fvec(item,res){
            cout<<item<<" ";
        }
    }
}
int main() {
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t=1;
//    cin>>t;
    ll index=1;
    while (t--){
        solve(index++);
    }
    return 0;
}

