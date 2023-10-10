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
vector<ll> len(N, OO);
set<int>se;
void BFS(int s) {
	queue<int> q;
	q.push(s), len[s] = 0;
	while(!q.empty()) {
            int cur = q.front(); q.pop();
            se.insert(len[cur]);
			fvec(i, adjList[cur])
			    if (len[i] == OO){
                    q.push(i); len[i] =len[cur]+1;
				}
	}
}
int main() {
        // freopen("survive.in "," r ",stdin);
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        ll num;cin>>num;
        vll vec;
        fp(i,1,num){
            ll temp;
            cin>>temp;
            if(temp==-1)vec.pb(i);
            else{
                adjList[temp].pb(i);
                adjList[i].pb(temp);
            }
        }
        fvec(item,vec){
            BFS(item);
        }
        cout<<se.size()<<'\n';
}
