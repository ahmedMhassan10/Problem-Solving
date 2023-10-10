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
const int N = 2e5+10 , M = 23, sqr = 45;
ll pow(ll a, ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans*a)%mod;
        b/=2;
        a=(a*a)%mod;
    }
    return ans;
}

vector<int>adjList[N];
bool vis[N];
ll BFS(int s) {
    ll len=1;
	queue<int> q;
	q.push(s); vis[s] = true;

	while(!q.empty()) {
            int cur = q.front();q.pop();
			fvec(i, adjList[cur])
			    if (!vis[i] ){
                    q.push(i); vis[i] =true;
                    len++;
				}

	}
	return len;	//cur is the furthest node from s with depth dep && dep is the depth of it
}

int main()
{

        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        ll n,k;cin>>n>>k;
        ll re=pow(n,k);
        fo(i,n-1){
            int u,v,w;cin>>u>>v>>w;
            if(w==0){
                adjList[u].pb(v);
                adjList[v].pb(u);
            }
        }
        fp(i,1,n){
            if(!vis[i]){
                ll len=BFS(i);
                re-=pow(len,k);
                re=(re+mod)%mod;
            }
        }
        cout<<(re+mod)%mod;
}


