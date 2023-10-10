#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v) ((v).begin()), ((v).end())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < siz(v); ++i)
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
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;

typedef vector<pll> vp;
typedef vector< long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef tree< pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define setp(item) cout<<fixed<<setprecision(item);
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO =LLONG_MAX, mod = 1e9+7,mod2=1e9+9, N =2e5+5,M=30,MOD=998244353, minOO=LLONG_MIN;
///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة
ll seg[N<<2], a[N], lazy[N<<2];
void build( int node , int l , int r)
{
    lazy[node]=0;
    if( l == r)
    {
        seg[node]=a[l];
        return ;
    }
    int md = l + r >> 1 ;
    build(node<<1,l,md),build(node<<1|1,md+1,r);
    seg[node] = max(seg[node<<1] , seg[node<<1|1]);
}

void propagate( int node , int l , int r )
{
    if(lazy[node] == 0)
        return;
    seg[node] += lazy[node];
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
    seg[node] = max(seg[node<<1] , seg[node<<1|1]);
}

ll query( int node , int l , int r , int s , int e)
{
    propagate(node,l,r);
    if ( l > e || r < s)
        return -OO;
    if ( l >= s and r <= e)
        return seg[node];
    int md = l + r >> 1 ;
    return max(query(node<<1,l,md,s,e),query(node<<1|1,md+1,r,s,e));
}
void solve(int inde) {
    ll num,q;cin>>num>>q;
    vll vec(num+1);
    fp(i,1,num){
        cin>>a[i];
        vec[i]=a[i];
    }

    fp(i,2,num){
        a[i]+=a[i-1];
    }
    build(1,1,num);
    while (q--){
        ll t,u,v;cin>>t>>u>>v;
        if(t==1){
            update(1,1,num,u,num,v-vec[u]);
            vec[u]=v;
        }else{
            ll st=0;
            if(u==1)st=0;
            else{st=query(1,1,num,u-1,u-1);}
            cout<<max((ll)0,query(1,1,num,u,v)- st)<<'\n';
        }
    }
}

int main() {
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
//    cin>>t;
    ll index=1;
    while (t--){
        solve(index++);
    }
    return 0;
}
