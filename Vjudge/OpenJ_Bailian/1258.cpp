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
typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef unsigned long long ull;
typedef  long long ll;
const ll OO =10e7;
const int N=200 ;
map<int,int> par, sz;
void init(int n)
{
    for ( int i = 1 ; i <= n ;i++)
        par[i] = i , sz[i] = 1;
}
// O(n) ---> O(n ^ 2)
int findparent( int u)
{
    if(par[u] == u)
        return  u;
    return par[u] = findparent(par[u]);
}
bool iscyclic = false;
void connect( int u , int v)
{
    u = findparent(u);
    v = findparent(v);
    if ( u == v)
    {
        iscyclic =true;
        return;
    }
    if(sz[v] < sz[u])
        par[v] = u ,sz[u] += sz[v];
    else
        par[u] = v,sz[v] += sz[u];
}
bool isconnected( int u , int v)
{
    return (findparent(u) == findparent(v));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    while(cin>>n &&n){
    init(n);
    vector<pair<int,pair<int,int>>> vec;
    for ( int i = 1 ; i <= n;  i++)
    {
        for(int j=1;j<=n;j++){
            int k;cin>>k;
                if(i<j)
                    vec.pb({k,{i,j}});
        }
    }
    sort(vec.begin(),vec.end());
    int ans=0;
    for(int i=0;i<vec.size();i++)
	{
		int u=vec[i].second.first,v=vec[i].second.second;
		if(isconnected(u,v))
			continue;
		ans+=vec[i].first;
		connect(u,v);
	}
	cout<<ans<<'\n';
    }
}


