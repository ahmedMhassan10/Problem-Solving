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
const ll OO =10e16 , mod = 1e9+7;
const int N = 25 ;
string ss;
int n ,m,k ;
map<int ,string>m1;
map<string,int>m2;
vector<ll>dist(N),par(N),cost(N);
vector < pair < int , int > > g[N];

void Dijkstra( int src)
{

    fo(i,n){
        dist[i+1]=OO;
        par[i+1]=-1;
    }
    dist[src]=cost[src];
    priority_queue< pair < int , int > > pq;
    pq.push({-dist[src],src});
    while(!pq.empty())
    {
        int node = pq.top().second , distance = -pq.top().first;
        pq.pop();
        if(distance > dist[node])
            continue;
        for(auto ch : g[node])
        {
            if(dist[node] + 2*ch.second+cost[ch.first] < dist[ch.first])
            {
		par[ch.first]=node;
                dist[ch.first] = dist[node] + 2*ch.second+cost[ch.F];
                pq.push({-dist[ch.first],ch.first});
            }
        }
    }
}
void getpath(int num){
	vector<string>vec;
	while(num!=-1){
		vec.pb(m1[num]);
		num=par[num];
	}
	fn(i,siz(vec)-1,0){
		cout<<vec[i];
		if(i!=0)cout<<" ";
	}

}
void testCase(int item)
{
    clr(g,{});
    m1.clear();m2.clear();
    cout<<"Map #"<<item<<'\n';
    cin >> n  ;
    fo(i,n){
        string str;cin>>str;
        m2[str]=i+1;m1[i+1]=str;
        cin>>cost[i+1];
    }
    cin>>m;
    for ( int i = 0 ; i < m ;i++)
    {
        string str1,str2;cin>>str1>>str2;
        int u=m2[str1], v=m2[str2] ,w;
        cin>> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    cin>>k;
    fo(i,k){
        cout<<"Query #"<<i+1<<'\n';
        string st,en;cin>>st>>en;
        int seat;cin>>seat;
        Dijkstra(m2[st]);
        getpath(m2[en]);cout<<'\n';
        double re=((float)(dist[m2[en]]+.1*dist[m2[en]])/seat);
        cout<< "Each passenger has to pay : "<<setprecision(2)<<fixed<<re<<" taka\n";
    }
}



int main()
{

        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
       ll t;cin>>t;
       fo(i,t){
           if(i>0)cout<<"\n";
          // cin>>ss;
           testCase(i+1);}
}


