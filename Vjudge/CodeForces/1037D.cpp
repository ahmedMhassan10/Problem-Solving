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
const ll OO =10e7;
#define mine(x,y,z) min(x,min(y,z))
#define maxe(x,y,z) max(x,min(y,z))

map<ll,vector<int>>adjList;
vector<int> BFS2(int s,int num) {
	vector<int> len(num+1, OO);
	queue<int> q;
	q.push(s), len[s] = 0;

	int cur = s;
	while(!q.empty()) {

			cur = q.front(), q.pop();
			rep(i, adjList[cur])
			    if (len[adjList[cur][i]] == OO){
				q.push(adjList[cur][i]); len[adjList[cur][i]] =cur;}
	}
	return len;	//cur is the furthest node from s with depth dep && dep is the depth of it
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int num;cin>>num;
        fo(i,num-1){
            int u,v;cin>>u>>v;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }
        queue<int>q1,q2;
        for(int i=0;i<num;i++){
            int item;cin>>item;
            q1.push(item);
        }
        vector<int>len=BFS2(1,num);
        bool tr=true;
        q2.push(q1.front());q1.pop();
        if(len[q2.front()]!=0)tr=false;
        int siz=sz(adjList[q2.front()]);
        while(!q1.empty()&&tr){
                while(siz--){
                    if(len[q1.front()]!=q2.front()){tr=false;//break;
                    }
                    else {
                        q2.push(q1.front());q1.pop();
                    }
                }
                q2.pop();
                siz=sz(adjList[q2.front()])-1;

        }
        if(tr)cout<<"YES\n";
        else cout<<"NO\n";
}

