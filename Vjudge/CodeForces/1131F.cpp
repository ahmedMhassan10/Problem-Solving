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
const int N=150005 ;
int par[N], sz[N];
vector<vector<int>>vec;
map<ll,vector<ll>>m;
void init(int n)
{
    for ( int i = 1 ; i <= n ;i++)
    {
        par[i] = i ; sz[i] = 1;m[i].pb(i);
    }
}

int findparent( int u)
{
    if(par[u] == u)
        return  u;
    return par[u] = findparent(par[u]);
}
bool iscyclic = false;
void connect( int u , int v)
{
    int u1=u,v1=v;
    u = findparent(u);
    v = findparent(v);
    if ( u == v)
    {
        iscyclic =true;
        return;
    }
    if(sz[v] < sz[u]){
        fvec(i,m[v]){m[u].pb(i);}
        par[v] = u ;sz[u] += sz[v];
    }
    else{
        fvec(i,m[u]){m[v].pb(i);}
        par[u] = v;sz[v] += sz[u];
    }
}
bool isconnected( int u , int v)
{
    return (findparent(u) == findparent(v));
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int num;cin>>num;
        init(num);
        fo(i,num-1){
            int u,v;cin>>u>>v;
            connect(u,v);
        }
        vector<ll> ans=m[findparent(1)];
        fvec(i,ans)cout<<i<<" ";
}


