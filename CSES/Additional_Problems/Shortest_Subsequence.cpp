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
const ll OO =1e18+10, mod = 1e9+7,mod2=1e9+9,  N=1e5+5,M=25,MOD= 998244353, minOO=LLONG_MIN;
const double EPS=1e-10;
const ll maximum=2e6+6;
const int NOT_VISITED = -1;

void func(int index){
    string str;cin>>str;
    ll n=str.size();
    map<char,int>ma;
    ma['A']=0,ma['C']=1,ma['G']=2,ma['T']=3;
    vector<int>contain(4);
    ll s=0;
    for (int i = 0; i < n; ++i) {
        ll temp=ma[str[i]];
        if(!contain[temp]){
            contain[temp]=1;
            s++;
            if(s==4){
                contain=vector<int>(4,0);
                cout<<str[i];
                s=0;
            }
        }
    }
    if(!contain[0]){
        cout<<"A";
    }else if(!contain[1]){
        cout<<"C";
    }else if(!contain[2]){
        cout<<"G";
    }else if(!contain[3]){
        cout<<"T";
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