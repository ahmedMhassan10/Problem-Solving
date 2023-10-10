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
const ll OO = 1e9, mod = 1e9+7,mod2=1e9+9, N =100+5,M=23;
ll dist[N+2][N+2];
set<int>nuu;
void floyed_warshal(){
	for (int k = 1; k <= N; ++k) {
  	  for (int i = 1; i <= N; ++i) {
       		 for (int j = 1; j <= N; ++j) {
           		 dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        	}
    	   }
	}
}

int inde=1;
void testcase(){ll u,v;
	while(cin>>u>>v){

		if(u==0&&v==0)break;
		nuu.insert(u);
		nuu.insert(v);
		dist[u][v]=1;
	}
	floyed_warshal();
    ll sum=0,counter=nuu.size()*(nuu.size()-1);
    fp(i,1,N){
        fp(j,1,N){
            if(dist[i][j]==OO)continue;
            sum+=dist[i][j];
        }
    }
    setp(3);
    cout<<"Case "<<inde++<<": average length between pages = "<<(double)sum/counter<<" clicks\n";
}

int main() {
        //freopen("input.txt","rt",stdin);
        //freopen("output.txt","wt",stdout);
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        ll ss,ee;
        while(cin>>ss>>ee){
            if(ss== 0 && ee== 0)
               break;
                nuu.clear();
            	for(int i=0;i<=N;i++)
                    for(int j=0;j<=N;j++)
                      if(i!=j)
                        dist[i][j]=OO;
                      else dist[i][j]=0;

            nuu.insert(ss);
            nuu.insert(ee);
            dist[ss][ee]=1;
            testcase();
        }
}
