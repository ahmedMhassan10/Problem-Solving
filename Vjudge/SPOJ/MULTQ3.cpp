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
const ll OO = 1e10, mod = 1e9 + 7,mod2=1e9+9, N =100000 +5,M=23;
ll tree[N<<2][3], a[N], lazy[N<<2];
ll num,q;
void build( int node , int l , int r)
{
    lazy[node]=0;
    if( l == r)
   {
       tree[node][0]=0;
       tree[node][1]=0;
       tree[node][2]=0;
        tree[node][a[l]%3]++;
       return ;
   }
    int md = l + r >> 1 ;
    build(node<<1,l,md),build(node<<1|1,md+1,r);
    tree[node][0] = tree[node<<1][0] + tree[node<<1|1][0];
    tree[node][1] = tree[node<<1][1] + tree[node<<1|1][1];
    tree[node][2] = tree[node<<1][2] + tree[node<<1|1][2];

}

void propagate( int node , int l , int r )
{
    if(lazy[node] == 0)
        return;
    ll one=tree[node][0],two=tree[node][1],three=tree[node][2];
    tree[node][(0+lazy[node])%3]=one;

    tree[node][(1+lazy[node])%3]=two;

    tree[node][(2+lazy[node])%3]=three;
    if(l != r) {
        lazy[node << 1] += lazy[node];
        lazy[node << 1 | 1] += lazy[node];
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
    tree[node][0] = tree[node<<1][0] + tree[node<<1|1][0];
    tree[node][1] = tree[node<<1][1] + tree[node<<1|1][1];
    tree[node][2] = tree[node<<1][2] + tree[node<<1|1][2];
}

ll query( int node , int l , int r , int s , int e)
{
    propagate(node,l,r);
    if ( l > e || r < s)
        return 0;
    if ( l >= s and r <= e)
        return tree[node][0];
    int md = l + r >> 1 ;
    return query(node<<1,l,md,s,e)+query(node<<1|1,md+1,r,s,e);
}

int main() {
        // freopen("survive.in "," r ",stdin);
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        cin>>num>>q;
        fp(i,1,num)a[i]=0;
        build(1,1,num);
        while(q--){
            ll t,u,v;cin>>t>>u>>v;
            u++,v++;
            if(t==0){
                update(1,1,num,u,v,1);
            }else{
                cout<<query(1,1,num,u,v)<<"\n";
            }
        }
}
