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
const ll OO = 1e18, mod = 1e9+7,mod2=1e9+9, N =1e6+4,M=23;
map<ll, vector < pair<ll,ll> > >adj;
map<ll,bool> vis;

vector<pair<ll,pair<ll,ll>>> vec;
void dfs( int node)
{
    vis[node] = true;
    for ( auto chi : adj[node])
    {
        ll child=chi.F,color=chi.S;
        if(vis[child] == false)
        {
            vec.pb({node,chi});
            dfs(child);
        }
    }
}

int main() {
        //freopen("input.txt","rt",stdin);
        //freopen("output.txt","wt",stdout);
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        map<ll,vector<ll>>ma;
        ll num;cin>>num;
        fp(i,1,num){
            ll nu;cin>>nu;
            fo(j,nu){
                ll color;cin>>color;
                ma[color].pb(i);
            }
        }
        fvec(item,ma){
                ll  nn=item.S[0];
                fp(j,1,siz(item.S)-1){
                    adj[item.S[0]].pb({item.S[j],item.F});
                    adj[item.S[j]].pb({item.S[0],item.F});

                }

        }
        dfs(1);
        fp(i,1,num){
            if(!vis[i]){
                cout<<"impossible";return 0;
            }
        }
        fvec(item,vec){
            cout<<item.F<<" "<<item.S.F<<" "<<item.S.S<<'\n';
        }
}

