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
ll counter=0;
void dfs( int node)
{
    counter++;
    vis[node] = true;
    for ( auto child : adj[node])
        if(vis[child] == false){
            dfs(child);
        }
}
int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int num,re;       cin>>num>>re;
        while(num!=0||re!=0){
        vis.clear();
        adj.clear();
        map<string,int>m;
        ll cc=0;
        fp(i,1,num)
        {
            string str;cin>>str;
            m[str]=i;
        }
        fp(i,1,re){
            string s1,s2;cin>>s1>>s2;
            adj[m[s1]].pb(m[s2]);
            adj[m[s2]].pb(m[s1]);
        }
        fp(i,1,num){
            if(vis[i]==false){
                dfs(i);
                cc=max(cc,counter);
                counter=0;
            }
        }
        cout<<cc<<'\n';
        cin>>num>>re;
    }
}

