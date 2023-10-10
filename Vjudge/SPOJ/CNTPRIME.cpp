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
const ll OO = 1e10, mod = 1e9 + 7,mod2=1e9+9, N =2e4 +5,M=23;
ll tree[N<<2], a[N], lazy[N<<2];
ll num,q;
bool prime[(ll)(1e6+5)];

void build( int node , int l , int r)
{
    lazy[node]=0;
    if( l == r)
   {
       tree[node]=prime[a[l]];
       return ;
   }
    int md = l + r >> 1 ;
    build(node<<1,l,md),build(node<<1|1,md+1,r);
    tree[node] = tree[node<<1] + tree[node<<1|1];
}

void propagate( int node , int l , int r )
{
    if(lazy[node] == 0)
        return;
    tree[node] = prime[lazy[node]]* (r- l + 1);
    if(l != r) {
        lazy[node << 1] = lazy[node];
        lazy[node << 1 | 1] = lazy[node];
    }
    lazy[node] = 0;
}

void update( int node , int l , int r , int s , int e , int val)
{
    propagate(node,l,r);
    if ( l > e || r < s)
        return ;
    if ( l >= s and r <= e)
    {
        lazy[node] = val;
        propagate( node , l, r);
        return;
    }
    int md = l + r >> 1 ;
    update(node<<1,l,md,s,e,val),update(node<<1|1,md+1,r,s,e,val);
    tree[node] = tree[node<<1] + tree[node<<1|1];
}

ll query( int node , int l , int r , int s , int e)
{
    propagate(node,l,r);
    if ( l > e || r < s)
        return 0;
    if ( l >= s and r <= e)
        return tree[node];
    int md = l + r >> 1 ;
    return query(node<<1,l,md,s,e)+query(node<<1|1,md+1,r,s,e);
}

int main() {
        // freopen("survive.in "," r ",stdin);
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int n = 1e6+2;
        memset(prime , true, sizeof prime );
        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= n; i++)
        if ( prime[i])
        for (int j = i * i; j <= n; j += i)
        prime[j] = false;
        int t;cin>>t;
        fp(ll,1,t){
            cout<<"Case "<<ll<<":\n";
            cin>>num>>q;
            fp(i,1,num)cin>>a[i];
            build(1,1,num);
            while(q--){
                int tt,u,v;
                cin>>tt>>u>>v;
                if(tt==0){
                    int kk;
                    cin>>kk;
                    update(1,1,num,u,v,kk);
                }else{
                    cout<<query(1,1,num,u,v)<<"\n";
                }
            }
        }
}
