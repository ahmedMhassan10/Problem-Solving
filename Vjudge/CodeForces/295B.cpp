#include <bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()), ((v).end())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < sz(v); ++i)
#define fo(i, n) for (int i = 0; i < (int)(n); ++i)
#define fp(i, j, n) for (int i = (j); i <= (int)(n); ++i)
#define fn(i, j, n) for (int i = (j); i >= (int)(n); --i)
#define fvec(i, vec) for (auto i : vec)
#define pb push_back
#define MP make_pair
#define mine(x, y, z) min(x, min(y, z))
#define maxe(x, y, z) max(x, min(y, z))
#define F first
#define S second
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef unsigned long long ull;
typedef long long ll;
const ll OO = 1e16, mod = 1e9 + 7, N = 505;

ll dist[N][N], n, cost[N][N];
void floyed_warshal() {
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}
ull getsum() {
  ull sum = 0;
  fp(i, 1, n) {
    fp(j, 1, n) {
      if (dist[i][j] != OO)
        sum += dist[i][j];
    }
  }
  return sum;
}
void testcase() {
  cin >> n;
  fp(i, 1, n) {
    fp(j, 1, n) {
        if(i!=j)dist[i][j]=OO;
         cin >> cost[i][j]; }
  }

stack<int>vec;
  vector<ll>re;

  fo(cc,n){
    int item;cin>>item;vec.push(item);
  }

map<ll,bool>mcount;

   for(int mm=1;mm<=n;mm++){
        int item=vec.top();vec.pop();
        mcount[item]=true;
        fp(i,1,n){
            if(!mcount[i])continue;
            if(dist[i][item]>cost[i][item]){dist[i][item]=cost[i][item];
            }
            if(dist[item][i]>cost[item][i]){dist[item][i]=cost[item][i];
            }
        }
        fp(i,1,n){
            fp(j,1,n){
                dist[i][j]=min(dist[i][j],dist[i][item]+dist[item][j]);
                dist[i][item]=min(dist[i][item],dist[i][j]+dist[j][item]);
                dist[item][j]=min(dist[item][j],dist[item][i]+dist[i][j]);
            }
        }
        fp(i,1,n){
            fp(j,1,n){
                dist[i][j]=min(dist[i][j],dist[i][item]+dist[item][j]);
                dist[i][item]=min(dist[i][item],dist[i][j]+dist[j][item]);
                dist[item][j]=min(dist[item][j],dist[item][i]+dist[i][j]);
            }
        }
        re.pb(getsum());
   }
   reverse(all(re));
   fvec(item2,re)cout<<item2<<" ";
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  testcase();
}
