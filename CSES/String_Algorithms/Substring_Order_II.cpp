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
    int len=0, link=0,count=0,dp=-1;
    map<char, int> next;
};
const int MAXLEN = 1e5+10;
state st[MAXLEN * 2];
int sz, last;
void init() {
    st[0].len = 0;
    st[0].count = 0;
    st[0].link = -1;
    st[0].dp = -1;
    st[0].next.clear();
    sz=0;
    sz++;
    last = 0;
}
void insertChar(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].count=1;
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
vector<vector<int>>g(2*MAXLEN);
void dfs(int node){
    for(auto item:g[node]){
        dfs(item);
        st[node].count+=st[item].count;
    }
}
void calcDp(int node){
    st[node].dp=st[node].count;
    for (auto item:st[node].next) {
        if(st[item.second].dp==-1)
            calcDp(item.second);
        st[node].dp+=st[item.second].dp;
    }
}
void calc_the_counter_for_every_subtree(){
    for (int i = 1; i < sz; ++i) {
        g[st[i].link].push_back(i);
    }
    dfs(0);
    calcDp(0);
}
void solve(int idx) {
    init();
    string str;cin>>str;
    for (int i = 0; i < str.size(); ++i) {
        insertChar(str[i]);
    }
    ll k;cin>>k;
    ll n=str.size();
    if(n*(n+1)/2<k){
        cout<<"No such line.\n";
        return;
    }
    ll node=0;
    calc_the_counter_for_every_subtree();
    while (1){
        for (auto item:st[node].next) {
            if (k <= st[item.second].count) {
                cout<<item.first;
                return;
            } else if(st[item.second].dp>=k){
                cout<<item.first;
                k-=st[item.second].count;
                node=item.second;
                break;
            }else{
                k-=st[item.second].dp;
            }
        }
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