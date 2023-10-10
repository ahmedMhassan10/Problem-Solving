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
const ll OO = 1e9, mod = 1e9+7,mod2=1e9+9, N =200+5,M=23;
ll dist[N] , n,m,val[N];
vector < pair < int , pair < ll, ll> > > edges;
bool negCycle = false;
map<ll,ll>ma;
void Bellman_Ford( ll  src)
{
    dist[src] = 0;
    // O(n * m)
    for(int i= 1 ; i<= n ; i++) {
        for(int j = 0; j < edges.size(); j++) {
            int u = edges[j].S.F, v = edges[j].S.S, w = edges[j].F;
            if(dist[u]!=OO)
            if (dist[u] + w < dist[v])
            {
                if(i == n)
                    negCycle,ma[v]++;
                dist[v] = dist[u] + w;
            }
        }
    }
}
ll inde=1;
void testcase(){
    ma.clear();
    fp(i,0,n){
        edges.clear();
        dist[i]=OO;
        val[i]=0;
    }
    cout<<"Set #"<<inde++<<'\n';
    fp(i,1,n)cin>>val[i];
    cin >> m ;
    for ( int i = 0 ; i < m ; i++)
    {
        ll u , v , w;
        cin >> u >> v;
        w=val[v]-val[u];
        w=w*w*w;
        edges.push_back({w,{u,v}});
    }
    Bellman_Ford(1);
    ll q;cin>>q;
    while(q--){
        ll u;cin>>u;
        if(ma[u] >0|| dist[u]<3||dist[u]>=OO)cout<<"?\n";
        else cout<<dist[u]<<'\n';
    }
}

int main() {
        //freopen("input.txt","rt",stdin);
        //freopen("output.txt","wt",stdout);
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        while(cin>>n)
        {
            //if(n==0)break;
            testcase();
        }
}
