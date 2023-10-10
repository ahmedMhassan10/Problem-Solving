#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define clr(v, d)			memset(v, d, sizeof(v))
#define ll long long

#define int long long

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
const int OO =1e18, mod = 1e9+7,mod2=1e9+9, N =2e5+5,M=30,MOD= 998244353, minOO=LLONG_MIN;

///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة

/// a33333333333333333333333333333333333333333333333333333333333333333333333333333333333333

void func(int index){
    int t, n, q, l, k, nn, r, z;
    cin >> t;
    vector<int> snake;
    unordered_map<int,int> mm;
    for (int i = 0; i < t; ++i){
        cin >> n >> q;
        snake.resize(n);
        for (int j = 0; j < n; ++j)
            cin >> snake[j];
        sort(snake.begin(),snake.end());
        mm.clear();
        for (int j = 0; j < q; ++j){
            cin >> k;
            if (mm.count(k)){
                cout << mm[k] << endl;
                continue;
            }
            if (k <= snake[0]){
                cout << n << endl;
                mm[k] = n;
                continue;
            }
            if (k > snake.back() + n - 1){
                cout << 0 << endl;
                mm[k] = 0;
                continue;
            }
            nn = -1;
            l = snake.end() - lower_bound(snake.begin(),snake.end(),k);
            r = l - 1;
            for (z = n - l - 1; z > nn; --z){
                ++r;
                nn += k - snake[z];
            }
            if (z == nn)
                ++r;
            mm[k] = r;
            cout << r << endl;
        }
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