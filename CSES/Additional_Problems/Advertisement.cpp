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
int ceilSqrt(int a){
    return ::ceil(sqrtl(a));
}
int  divC(int a,int b){
    return a/b+(a%b!=0);
}
int gcd(int a, int b) { return ((b == 0) ? a : gcd(b, a % b)); }
int lcm(int a,int b){return (a*b)/gcd(a,b);}
const ll OO =1e18+10, mod = 1e9+7,mod2=1e9+9,  N=1e5+5,M=25,MOD= 998244353, minOO=LLONG_MIN;
const double EPS=1e-10;
const double PI=acos(-1);
const ll maximum=2e6+6;
const int NOT_VISITED = -1;

void func(int index){
    int num;cin>>num;
    int a[num],  mnl[num], mnr[num];
    int maxi=0;
    for(int i = 0; i < num; i++)
    {
        cin>>a[i];
        maxi=max(a[i],maxi);
    }
    stack<int>  s2,  s4;
    for(int i = 0; i < num; i++) {
        while(!s2.empty() && a[s2.top()] >= a[i])
            s2.pop();
        while(!s4.empty() && a[s4.top()] >= a[num - 1 - i])
            s4.pop();
        mnl[i] = s2.empty() ? -1: i - s2.top();//distance
        mnr[num - 1 - i] = s4.empty() ? -1: s4.top() - (num - 1 - i);//distance
        s2.push(i);
        s4.push(num - 1 - i);
    }
    for (int i = 0; i < num; ++i) {
        if(mnl[i]==-1){
            mnl[i]=i+1;
        }
        if(mnr[i]==-1){
            mnr[i]=num-i;
        }
    }
    for (int i = 0; i < num; ++i) {
        ll prev=mnl[i],next=mnr[i];
        ll len2=(prev-1)+(next-1)+1;
        ll res=len2*a[i];
        maxi=max(maxi,res);
    }
    cout<<maxi;
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