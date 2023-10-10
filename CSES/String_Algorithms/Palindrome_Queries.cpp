#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")

#define clr(v, d)			memset(v, d, sizeof(v))
#define ll long long
#define int long long
typedef tree< pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define setP(item) cout<<fixed<<setprecision(item);
int ceilSqrt(int a){
    return ::ceil(sqrtl(a));
}
int  divC(int a,int b){
    return a/b+(a%b!=0);
}
int gcd(int a, int b) { return ((b == 0) ? a : gcd(b, a % b)); }
int lcm(int a,int b){return (a*b)/gcd(a,b);}
const ll OO =1e18+10, mod = 1e9+7,mod2=1e9+9,  N=2e5+5,M=25,MOD= 998244353, minOO=LLONG_MIN;
const double EPS=1e-10;
const double PI=acos(-1);
const ll maximum=2500+6;
const int NOT_VISITED = -1;
vector<int>  pw(N);
vector<int> inv(N);

ll add(ll a, ll b) {
    return ((a % mod + b % mod) + mod) % mod;
}

ll mul(ll a, ll b) {
    return ((a % mod * b % mod) + mod) % mod;
}

ll minu(ll a, ll b) {
    return ((a % mod - b % mod) + mod) % mod;
}

ll fastp(ll a, ll b) {
    if (b == 0)return (1);
    ll temp = fastp(a, b / 2);
    ll total = mul(temp, temp);
    if (b % 2 == 1) {
        total = mul(total, a);
    }
    return total;
}

void pre() {
    pw[0] = 1;
    inv[0] = 1;
    ll mul_inv = fastp(29, mod - 2);
    for (int i = 1; i < N; ++i) {
        pw[i] = mul(pw[i - 1], 29);
        inv[i] = mul(inv[i - 1], mul_inv);
    }
}

void make_hash(string &x, vector<int>  &prifx ) {
    for (int i = 1; i < x.size(); ++i) {
        ll ind = x[i] - 'a' + 1;
        prifx[i] = mul(ind, pw[i]);
    }
}

void Build_seg(ll node,ll l , ll r,vector<int>&seg,vector<int>&arr) {// DONT FORGET BUILD IN MAIN YA 7OMAR
    if (l == r) {
        seg[node] = arr[l];
        return;
    }
    ll mid = (l + r) / 2;
    Build_seg(node * 2, l, mid,seg,arr);
    Build_seg(node * 2 + 1, mid + 1, r,seg,arr);
    seg[node] = add(seg[node * 2] , seg[node * 2 + 1]);// DONT FORGET BUILD IN MAIN YA 7OMAR
}
void update(ll node,ll l ,ll r,ll idx,ll val,vector<int>&seg,vector<int>&arr) {// DONT FORGET BUILD IN MAIN YA 7OMAR
    if (l == r) {
        seg[node] = val;
        arr[l]=val;
        return;
    }
    ll mid = (l + r) / 2;
    if (idx <= mid) update(node * 2, l, mid, idx,val,seg,arr);
    else update(node * 2 + 1, mid + 1, r, idx,val,seg,arr);
    seg[node] = add(seg[node * 2] , seg[node * 2 + 1]);// DONT FORGET BUILD IN MAIN YA 7OMAR
}
ll query(ll node,ll l ,ll r,ll st,ll en,vector<int>&seg) {// DONT FORGET BUILD IN MAIN YA 7OMAR
    if(l>en || r<st){
        return 0;
    }
    if(l>=st && r<=en){
        return seg[node];
    }
    ll md= (l+r)/2 ;
    return add(query(node*2,l,md,st,en,seg),query(node*2+1,md+1,r,st,en,seg));// DONT FORGET BUILD IN MAIN YA 7OMAR
}
ll n,q;

ll get_value(ll st, ll en, vector<int>  &seg) {

    return mul(query(1,1,n,st,en,seg),inv[st]);

}
ll getRev(int idx){
    return n-idx;
}
void func(int index){
    cin>>n>>q;
    pre();
    string str;cin>>str;
    string s1="#"+str;
    n=s1.size();
    vector<int>a1(n),a2(n);
    make_hash(s1,a1);
    reverse(str.begin(),str.end());
    str="#"+str;
    make_hash(str,a2);
    vector<int>seg1(N<<2),seg2(N<<2);
    Build_seg(1,1,n,seg1,a1);
    Build_seg(1,1,n,seg2,a2);
    for (int i = 0; i < q; ++i) {
        ll t;cin>>t;
        if(t==1){
            ll idx;char ch;cin>>idx>>ch;
            update(1,1,n,idx,mul(pw[idx],ch-'a'+1),seg1,a1);
            update(1,1,n, getRev(idx),mul(pw[getRev(idx)],ch-'a'+1),seg2,a2);
        }else {
            ll st,en;cin>>st>>en;
            ll v1= getRev(st),v2= getRev(en);
            ll val=   get_value(st,en,seg1);
            ll val2=  get_value(getRev(en), getRev(st),seg2);
            if(val==val2){
                cout<<"YES\n";
            }else
                cout<<"NO\n";
        }

    }
}

signed main() {
//    freopen("ysys.in","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
//    cin>>t;
    ll index=1;
    while (t--){
        func(index++);
    }
    return 0;
}