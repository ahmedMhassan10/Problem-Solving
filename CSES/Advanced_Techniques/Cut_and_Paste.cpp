#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
//
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")

#define clr(v, d)			memset(v, d, sizeof(v))
#define ll long long
#define int long long
typedef tree< pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define setp(item) cout<<fixed<<setprecision(item);
#define PI 3.14159265358979323846264338327950
int ceilSqrt(int a){
    return ::ceil(sqrtl(a));
}
int  divC(int a,int b){
    return a/b+(a%b!=0);
}
int gcd(int a, int b) { return ((b == 0) ? a : gcd(b, a % b)); }
int lcm(int a,int b){return (a*b)/gcd(a,b);}
const ll OO =1e18+10, mod = 1e9+7,mod2=1e9+9,  N=2e5+5,M=25,MOD= 998244353, minOO=LLONG_MIN;
const double EPS=1e-6;
const ll maximum=5e4+1;

struct item {
    int  prior,cnt=1;
    char key;
    item *l, *r;
    item () { }
    item (char key) : key(key), prior(rand()), l(NULL), r(NULL) { }
    item (char key, int prior) : key(key), prior(prior), l(NULL), r(NULL) { }
};
typedef item* pitem;

int cnt (pitem t) {
    return t ? t->cnt : 0;
}

void upd_cnt (pitem t) {
    if (t)
        t->cnt = 1 + cnt(t->l) + cnt (t->r);
}

// use merge and split to insert & erase elelment

void merge (pitem & t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {  // l the first key elements r is the rest
    if (!t)
        return void( l = r = 0 );
    int cur_key = add + cnt(t->l); //implicit key
    if (key <= cur_key)
        split (t->l, l, t->l, key, add),  r = t;
    else
        split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    upd_cnt (t);
}

void output (pitem t) {
    if (!t)  return;
    output (t->l);
    cout<< t->key;
    output (t->r);
}

void func(int index){
    ll n,q;cin>>n>>q;
    string str;cin>>str;
    pitem root=new item(str[0]);
    for (int i = 1; i < n; ++i) {
        merge(root,root,new item(str[i]));
    }
    while (q--){
        ll st,en;cin>>st>>en;
        ll rem=en-st+1;
        pitem l1,r1,l2,r2;
        split(root,l1,r1,st-1);
        split(r1,l2,r2,rem);
        merge(root,l1,r2);
        merge(root,root,l2);
    }
    output(root);
}
signed main() {
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