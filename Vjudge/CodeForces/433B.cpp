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
const ll OO = 1e5, mod = 1e9 + 7, N = 1e5;
int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll num;cin>>num;
  vector<ll>vec(num+1),vec2(num+1);
  for(int i=1;i<=num;i++){
    cin>>vec[i];
    vec2[i]=vec[i];
  }
  sort(all(vec2));
  fp(i,1,num-1){
    vec[i+1]+=vec[i];
    vec2[i+1]+=vec2[i];
  }
  int q;cin>>q;
  while(q--){
    int u,v,w;cin>>u>>v>>w;
    if(u==1){
            cout<<vec[w]-vec[v-1]<<'\n';
    }else{
            cout<<vec2[w]-vec2[v-1]<<'\n';

    }
  }
}
