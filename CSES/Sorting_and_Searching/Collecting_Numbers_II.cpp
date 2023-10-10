#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree< pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int long long
#define ll long long

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
const int OO =1e15, mod = 1e9+7,mod2=1e9+9, N =2e5+5,M=30,MOD= 998244353, minOO=LLONG_MIN;
///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة
/// :-)
/// a33333333333333333333333333333333333333333333333333333333333333333333333333333333333333
void func(int index) {
    int n; cin>>n;
    ll m;cin>>m;
    int l = 1;
    vector<int> ind(n+5,0);
    vector<int> app(n+5,0);
    for (int i = 1; i <= n; i++) {
        int x; cin>>x;
        ind[x] = i;
        app[i]=x;
    }
    ind[n+1]=n+1;
    int c = 1;
    for (int i = 1; i <= n; i++) {
        if (l > ind[i])
            c++;
        l = ind[i];
    }
//    cout<<c;
    while (m--){
        ll u,v;cin>>u>>v;
        ll uVal=app[u],vVal=app[v];
        swap(app[u],app[v]);
        ll prevV=vVal-1,nextV=vVal+1;
        ll prevU=uVal-1,nextU=uVal+1;
        if(ind[prevU]<=ind[uVal]&&ind[prevU]>v)c++;
        if(ind[prevU]>ind[uVal]&&ind[prevU]<=v)c--;
        if(ind[nextU]>=ind[uVal]&&ind[nextU]<v)c++;
        if(ind[nextU]<ind[uVal]&&ind[nextU]>=v)c--;
        ind[uVal]=v; // to handle dependency
        if(ind[prevV]<=ind[vVal]&&ind[prevV]>u)c++;
        if(ind[prevV]>ind[vVal]&&ind[prevV]<=u)c--;
        if(ind[nextV]>=ind[vVal]&&ind[nextV]<u)c++;
        if(ind[nextV]<ind[vVal]&&ind[nextV]>=u)c--;
        ind[vVal]=u;
        
        cout<<c<<'\n';
    }

}
signed main() {
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
//    cin>>t;
    int index=1;
    while (t--){
        func(index++);
    }
    return 0;
}