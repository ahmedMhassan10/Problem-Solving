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
const ll OO = 1e9, mod = 1e9 + 7,mod2=1e9+9, N =1000 +5,M=23;

int par[N], sz[N];
void init(int n)
{
    for ( int i = 1 ; i <= n ;i++)
        par[i] = i , sz[i] = 1;
}
// O(n) ---> O(n ^ 2)
int findparent( int u)
{
    if(par[u] == u)
        return  u;
    return par[u] = findparent(par[u]);
}
bool iscyclic = false;
void connect( int u , int v)
{
    u = findparent(u);
    v = findparent(v);
    if ( u == v)
    {
        iscyclic =true;
        return;
    }
    if(sz[v] < sz[u])
        par[v] = u ,sz[u] += sz[v];
    else
        par[u] = v,sz[v] += sz[u];
}
bool isconnected( int u , int v)
{
    return (findparent(u) == findparent(v));
}
int main() {
        //freopen("input.txt","rt",stdin);
        //freopen("output.txt","wt",stdout);
        ll n;cin>>n;
        init(27);
        map<char,bool>ma;
        fo(i,n){
            string str;cin>>str;
            char ch=str.back();
            fvec(item,str){
                ma[item]=1;
                if(isconnected(item-'a',ch-'a'))continue;
                connect(item-'a',ch-'a');
            }
        }
        set<int>s;
        fvec(item,ma){
            s.insert(findparent(item.F-'a'));
        }
        cout<<s.size();
}
