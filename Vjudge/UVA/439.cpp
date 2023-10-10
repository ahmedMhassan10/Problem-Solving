#include <bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()), ((v).end())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < sz(v); ++i)
#define fo(i, n) for (int i = 0; i < (int)(n); ++i)
#define fp(i, j, n) for (long long i = (j); i <= (long long)(n); ++i)
#define fn(i, j, n) for (int i = (j); i >= (int)(n); --i)
#define fvec(i, vec) for (auto i : vec)
#define pb push_back
#define MP make_pair
#define mine(x, y, z) min(x, min(y, z))
#define maxe(x, y, z) max(x, max(y, z))
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<pair<ll,ll>> vp;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
#define setp(item) cout<<fixed<<setprecision(item);
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO = 1e10, mod = 1e9 + 7,mod2=1e9+9, N =1e5 +5,M=23;
map<ll,vector<int>>adjList;
map<pair<int,int>,int> len;
vector<int>dx={1,2,-1,-2,1,2,-1,-2};
vector<int>dy={2,1,2,1,-2,-1,-2,-1};
void BFS(int x,int y) {
	queue<pair<int,int>> q;
	q.push({x,y}), len[{x,y}] = 1;
	while(!q.empty()) {
            pair<int,int> cur = q.front(); q.pop();
			fo(i,8){
                ll xx=cur.F+dx[i],yy=cur.S+dy[i];
                if(xx>8||xx<1||yy>8||yy<1)continue;
			    if (len[{xx,yy}] == 0){
				q.push({xx,yy}); len[{xx,yy}] =len[cur]+1;}
			}
	}
}
int main() {
        // freopen("survive.in "," r ",stdin);
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        string str1,str2;
        while(cin>>str1>>str2){
            if(str1=="1")break;
            pair<int,int>st={str1[0]-'a'+1,str1[1]-'0'},en={str2[0]-'a'+1,str2[1]-'0'};
            BFS(st.F,st.S);
            cout<<"To get from "<<str1<<" to "<<str2<<" takes "<<len[en]-1<<" knight moves.\n";
            len.clear();
        }
}
