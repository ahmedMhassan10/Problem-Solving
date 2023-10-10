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
const ll maximum=5000+6;
const int NOT_VISITED = -1;
void compute_prefix(string &s,vector<int> &fail){
    for( int i=1;i<s.size();i++){
        int j=fail[i-1];
        while(j>0&& s[i]!=s[j])
            j=fail[j-1];
        if(s[i]==s[j])
            fail[i]=j+1;
        else fail[i]=0;
    }
}

void func(int index){
    string str;cin>>str;
    ll n=str.size();
    vector<int>fail(n);
    compute_prefix(str,fail);
    ll st=fail[n-1];
    vector<int>v;
    while (st){
        v.push_back(st);
        st=fail[st-1];
    }
    v.push_back(0);
    for(auto item:v){
        cout<<n-item<<" ";
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