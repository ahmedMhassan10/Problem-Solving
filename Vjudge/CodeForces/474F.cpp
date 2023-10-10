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
const ll OO = 1e9, mod = 1e9 + 7,mod2=1e9+9, N =2e5+5,M=25;
ll seg[N<<2];
ll arr[N];
ll num;
void Build_seg(ll node,ll l , ll r) {
    if (l == r) {
        seg[node] = arr[l];
        return;
    }
    ll mid = (l + r) / 2;
    Build_seg(node * 2, l, mid);
    Build_seg(node * 2 + 1, mid + 1, r);
    seg[node] = gcd(seg[node * 2] , seg[node * 2 + 1]);
}
void update(ll node,ll l ,ll r,ll idx,ll val) {
    if (l == r) {
        seg[node] = val;
        return;
    }
    ll mid = (l + r) / 2;
    if (idx <= mid) update(node * 2, l, mid, idx,val);
    else update(node * 2 + 1, mid + 1, r, idx,val);
    seg[node] = gcd(seg[node * 2] , seg[node * 2 + 1]);
}
ll query(ll node,ll l ,ll r,ll st,ll en) {
       if(l>en || r<st){
        return 0;
       }
       if(l>=st && r<=en){
             return seg[node];
       }
       ll md= (l+r)/2 ;
       return gcd(query(node*2,l,md,st,en),query(node*2+1,md+1,r,st,en));
}

int main() {
        // freopen("survive.in "," r ",stdin);
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        cin>>num;
        map<ll,vector<ll>>ma;
        fp(i,1,num){
            cin>>arr[i];
            ma[arr[i]].pb(i);
        }
        Build_seg(1,1,num);
        ll q;cin>>q;
        while(q--){
            int l,r;cin>>l>>r;
            ll re=query(1,1,num,l,r);
            if(ma.count(re)==0)cout<<r-l+1<<'\n';
            else {
                cout<<r-l+1- (upper_bound(all(ma[re]),r)-lower_bound(all(ma[re]),l))<<'\n';
            }
        }
}
