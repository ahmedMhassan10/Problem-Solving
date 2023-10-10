#include <bits/stdc++.h>
using namespace std;
#define clr(v, d)			memset(v, d, sizeof(v))
#define ll long long
#define int long long
#define double long double

const ll OO =1e17+10, mod = 1e9+7,mod2=1e9+9,  N=2e5+5,M=25,MOD= 998244353, minOO=LLONG_MIN;

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


struct state {
    int len, link;
    map<char, int> next;
};
const int MAXLEN = 1e5;
state st[MAXLEN * 2];
int sz, last;
void init() {
    st[0].len = 0;
    st[0].link = -1;
    st[0].next.clear();
    sz=0;
    sz++;
    last = 0;
}
void insertChar(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
vector<int>res(2*MAXLEN);
void get_diff_strings(int len){
    for(int i = 1; i < sz; i++) {
        res[st[st[i].link].len+1]++;
        res[st[i].len+1]--;
    }
    for (int i = 1; i <=len; ++i) {
        res[i]+=res[i-1];
    }
}
void solve(int idx) {
    init();
    string str;cin>>str;
    for (int i = 0; i < str.size(); ++i) {
        insertChar(str[i]);
    }
    get_diff_strings(str.size());
    for (int i = 1; i <= str.size() ; ++i) {
        cout<<res[i]<<' ';
    }
}
signed main() {
//    freopen("dim_sum_delivery_input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
//    cin>>t;
    for (int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}