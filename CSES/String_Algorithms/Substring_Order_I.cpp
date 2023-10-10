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
const ll OO =1e18+10, mod = 1e9+7,mod2=1e9+9,  N=4e5+5,M=25,MOD= 998244353, minOO=LLONG_MIN;
const double EPS=1e-10;
const ll maximum=2e3+6;
const int NOT_VISITED = -1;


void count_sort(vector<int>&p,vector<int>&c){

    int n=p.size();
    vector<int>cnt(n);
    for (auto x:c) {
        cnt[x]++;
    }
    vector<int>p_new(n);
    vector<int>pos(n);
    pos[0]=0;
    for (int i = 1; i < n; ++i) {
        pos[i]=pos[i-1]+cnt[i-1];
    }
    for (auto x:p) {
        int i=c[x];
        p_new[pos[i]]=x;
        pos[i]++;
    }
    p=p_new;
}

vector<int> lcp_construction(string& s, vector<int>& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}
void func(int index){
    string s;cin>>s;
    ll len=s.size();
    s+="$";
    ll n=s.size();
    vector<int>p(n),c(n);
    {
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = {s[i], i};
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            } else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
    }
    int k=0;
    while ((1<<k)<n){
        for (int i = 0; i < n; ++i) {
            p[i]=(p[i]-(1<<k)+n)%n;
        }
        count_sort(p,c);
        vector<int>c_new(n);
        c_new[p[0]] = 0;
        for (int i = 1; i < n; ++i) {
            pair<int,int>prev={c[p[i-1]],c[(p[i-1]+(1<<k))%n]};
            pair<int,int>now={c[p[i]],c[(p[i]+(1<<k))%n]};
            if (now==prev) {
                c_new[p[i]] = c_new[p[i - 1]];
            } else {
                c_new[p[i]] = c_new[p[i - 1]] + 1;
            }
        }
        c=c_new;
        k++;
    }
    ll rank;cin>>rank;
    auto lcp= lcp_construction(s,p);
    ll total=0;
    for (int i = 1; i < n; ++i) {
        ll len2=len-p[i]-lcp[i-1];
        if(total+len2>=rank){
            ll go=(rank-total);
            string sR="";
            for (int j = 0; j < lcp[i-1]; ++j) {
                sR+=s[p[i]+j];
            }
            for (int j = 0; j < go; ++j) {
                sR+=s[p[i]+j+lcp[i-1]];
            }
            cout<<sR<<endl;
            return;
        }
        total+=len2;
    }
}

signed main() {
//    freopen("ysys.in","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
//    cin>>t;
    ll index=1;
    while (t--){
        auto start=chrono::system_clock::now();
        func(index++);
        auto end=chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
//        cout<<elapsed_seconds.count()<<endl;
    }
    return 0;
}