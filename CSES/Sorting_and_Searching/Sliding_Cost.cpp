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
    ll n,k;cin>>n>>k;
    ordered_set se;
    vector<int>vec(n);
    for (int i = 0; i < n; ++i) {
        cin>>vec[i];
    }
    for (int i = 0; i < k; ++i) {
        se.insert({vec[i],i});
    }
    ll order=(k+1)/2-1;
    pair<int,int> lastMed=*se.find_by_order(order);
    ll cost=0;
    ll lessSum=0,higherSum=0;
    for (auto it:se) {
        if(cost==order){
            cost++;
            continue;
        }
        if(cost<order){
            lessSum+=it.first;
        }else{
            higherSum+=it.first;
        }
        cost++;
    }
    for (int i = k; i <= n; ++i) {
        cout<<(order)*lastMed.first-lessSum+higherSum-(k-1-order)*lastMed.first<<' ';
        pair<int,int>l={vec[i-k],i-k};
        if(l<lastMed)lessSum-=l.first;
        else if(l>lastMed)higherSum-=l.first;
        se.erase({vec[i-k],i-k});
        if(i<n){
            se.insert({vec[i],i});
            pair<int,int>median=*se.find_by_order(order);
            pair<int,int>cur={vec[i],i};
            if(median.second!=i&&median!=lastMed){
                if(median<lastMed){
                    lessSum-=median.first;
                }else{
                    higherSum-=median.first;
                }
            }
            if(median!=cur){
                if(median<cur)
                    higherSum+=cur.first;
                else lessSum+=cur.first;
            }
            if(median!=lastMed&&lastMed!=l){
                if(median>lastMed)
                    lessSum+=lastMed.first;
                else
                    higherSum+=lastMed.first;
            }
            lastMed=median;
        }
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