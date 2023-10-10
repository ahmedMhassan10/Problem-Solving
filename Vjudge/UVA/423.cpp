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
const ll OO = 1e18, mod = 1e9+7,mod2=1e9+9, N =200,M=23;
ll dist[N] , n,m;
vector < pair < int , pair < ll, ll> > > edges;
bool negCycle = false;
ll maxi=-OO;
void Bellman_Ford( ll  src)
{
    for ( int i = 1 ; i <= n ; i++)
        dist[i] = OO;
    dist[src] = 0;
    // O(n * m)
    for(int i= 1 ; i<= n ; i++) {
        for(int j = 0; j < edges.size(); j++) {
            int u = edges[j].S.F, v = edges[j].S.S, w = edges[j].F;
            if (dist[u] + w < dist[v])
            {
                if(i == n)
                    negCycle = true;
                dist[v] = dist[u] + w;
            }
        }
    }
}

void testcase(){
    cin >> n ;
    for ( int i = 1 ; i <= n ; i++)
    {
        fp(j,1,i-1){
        string w;
        cin >>w;
        if(w=="x")continue;
        edges.push_back({stoll(w),{i,j}});
        edges.push_back({stoll(w),{j,i}});

        }
    }
    Bellman_Ford(1);
    fp(i,1,n)maxi=max(maxi,dist[i]);
    cout<<maxi<<'\n';
}
int main() {
        //freopen("input.txt","rt",stdin);
        //freopen("output.txt","wt",stdout);
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        testcase();
}
