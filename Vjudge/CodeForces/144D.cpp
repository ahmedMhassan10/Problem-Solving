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
const ll OO =10e16;
const int N = 2e5+10 , M = 23 , mod = 1e9+7, sqr = 45;
int n ,m ;
vector<ll>dist(N),par(N);
vector < pair < ll , ll > > g[N];

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
}
void getpath(int num){
	vector<int>vec;
	while(num!=-1){
		vec.pb(num);
		num=par[num];
	}
	fn(i,siz(vec)-1,0){
		cout<<vec[i]<<" ";
	}

}
int src;

void testCase()
{
    cin >> n >> m >>src;
    for ( int i = 0 ; i < m ;i++)
    {
        int u, v ,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    Dijkstra(src);
}

int main()
{

        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        testCase();
        int l;cin>>l;
        ll re=0;
        set<pair<pair<int,int>,int>>s;
        fp(i,1,n){
            if(dist[i]==l)re++;
                fvec(ch,g[i]){
                            s.insert({{min((ll)i,ch.first),max((ll)i,ch.first)},ch.second});
                }
        }
        fvec(ele,s){
            int c=ele.S;
            if(dist[ele.F.F]<l&&dist[ele.F.S]<l&&dist[ele.F.F]+dist[ele.F.S]+c==2*l)re++;
            else if(dist[ele.F.F]+dist[ele.F.S]+c>2*l){
                if(dist[ele.F.F]<l&&dist[ele.F.F]+c>l)re++;
                if(dist[ele.F.S]<l&&dist[ele.F.S]+c>l)re++;
            }
        }
        cout<<(re);
}


