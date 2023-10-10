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
const ll OO =1e18, mod = 1e9+7,mod2=1e9+9, N =4e5+5,M=30,MOD=998244353, minOO=LLONG_MIN;
ll seg[N<<2];
ll arr[N];
void update(ll node,ll l ,ll r,ll idx,ll val) {// DONT FORGET BUILD IN MAIN YA 7OMAR
    if (l == r) {
        seg[node] = val;
        arr[l]=val;
        return;
    }
    ll mid = (l + r) / 2;
    if (idx <= mid) update(node * 2, l, mid, idx,val);
    else update(node * 2 + 1, mid + 1, r, idx,val);
    seg[node] = max(seg[node * 2] , seg[node * 2 + 1]);// DONT FORGET BUILD IN MAIN YA 7OMAR
}
ll query(ll node,ll l ,ll r,ll st,ll en) {// DONT FORGET BUILD IN MAIN YA 7OMAR
    if(l>en || r<st){
        return 0;
    }
    if(l>=st && r<=en){
        return seg[node];
    }
    ll md= (l+r)/2 ;
    return max(query(node*2,l,md,st,en),query(node*2+1,md+1,r,st,en));// DONT FORGET BUILD IN MAIN YA 7OMAR
}
void func(int index) {
    ll num;cin>>num;
    set<ll>se;
    vector<pair<ll,pll>>vec(num);
    fo(i,num){
        cin>>vec[i].F>>vec[i].S.F>>vec[i].S.S;
        se.insert(vec[i].F);
        se.insert(vec[i].S.F);
    }
    ll ind=2;
    map<ll,ll>ma;
    fvec(item,se){
        ma[item]=ind++;
    }
    fo(i,num){
        vec[i].F=ma[vec[i].F];
        vec[i].S.F=ma[vec[i].S.F];
    }
    sort(all(vec));
    fo(i,num){
        auto item=vec[i];
        ll st=item.F,en=item.S.F,value=item.S.S;
        ll q= query(1,1,ind,1,st-1);
        ll qq=arr[en];
        if(q+value>qq)
            update(1,1,ind,en,q+value);
    }
    cout<<query(1,1,ind,1,ind);


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
        func(index++);
    }
    return 0;
}