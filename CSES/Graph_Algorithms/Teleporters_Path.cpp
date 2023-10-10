#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define clr(v, d)			memset(v, d, sizeof(v))
#define ll long long
#define int long long
typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
const ll OO =1e18, mod = 1e9+7,mod2=1e9+9, N =2e5+5,M=30,MOD= 998244353, minOO=LLONG_MIN;

///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة

/// a33333333333333333333333333333333333333333333333333333333333333333333333333333333333333

vector<int> in(N), out(N);
vector < int > g[N];
vector < int > ans;
void dfs( int node)
{
    while(!g[node].empty())
    {
        int v = g[node].back();
        g[node].pop_back();
        dfs(v);
    }
    ans.push_back(node);
}
void func(int index)
{
    int n , m ;
    cin >> n >> m;
    for ( int i = 0 ; i < m ; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        out[u]++,in[v]++;
    }
    for ( int i = 2; i < n ; i++)
    {
        if(in[i] != out[i])
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    if(out[1] != in[1]+1 || in[n] != out[n]+1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    dfs(1);
    if(ans.size() != m+1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for ( int i = m ; i >= 0 ; i--)
        cout << ans[i] << ' ';
    cout << '\n';
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