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
const ll OO =10e9+7;
int N=10e5+5;

vector<int> par(N), sz(N),sum(N),chi(N);
void init(int n)
{
    for ( int i = 1 ; i <= n ;i++){
        par[i] = i ;sz[i] = 1;sum[i]=i;chi[i]=i;
    }
}
int findparent( int u)
{
    if(par[u] == u)
        return  u;
    return findparent(par[u]);
}
int findchild(int u){
    if(chi[u]==u)return u;
    return findchild(chi[u]);
}
bool isconnected( int u , int v)
{
    return (findparent(u) == findparent(v));
}
void connect( int u , int v)
{
    if (isconnected( u , v))return;
    int chiu=findchild(u);
    u = findparent(u);
    v = findparent(v);
    chi[chiu]=v;
    par[v] = chiu ,sz[u] += sz[v];
    sz[v]=0;
    sum[u]+=sum[v];sum[v]=0;
}

void movenode(int u,int v){
    if(isconnected(u,v)) return;
    int paru=findparent(u),chiu=findchild(u);
    if(paru==u&&chiu==u)connect(v,u);

    else if(paru==u&&chiu!=u){
        sz[chi[u]]=sz[u]-1;sz[u]=1;
        sum[chi[u]]=sum[u]-u;sum[u]=u;
        par[chi[u]]=chi[u];
        chi[u]=u;par[u]=u;
        connect(v,u);
    }
    else if( paru!=u&&chiu==u){
        sz[paru]--;sum[paru]-=u;
        sz[u]=1;sum[u]=u;
        chi[par[u]]=par[u];
        chi[u]=u;par[u]=u;
        connect(v,u);
    }
    else {
        sum[paru]-=u;sz[paru]--;
        sz[u]=1;sum[u]=u;
        par[chi[u]]=par[u];chi[par[u]]=chi[u];
        chi[u]=u;par[u]=u;
        connect(v,u);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    while(cin>>n>>m){
            init(n);
        fo(i,m){
        int num;cin>>num;
        if(num==1){
            int u,v;cin>>u>>v;
            connect(u,v);
        }else if (num==2){
            int u,v;cin>>u>>v;
            movenode(u,v);
        }else {
            int u;cin>>u;
            cout<<sz[findparent(u)]<<" "<<sum[findparent(u)]<<'\n';
        }
        }
    }
}


