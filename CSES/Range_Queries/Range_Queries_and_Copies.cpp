#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
const ll OO =1e18, mod = 1e9+7,mod2=1e9+9,  N=2e5+5,M=30,MOD= 998244353, minOO=LLONG_MIN;

///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة

/// a33333333333333333333333333333333333333333333333333333333333333333333333333333333333333

int n, q;
int arr[N];
pair<int, int> child[N*2*M];//contain the left and right pointer of some node (M is log value)
int seg[N*2*M];
int root[N*2]; // contain pointer that point ot root of current component
int ptr=0, list_size=0;
void update(int cur, int prev, int l, int r, int pos, int val) {
    if (l == r) {
        seg[cur] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
        child[cur].first = ++ptr;
        child[cur].second = child[prev].second;
        update(child[cur].first, child[prev].first, l, mid, pos, val);
    } else {
        child[cur].first = child[prev].first;
        child[cur].second = ++ptr;
        update(child[cur].second, child[prev].second, mid + 1, r, pos, val);
    }
    seg[cur] = seg[child[cur].first] + seg[child[cur].second];
}

void modify(int new_version, int prev_version, int pos, int val) {
    update(new_version, prev_version, 0, n - 1, pos, val);
}
ll Build(ll l,ll r){
    ++ptr;
    ll id=ptr;
    if(l==r){
        seg[id]=arr[l];
        return id;
    }
    ll mid=(l+r)/2;
    child[id].first=Build(l,mid);
    child[id].second=Build(mid+1,r);
    seg[id]=seg[child[id].first]+seg[child[id].second];
    return id;
}
int query(int node, int l, int r, int ql, int qr) {
    if (node == 0) return 0;
    if (l > qr || r < ql) return 0;
    if (l >= ql && r <= qr) return seg[node];

    int mid = (l + r) / 2;
    return query(child[node].first, l, mid, ql, qr) + query(child[node].second, mid + 1, r, ql, qr);
}

int query(int version, int l, int r) {
    return query(version, 0, n - 1, l, r);
}
void func(int index) {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
//        int prev_root = root[1];
//        root[1] = ++ptr;
//        modify(root[1], prev_root, i, arr[i]);
    }
    root[1]= Build(0,n-1);
    list_size = 1;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int idx, k, x;
            cin >> k >> idx >> x;
            idx--;
            int new_root = ++ptr;
            modify(new_root, root[k], idx, x);
            root[k] = new_root;
        } else if (type == 2) {
            int k, l, r;
            cin >> k >> l >> r;
            l--, r--;
            cout << query(root[k], l, r) << "\n";
        } else {
            int k;
            cin >> k;
            root[++list_size] = root[k];
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