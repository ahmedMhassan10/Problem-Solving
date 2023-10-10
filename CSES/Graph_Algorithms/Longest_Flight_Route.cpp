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
ll n ,m ;
vector<ll>dist(N),par(N);
vector < pair < ll, ll> > g[N];

void Dijkstra( ll src)
{
    vll vis(N,0);
    dist.assign(n+1,-OO);
    par.assign(n+1,-1);
    dist[src] = 0;
    //  distance node
    priority_queue< pair < ll, ll> > pq;
    pq.push({0,src});

    while(!pq.empty())
    {
        ll node = pq.top().second , distance = pq.top().first;
        pq.pop();
        vis[node]++;
        if(dist[node]>distance||vis[node]>=20)
            continue;
        for(auto ch : g[node])
        {
            if(dist[node] + ch.second > dist[ch.first])
            {
                par[ch.first]=node;
                dist[ch.first] = dist[node] + ch.second;
                pq.push({dist[ch.first],ch.first});
            }
        }
    }
}
void func(int inde) {
    cin>>n>>m;
    fo(i,m){
        ll u,v;cin>>u>>v;
        g[u].push_back({v,1});
    }
    Dijkstra(1);
    if(dist[n]!=-OO){
        ll node=n;
        vll res;
        res.push_back(node);
        while (node!=1){
            node=par[node];
            res.push_back(node);
        }
        reverse(all(res));
        cout<<res.size()<<'\n';
        fvec(item,res)cout<<item<<" ";
    }else{
        cout<<"IMPOSSIBLE";
    }
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