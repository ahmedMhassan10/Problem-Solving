#include<bits/stdc++.h>
using namespace std;
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define fo(i, n)		for(int i=0;i<(int)(n);++i)
#define fp(i, j, n)	for(int i=(j);i<=(int)(n);++i)
#define fn(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define fvec(i,vec) for(auto i:vec)
#define pb				push_back
#define MP			make_pair
typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef unsigned long long ull;
typedef  long long ll;
const ll OO =10e9;
#define mine(x,y,z) min(x,min(y,z))
#define maxe(x,y,z) max(x,min(y,z))
map<ll, vector < int > >adj;
map<ll,bool> vis;
map<int,int>m;
vector<int>re;
/*
void dfs2(int node,int counter){
    counter++;vis2[node]=true;
    if(counter%2==1)m[node]=abs(m[node]-1);
        for ( auto child : adj[node])
        if(vis2[child] == false){
            dfs2(child,counter);
        }
}*/
void dfs( int node, int counter,bool even ,bool odd )
{
    counter++;
    if(even &&counter%2==0) m[node]=abs(m[node]-1);
    if(odd&&counter%2==1)m[node]=abs(m[node]-1);
    if(m[node]==1){
        if(counter%2==0)even=!even;
        else odd=!odd;
        re.pb(node);
    }

    vis[node] = true;
    for ( auto child : adj[node])
        if(vis[child] == false){
            dfs(child,counter,even,odd);
        }
}
int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int num;cin>>num;
        fo(i,num-1){
            int u,v;cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vector<int>vec1(num),vec2(num);
        fo(i,num)cin>>vec1[i];
        fo(i,num)cin>>vec2[i];
        fo(i,num)
            if(vec1[i]!=vec2[i])m[i+1]=1;

        dfs(1,0,false,false);

        cout <<re.size()<<endl;
        rep(i,re)cout<<re[i]<<endl;
}

