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
const ll OO = 1e9, mod = 1e9+7,mod2=1e9+9, N =20000+5 ,M=23;
vector<int>dx={1,2,-1,-2,1,2,-1,-2};
vector<int>dy={2,1,2,1,-2,-1,-2,-1};
ll dist[8][8];
ll x1,x2,yt,y2;

void Dijkstra( ll x,ll y)
{
    fo(i,8)fo(j,8)dist[i][j]=OO;
    dist[x][y] = 0;
                    //  distance node
    priority_queue< pair<ll, pair< ll, ll>> > pq;
    pq.push({0,{x,y}});
    while(!pq.empty())
    {
        pair<ll,ll> node = pq.top().second ; ll distance = -pq.top().first;
        pq.pop();
        if(node.F==x2&&node.S==y2)break;
        if(distance > dist[node.F][node.S])
            continue;
        fo(i,8)
        {
            ll xx=node.F+dx[i],yy=node.S+dy[i];
            if(xx<0||xx>7||yy<0||yy>7)continue;

            if(dist[node.F][node.S] +xx*node.F+yy*node.S  < dist[xx][yy])
            {
                dist[xx][yy] = dist[node.F][node.S] + xx*node.F+yy*node.S;
                pq.push({-dist[xx][yy],{xx,yy}});
            }
        }
    }
}
int main() {
        //freopen("input.txt","rt",stdin);
        //freopen("output.txt","wt",stdout);
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        while(cin>>x1>>yt>>x2>>y2){
            if(x1==-1)break;
            Dijkstra(x1,yt);
            if(dist[x2][y2]==OO)cout<<-1<<'\n';
            else
            cout<<dist[x2][y2]<<'\n';
        }
}
