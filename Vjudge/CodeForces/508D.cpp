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
const ll OO = 1e5, mod = 1e9 + 7, N = 2e5+5;
map<string,ll> in, out;
map<string,vector < string >> g;
string ans;
void dfs( string node)
{
    while(!g[node].empty())
    {
        string v = g[node].back();
        g[node].pop_back();
        dfs(v);
    }
    ans.push_back(node[1]);
}
 void testCase()
{
    int n;cin>>n;
        if(n==1){
            cout<<"YES\n";
            string str;cin>>str;
            cout<<str<<'\n';
            return;
        }

    for ( int i = 0 ; i < n ; i++)
    {
        string str;cin>>str;
        string u=str.substr(0,2),v=str.substr(1,2);//cout<<u<<" "<<v<<'\n';
        g[u].push_back(v);
        out[u]++;in[v]++;
    }

    int incount=0,outcount=0;
    string start="";
    fvec(item,g)
    {
        string str=item.first;
        if(in[str]==out[str]+1){
                incount++;
               // start=str;
        }else if(in[str]+1==out[str]){
            outcount++;
            start=str;
           // cout<<str<<'\n';
        }
        else if(in[str] != out[str])
        {
            cout << "NO\n";
            return;
        }
        if(incount>1||outcount>1){
            cout << "NO\n";
            return;
        }
    }
    if(start==""){
        fvec(item,in)
        {
            string str=item.first;
            if(in[str]==out[str]){
                start=str;break;
            }
        }
    }
  //  cout<<start<<'\n';
    dfs(start);
    ans.pb(start[0]);
    reverse(all(ans));
    if(ans.size() != n+2)
    {
        cout << "NO\n";
        return;
    }
    cout<<"YES\n";
    cout<<ans;
    cout << '\n';
}
int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
    testCase();
}
