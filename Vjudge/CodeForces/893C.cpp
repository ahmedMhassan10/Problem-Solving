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
const ll OO =1e16 , mod = 1e9+7, N =1e5+5 ;
map<ll,vector<int>>adjList;
vector<ll> len(N, OO),cost(N);
ll sum=OO;
void BFS(int s) {
	queue<int> q;
	q.push(s), len[s] = 0;
    sum=cost[s];
	while(!q.empty()) {
            int cur = q.front(); q.pop();
			fvec(i, adjList[cur])
			    if (len[i] == OO){
				q.push(i); len[i] =len[cur]+1;
                sum=min(sum,cost[i]);
                }
	}
}

int main()
{

        //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n,m;cin>>n>>m;
        fp(i,1,n)cin>>cost[i];
        fo(i,m){
            int u,v;cin>>u>>v;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }
        ll re=0;
        fp(i,1,n){
            if(len[i]==OO){
                BFS(i);
                re+=sum;
                sum=OO;
            }
        }
        cout<<re;
}
