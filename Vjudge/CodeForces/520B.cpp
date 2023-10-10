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
map<ll,vector<int>>adjlist;
int BFS2(int s, int m) {
	vector<ll> len(20005, OO);
	queue<int> q;
	q.push(s); len[s] = 0;
	int  cur = s;
	while(!q.empty()) {
			cur = q.front(), q.pop();
			int s1=2*cur,s2=cur-1;
			if(s1<20005&&len[s1]==OO){len[s1]=len[cur]+1;q.push(s1);}
			if(s2>0&&len[s2]==OO){len[s2]=len[cur]+1;q.push(s2);}

            if(len[m]!=OO)break;
	}
	return len[m];	//cur is the furthest node from s with depth dep && dep is the depth of it
}
int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n,m;cin>>n>>m;
        int re=BFS2(n,m);
        cout<<re;
}

