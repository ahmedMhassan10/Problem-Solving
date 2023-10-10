#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define all(v) ((v).begin()), ((v).end())
#define allRev(v) ((v).rbegin()), ((v).rend())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define fo(i, n) for (long long i = 0; i < (long long)(n); ++i)
#define fp(i, j, n) for (long long i = (j); i <= (long long)(n); ++i)
#define fn(i, j, n) for (long long i = (j); i >= (long long)(n); --i)
#define fvec(i, vec) for (auto i : vec)
#define pb push_back
#define mine(x, y, z) min(x, min(y, z))
#define maxe(x, y, z) max(x, max(y, z))
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef vector<pll> vp;
typedef vector<double> vd;
typedef vector<string> vs;
typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define setp(item) cout<<fixed<<setprecision(item);
#define PI 3.14159265358979323846264338327950
ll ceilSqrt(ll a){
    return ::ceil(sqrtl(a));
}
ll  divC(ll a,ll b){
    return a/b+(a%b!=0);
}
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO =1e15, mod = 1e9+7,mod2=1e9+9, N =1e5+5,M=30,MOD= 998244353, minOO=LLONG_MIN;
///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة
/// :-)
/// a33333333333333333333333333333333333333333333333333333333333333333333333333333333333333
vector<vector < int > >adj(N);
vector<bool> vis(N,0);
ll stNode=-1,enNode=-1;
vll parent(N);
bool cycle=0;
vector<bool>instack(N);
void dfs( int node,int par)
{

    instack[node]=1;
    vis[node] = true;
    parent[node]=par;
    for ( auto child : adj[node])
        if(vis[child] == false)
            dfs(child,node);
        else if(instack[child]){
            cycle =true;
            stNode=node,enNode=child;
        }
    instack[node]=0;
}

void func(int inde) {
    ll n,m;cin>>n>>m;
    fo(i,m){
        ll u,v;cin>>u>>v;
        adj[u].push_back(v);
    }
    fp(i,1,n){
        if(vis[i]==0){
            dfs(i,0);
            if(stNode==-1)continue;
            vll res;
            ll node=stNode;
            res.push_back(node);
            while (node!=enNode){
                node=parent[node];
                res.push_back(node);
            }
            res.push_back(stNode);
            cout<<res.size()<<'\n';
            reverse(all(res));
            fvec(item,res)cout<<item<<" ";
            return;
        }
    }cout<<"IMPOSSIBLE";
}
int main() {
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
//    cin>>t;
    ll index=1;
    while (t--){
        func(index++);
    }
    return 0;
}