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

ll seg[N<<2];
ll arr[N];
ll num;
ll sum[N<<2], suff[N<<2], pref[N<<2];
void Build_seg(ll node,ll l , ll r) {
    if (l == r) {
        seg[node] = arr[l];
        pref[node]=arr[l];
        sum[node] = arr[l];
        suff[node]=arr[l];
        return;
    }
    ll mid = (l + r) / 2;
    Build_seg(node * 2, l, mid);
    Build_seg(node * 2 + 1, mid + 1, r);
    ll n=node;
    pref[node] = max(pref[2 * n], sum[2 * n] + pref[2 * n + 1]);
    suff[node] = max(suff[2 * n + 1], suff[2 * n] + sum[2 * n + 1]);
    seg[node] = max(seg[2 * n], max(seg[2 * n + 1], suff[2 * n] + pref[2 * n + 1]));
    sum[node] = sum[2 * n] + sum[2 * n + 1];
}
void update(ll node,ll l ,ll r,ll idx,ll val) {
    if (l == r) {
        seg[node] =val;
        pref[node]=val;
        sum[node] = val;
        suff[node]=val;
        return;
    }
    ll mid = (l + r) / 2;
    if (idx <= mid) update(node * 2, l, mid, idx,val);
    else update(node * 2 + 1, mid + 1, r, idx,val);
    ll n=node;
    pref[node] = max(pref[2 * n], sum[2 * n] + pref[2 * n + 1]);
    suff[node] = max(suff[2 * n + 1], suff[2 * n] + sum[2 * n + 1]);
    seg[node] = max(seg[2 * n], max(seg[2 * n + 1], suff[2 * n] + pref[2 * n + 1]));
    sum[node] = sum[2 * n] + sum[2 * n + 1];

}
ll query(ll node,ll l ,ll r,ll st,ll en) {
    if(l>en || r<st){
        return 0;
    }
    if(l>=st && r<=en){
        return seg[node];
    }
    ll md= (l+r)/2 ;
    return (query(node*2,l,md,st,en)+query(node*2+1,md+1,r,st,en));
}
void solve(int inde) {
    ll q;
    cin>>num>>q;
    fp(i,1,num)cin>>arr[i];
    Build_seg(1,1,num);
    while (q--){
        ll u,v;cin>>u>>v;
        update(1,1,num,u,v);
        cout<<max((ll)0,query(1,1,num,1,num))<<'\n';
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
