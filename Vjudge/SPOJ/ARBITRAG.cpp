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
const ll OO =1e9 , mod = 1e9+7;
const ll N =35 , M = 23, sqr = 45;

ll n ,m ;
vector<ld>dist(N),par(N);
vector < pair < ld , ld > > g[N];

void Dijkstra( int src)
{
    dist.assign(n+1,-OO);
    //par.assign(n+1,-1)
    dist[src] = 1;
                    //  distance node
    priority_queue< pair < ld , ld > > pq;
    pq.push({1,src});
    while(!pq.empty())
    {
                    if(dist[1]>(ld)1)return;

        ld node = pq.top().second , distance = pq.top().first;
        pq.pop();
        if(distance < dist[node])
            continue;
        for(auto ch : g[(ll)node])
        {
            if(dist[node] * ch.second > dist[ch.first])
            {
		//par[ch.first]=node;
                dist[ch.first] = dist[node] * ch.second;
                pq.push({dist[ch.first],ch.first});
            }
        }
    }
}
void testCase(int item)
{
        clr(g,{});
    cout<<"Case "<<item<<": ";
    map<string ,int>mm;
    fo(i,n){
        string str;cin>>str;
        mm[str]=i+1;
    }
   // string ss;cin>>ss;
    cin>>m ;
    for ( int i = 0 ; i < m ;i++)
    {

        int u, v ;
        float w;
        string str1,str2;
        cin >> str1 >> w >> str2;
        u=mm[str1],v=mm[str2];
        g[u].push_back({v,w});
    }
    Dijkstra(1);
    if(dist[1]>(ld)1)cout<<"Yes\n";
    else cout<<"No\n";
}

int main()
{

        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
            int index=1;
            while(cin>>n){
                if(n==0)break;
                testCase(index++);
            // string ss;cin>>ss;
            }
}


