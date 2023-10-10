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

//the result length is --> k^n +n-1 ---( n is the length of needed string)&k is the #of outdeg for each node if we used binary it will be 2 if we use alpha it will be 26
//time is --> O(k^n)
ll fop( ll b , ll p)
{
    if(!p)
        return 1;
    ll temp = fop(b,p/2);
    temp = (temp*temp);
    if(p&1)
        temp =(temp*b);
    return temp;
}
set<string> done;// we can convert it to unordered set
vector<int> edges;
void DFS(string node, string&st)
{
    for (int i = 0; i < st.size(); ++i)
    {
        string cur = node+st[i];
        if (done.find(cur) == done.end())
        {
            done.insert(cur);
            DFS(cur.substr(1), st);
            edges.push_back(i);
        }
    }
}
string deBruijn(int n, string& st)
{
    done.clear(); edges.clear();

    string startingNode = string (n-1, st[0]);
    DFS(startingNode, st);
    string res;
    int len = fop(st.size(),n);
    for (int i = 0; i < len; ++i)
        res += st[edges[i]];
    res += startingNode;
    return res;
}
void func(int index)
{
    int n; cin >> n;
    string st = "01";// changable due to the main sequence
    cout << deBruijn(n, st) << '\n';
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