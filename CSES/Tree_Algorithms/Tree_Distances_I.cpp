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

/// Ew3a tsra2 el code yalla

/// 3enak ya 7arami
vector<int> trees[N];
int depth[N];
int ans[N];
vector<int>lvl(N);;

void eval_depth(int src, int par)
{
    lvl[src]=lvl[par]+1;
    int src_depth = 1;
    for(int child : trees[src])
    {
        if(child != par)
        {
            eval_depth(child, src);
            src_depth = max(src_depth, 1 + depth[child]);
        }
    }
    depth[src] = src_depth;
}

void solve(int src, int par, int par_ans)
{
    vector<int> prefixMax, suffixMax;
    // get depth of child nodes.
    for(int child : trees[src])
    {
        if(child != par)
        {
            prefixMax.push_back(depth[child]);
            suffixMax.push_back(depth[child]);
        }
    }
    for(int i = 1; i < prefixMax.size(); i++)
        prefixMax[i] = max(prefixMax[i], prefixMax[i-1]);
    for(int i = (int)suffixMax.size() - 2; i >= 0; i--)
        suffixMax[i] = max(suffixMax[i], suffixMax[i+1]);
    int c_no = 0;
    for(int child : trees[src])
    {
        if(child != par)
        {
            int op1 = (c_no == 0) ? INT_MIN : prefixMax[c_no - 1];
            int op2 = (c_no == (int)suffixMax.size() - 1) ? INT_MIN : suffixMax[c_no + 1];
            int partial_ans = 1 + max(par_ans, max(op1,op2));

            solve(child, src, partial_ans);
            c_no++;
        }
    }
    ans[src] =max(par_ans, (prefixMax.empty() ? -1 : prefixMax.back()));
}

void func(int index){
    ll n;cin>>n;
    for (int i = 0; i < n+1; ++i) {
        trees[i].clear();
        depth[i]=0;
        lvl[i]=0;
        ans[i]=0;
    }
    for (int i = 0; i < n-1; ++i) {
        ll u,v;cin>>u>>v;
        trees[u].push_back(v);
        trees[v].push_back(u);
    }
    eval_depth(1,0);
    solve(1,0,0);
    ll res=0;
    for (int i = 1; i <=n ; ++i) {
        cout<<ans[i]<<" ";
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