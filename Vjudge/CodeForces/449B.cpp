#include<bits/stdc++.h>
using namespace std;
#define all(v)				((v).begin()), ((v).end())
#define siz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define fo(i, n)		for(int i=0;i<(int)(n);++i)
#define fp(i, j, n)	for(int i=(j);i<=(int)(n);++i)
#define fn(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define fvec(i,vec) for(auto i:vec)
#define pb				push_back
#define MP			make_pair
#define mine(x,y,z) min(x,min(y,z))
#define maxe(x,y,z) max(x,min(y,z))
#define F first
#define S second
typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef unsigned long long ull;
typedef  long long ll;
const ll OO =1e17+5 , mod = 1e9+7;
const ll N =1e5+10 , M = 23, sqr = 45;
ll n ,m ,k;
vector<ll>dist(N);
bool solve[N];
vector <pair<int, pair < int , int > >> g[N];
void Dijkstra( ll src)
{
    dist.assign(n+1,OO);
    dist[src] = 0;
    ll re=0;
                    //  distance node
    priority_queue< pair < int , int > > pq;
    pq.push({0,src});
    while(!pq.empty())
    {
        ll node = pq.top().second , distance = -pq.top().first;
        pq.pop();
        if(distance > dist[node])
            continue;
        for(auto ch : g[node])
        {
            if(dist[node] + ch.second.S < dist[ch.S.first])
            {
                solve[ch.S.F]=(bool)ch.F;
                dist[ch.S.first] = dist[node] + ch.S.second;
                pq.push({-dist[ch.S.first],ch.S.first});
            }else if(dist[node]+ch.S.S==dist[ch.S.F]&&!ch.F){
                solve[ch.S.F]=0;
            }
        }
    }
}
void testCase()
{
    cin >> n >> m>>k ;
    for ( int i = 0 ; i < m ;i++)
    {
        ll u, v ,w;
        cin >> u >> v >> w;
        g[u].push_back({0,{v,w}});
        g[v].push_back({0,{u,w}});
    }
    fo(i,k){
        ll u,v;cin>>u>>v;
        g[1].pb({1,{u,v}});
        g[u].pb({1,{1,v}});

    }
    Dijkstra(1);
    ll sum=0;
    fp(i,1,n){
        sum+=(int)solve[i];
    }
    cout<<k-sum;
}


int main()
{

        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        testCase();
}


