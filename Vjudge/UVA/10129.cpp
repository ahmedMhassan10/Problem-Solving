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
const ll OO = 1e16, mod = 1e9 + 7, N = 100000+5;


int in[N], out[N],n=26,m;
vector < int > g[N];
vector < bool > vis(N);
void dfs( int node)
{
        vis[node]=true;
        fvec(item,g[node]){
            if(!vis[item])
                dfs(item);
        }
}
 void testCase()
{
    clr(g,{});
    clr(in,0);clr(out,0);vis.clear();
    cin >> m;
    int counter=0;
    set<int>s;   int outc=0,inc=0,indexfirst=-1,indexlast=0;
    for ( int i = 0 ; i < m ; i++)
    {
        int u, v;
        string str;cin>>str;
        u=str[0]-'a',v=str[siz(str)-1]-'a';
        s.insert(u);s.insert(v);
        if(u==v)counter++;
        g[u].push_back(v);
        out[u]++,in[v]++;
    }
    fvec(i,s )
    {
        if(in[i] == out[i]){
            if(indexfirst==-1)indexfirst=i;
        }
        else if(in[i]==out[i]+1){inc++;}
        else if(out[i]==in[i]+1){outc++;indexfirst=i;}
        else{
            cout<<"The door cannot be opened.";
            return;
        }

    }
    if(inc>1||outc>1)
    {
        cout << "The door cannot be opened.";
        return;
    }
    dfs(indexfirst);
    fvec(item,s){
        if(!vis[item]){
            cout << "The door cannot be opened.";
            return;
        }

    }
    cout<<"Ordering is possible.";
}
int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;cin>>t;
  while(t--){
        testCase();
        cout<<"\n";
  }
}

