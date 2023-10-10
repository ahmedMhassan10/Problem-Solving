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
const ll OO = 1e9, mod = 1e9+7,mod2=1e9+9, N =1000,M=23;
ll n,k;
vector<ll>dist(N,OO);
vector < pair < ll, ll> > g[N];

void Dijkstra( ll src)
{
    dist[src] = 0;
    priority_queue< pair < ll, ll> > pq;
    pq.push({0,src});
    while(!pq.empty())
    {
        ll node = pq.top().second , distance = -pq.top().first;
        pq.pop();
        if(distance > dist[node])
            continue;
        for(auto ch : g[node])
        {
           // cout<<ch.F<<" "<<ch.S<<"\n";

            if(dist[node] + ch.second+60*(node>0) < dist[ch.first])
            {
                dist[ch.first] = dist[node] + ch.second+60*(node>0);
                pq.push({-dist[ch.first],ch.first});
            }
        }
    }
}
int main() {
        //freopen("input.txt","rt",stdin);
        //freopen("output.txt","wt",stdout);
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        while(cin>>n>>k){
            if(n+k==0)break;
            fp(i,0,N){
                g[i].clear();
                dist[i]=OO;
            }
            vll vec(n);
            fp(i,0,n-1)cin>>vec[i];
            cin.ignore();
            fp(kk,0,n-1){
                vll stages;
                string st;
                getline(cin,st);
                stringstream ss(st);
                ll x;
                while(ss>>x)stages.pb(x);
               // fvec(item,stages)cout<<item<<'\n';
                fp(i,0,siz(stages)-1){
                    fp(j,i+1,siz(stages)-1){
                        g[stages[i]].pb({stages[j],abs(stages[j]-stages[i])*vec[kk]});
                        g[stages[j]].pb({stages[i],abs(stages[j]-stages[i])*vec[kk]});
                        //cout<<g[stages[i]].back().S<<'\n';
                    }
                }
            }
            Dijkstra(0);
            if(dist[k]==OO)cout<<"IMPOSSIBLE\n";
            else cout<<dist[k]<<'\n';
        }
}
