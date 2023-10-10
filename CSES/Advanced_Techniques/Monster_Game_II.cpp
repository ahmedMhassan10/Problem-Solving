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
const ll OO =1e18, mod = 1e9+7,mod2=1e9+9,  N=2e6+5,M=25,MOD= 998244353, minOO=LLONG_MIN;
const double EPS=1e-10;
const double PI=acos(-1);
const ll maximum=1e6;
const int NOT_VISITED = -1;

///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة

struct Line {
    ll m, b;
    ll operator()(const ll x) const {
        return m * x + b;
    }
} seg[N<<2];

int  lo[N<<2], hi[N<<2];
void build(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    seg[i] = {0, OO};
    if(l == r)  return;
    int m = (l+r)/2;
    build(2*i, l, m);
    build(2*i+1, m+1, r);
}

void insert(int i, Line L){
    int l = lo[i], r = hi[i];
    if(l == r){
        if(L(l) < seg[i](l))
            seg[i] = L;
        return;
    }
    int m = (l+r)/2;
    if(seg[i].m < L.m)
        swap(seg[i], L);
    if(seg[i](m) > L(m)){
        swap(seg[i], L);
        insert(2*i, L);
    } else insert(2*i+1, L);
}

ll query(int i, ll x){
    int l = lo[i], r = hi[i];
    if(l == r)
        return seg[i](x);

    int m = (l+r)/2;
    if(x < m)
        return min(seg[i](x), query(2*i, x));
    else
        return min(seg[i](x), query(2*i+1, x));
}
void func(int index) {
    ll n,x;
    cin>>n>>x;
    vector<int>s(n),f(n);
    for (int i = 0; i < n; ++i) {
        cin>>s[i];
    }
    for (int i = 0; i < n; ++i) {
        cin>>f[i];
    }

    build(1,1,maximum);
    insert(1,{x,0});
    for (int i = 0; i < n-1; ++i) {
        ll q= query(1,s[i]);
        insert(1,{f[i],q});
    }
    cout<<query(1,s[n-1])<<endl;
}
signed main() {
//    freopen("lcm.in","rt",stdin);
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