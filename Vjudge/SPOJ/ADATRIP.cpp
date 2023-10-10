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
const ll OO =1e7+5 , mod = 1e9+7;
const int N =10e5+10 , M = 23, sqr = 45;

int n ,m,k ;
vector<int>dist(N),par(N);
vector < pair < int , int > > g[N];

void Dijkstra( int src)
{
    dist.assign(n+1,OO);
   //par.assign(n+1,-1);
    dist[src] = 0;
                    //  distance node
    priority_queue< pair < int , int > > pq;
    pq.push({0,src});
    while(!pq.empty())
    {
        int node = pq.top().second , distance = -pq.top().first;
        pq.pop();
        if(distance > dist[node])
            continue;
        for(auto ch : g[node])
        {
            if(dist[node] + ch.second < dist[ch.first])
            {
                //par[ch.first]=node;
                dist[ch.first] = dist[node] + ch.second;
                pq.push({-dist[ch.first],ch.first});
            }
        }
    }
}/*
void getpath(int num){
	vector<int>vec;
	while(num!=-1){
		vec.pb(num);
		num=par[num];
	}
	fn(i,siz(vec)-1,0){
		cout<<vec[i]<<" ";
	}

}*/
void testCase()
{
    cin >> n >> m>>k ;
    for ( int i = 0 ; i < m ;i++)
    {
        int u, v ,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    fo(i,k){
        int u;cin>>u;
        Dijkstra(u);
        ll maxi=0 , re=0;
        fo(i,n){
            if(dist[i]==OO)continue;
            if(dist[i]==maxi)re++;
            else if(dist[i]>maxi){
                re=1;maxi=dist[i];
            }
        }

        cout<< maxi <<" "<<re<<'\n';
    }

}

int main()
{

        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        testCase();
}


