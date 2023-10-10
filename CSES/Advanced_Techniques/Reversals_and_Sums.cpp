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

typedef struct item * pitem;
struct item {
    int prior, cnt;
    bool rev;
    int value;
    int sum;
    pitem l, r;
    item (int value) : value(value),sum(value), prior(rand()), l(NULL), r(NULL) { }
    item (int value, int prior) : value(value), prior(prior), l(NULL), r(NULL) { }
};

int cnt (pitem it) {
    return it ? it->cnt : 0;
}
int sm(pitem it){
    return it ? it->sum : 0;
}
void upd_cnt (pitem it) {
    if (it)
    {
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
        it->sum=sm(it->l)+sm(it->r)+it->value;
    }
}

void push (pitem it) { 		// we use it as lazy propagation
    if (it && it->rev) {
        it->rev = false;
        swap (it->l, it->r);
        if (it->l)  it->l->rev ^= true;
        if (it->r)  it->r->rev ^= true;
    }
}

void merge (pitem & t, pitem l, pitem r) {
    push (l);
    push (r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    push (t);
    int cur_key = add + cnt(t->l);
    if (key <= cur_key)
        split (t->l, l, t->l, key, add),  r = t;
    else
        split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    upd_cnt (t);
}

void reverse (pitem t, int l, int r) {
    pitem t1, t2, t3;
    split (t, t1, t2, l-1);
    split (t2, t2, t3, r-l+1);
    t2->rev ^= true;
    merge (t, t1, t2);
    merge (t, t, t3);
}

void output (pitem t) {
    if (!t)  return;
    push (t);
    output (t->l);
    cout<<t->value;
    output (t->r);
}

void func(int index){
    ll n,q;cin>>n>>q;
    ll u;
    cin>>u;
    pitem root=new item(u);
    for (int i = 1; i < n; ++i) {
        cin>>u;
        merge(root,root,new item(u));
    }
    while (q--){
        ll t;cin>>t;
        ll st,en;cin>>st>>en;
        if(t==1){
            reverse(root,st,en);
        }else{
            pitem l1,r1,l2,r2;
            split(root,l1,r1,st-1);
            split(r1,l2,r2,en-st+1);
            cout<<l2->sum<<endl;
            merge(root,l1,l2);
            merge(root,root,r2);
        }
    }
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