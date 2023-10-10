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
const ll OO =1e18, mod = 1e9+7,mod2=1e9+9,  N=3e5+5,M=25,MOD= 998244353, minOO=LLONG_MIN;
const double EPS=1e-10;
const double PI=acos(-1);
const ll maximum=3e3+2;
const int NOT_VISITED = -1;

///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة

vector<int>prif(maximum);
ll getCost(int l,int r){
    return (prif[r]-prif[l])*(prif[r]-prif[l]);
}

vector<int>curArr(maximum,OO),prevArr(maximum,OO);
ll n,k;
void solve(int l,int r,int optL,int optR,vector<int>&prev,vector<int>&cur){
    if(l>r)return;
    ll md=(l+r)/2;
    pair<int,int>res={OO,l};
    for (int i = optL; i < min(md,optR+1); ++i) {
        res=min(res,{getCost(i,md)+prev[i],i});
    }
    cur[md]=res.first;
    solve(l,md-1,optL,res.second,prev,cur);
    solve(md+1,r,res.second,optR,prev,cur);
}
void func(int index) {
    cin>>n>>k;
    for (int i = 1; i <= n ; ++i) {
        cin>>prif[i];
        prif[i]+=prif[i-1];
    }
    prevArr[0]=0;
    for (int i = 1; i <= k ; ++i) {
        solve(1,n,0,n-1,prevArr,curArr);
        swap(prevArr,curArr);
    }
    cout<<prevArr[n];
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