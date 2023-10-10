#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define all(v) ((v).begin()), ((v).end())
#define allRev(v) ((v).rbegin()), ((v).rend())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define fo(i, n) for (long long i = 0; i < (long long)(n); ++i)
#define fp(i, j, n) for (long long i = (j); i <= (long long)(n); ++i)
#define fn(i, j, n) for (long long i = (j); i >= (long long)(n); --i)
#define fvec(i, vec) for (auto i : vec)
#define pb push_back
#define mine(x, y, z) min(x, min(y, z))
#define maxe(x, y, z) max(x, max(y, z))
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef vector<pll> vp;
typedef vector<double> vd;
typedef vector<string> vs;
typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define setp(item) cout<<fixed<<setprecision(item);
#define PI 3.14159265358979323846264338327950
ll ceilSqrt(ll a){
    return ::ceil(sqrtl(a));
}
ll  divC(ll a,ll b){
    return a/b+(a%b!=0);
}
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO =1e15, mod = 1e9+7,mod2=1e9+9, N =2e5+5,M=30,MOD= 998244353, minOO=LLONG_MIN;
///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة
/// :-)
/// a33333333333333333333333333333333333333333333333333333333333333333333333333333333333333
vector< vector<int> > adjList, comps, dagList;
vector<int> inStack, lowLink, dfn, comp, inDeg, outDeg;
stack<int> stk;
int ndfn, cntSrc, cntSnk;

void tarjan(int node) {
    lowLink[node] = dfn[node] = ndfn++, inStack[node] = 1;
    stk.push(node);

    fo(i, adjList[node].size()) {
        int ch = adjList[node][i];
        if (dfn[ch] == -1) {
            tarjan(ch);
            lowLink[node] = min(lowLink[node], lowLink[ch]);
        } else if (inStack[ch])
            lowLink[node] = min(lowLink[node], dfn[ch]);
    }

    if (lowLink[node] == dfn[node]) {
        comps.push_back(vector<int> ());
        int x = -1;
        while (x != node) {
            x = stk.top(), stk.pop(), inStack[x] = 0;
            comps.back().push_back(x);
            comp[x] = siz(comps) - 1;
        }
    }
}


void scc() {
    int n = siz(adjList);

    inStack.clear();	inStack.resize(n);
    lowLink.clear();	lowLink.resize(n);
    dfn.clear();		dfn.resize(n, -1);
    ndfn = 0;

    comp.clear(), comp.resize(n);
    comps.clear();

    fo(i, n) if (dfn[i] == -1)
            tarjan(i);
}
void func(ll index) {
    ll n, m;
    cin >> n >> m;
    adjList.clear();
    adjList = vector<vector<int> > (n);

    fo(i, m) {
        int f, t;
        cin >> f >> t;
        f--, t--;
        adjList[f].push_back(t);
    }
    scc();
    cout<<comps.size()<<'\n';

    fo(i,n){
        cout<<comp[i]+1<<" ";
    }
}
int main() {
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