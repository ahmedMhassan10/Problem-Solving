#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
    string str;cin>>str;
    ll n=str.size();
    map<char,ll>freq;
    for (int i = 0; i < n; ++i) {
        freq[str[i]]++;
    }
    ll odd=0;
    char oddCh='0';
    for (char i = 'A'; i <='Z' ; ++i) {
        if(freq.count(i)){
            if(freq[i]%2){
                oddCh=i;
                odd++;
            }
        }
    }
    deque<char>dq;
    if(odd>1){
        cout<<"NO SOLUTION\n";
        return;
    }else if(odd==1){
        dq.push_front(oddCh);
        freq[oddCh]--;
    }
    for(auto item:freq){
        while (item.second){
            item.second--;
            if(item.second%2){
                dq.push_front(item.first);
            }else dq.push_back(item.first);
        }
    }
    while (dq.size()){
        cout<<dq.front();
        dq.pop_front();
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