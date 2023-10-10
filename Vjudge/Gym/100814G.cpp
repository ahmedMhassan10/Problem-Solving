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
const ll N =10e5+10 , M = 23, sqr = 45;
struct Edge {
    ll to, cost, wis;

};


ll n ,m,k;
vector<ll>dist(N),par(N);
map<ll,vector < Edge>> g;
void Dijkstra( ll wiis)
{
    dist.assign(n+1,OO);
    dist[1] = 0;
    priority_queue< pair < ll , ll > > pq;
    pq.push({0,1});
    while(!pq.empty())
    {
        ll node = pq.top().second , distance = -pq.top().first;
        pq.pop();

        for(auto ch : g[node])
        {
            if(dist[node] + ch.cost < dist[ch.to]&&ch.wis<=wiis)
            {
                dist[ch.to] = dist[node] + ch.cost;
                pq.push({-dist[ch.to],ch.to});
            }
        }
       // if(dist[n]!=OO)break;
    }
}
void testCase()
{
    g.clear();
    cin >> n >> m>>k ;
    for ( int i = 0 ; i < m ;i++)
    {
        int u, v ,c,w;
        cin >> u >> v >>c>> w;
        g[u].push_back({v,c,w});
        g[v].push_back({u,c,w});
    }
    ll left=0,right=1e9+5;
    ll result=-1;

    while(left<=right){
        ll mid=(left+right)/2;
        Dijkstra(mid);
        if(dist[n]<k){
            result=mid;
            right=mid-1;
        }else left=mid+1;
    }
    cout<<result<<"\n";
}


int main()
{

        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int t;cin>>t;
        while(t--)
            testCase();
}


