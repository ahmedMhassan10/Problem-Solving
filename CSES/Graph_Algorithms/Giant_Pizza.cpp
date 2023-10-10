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
const int OO =1e15, mod = 1e9+7,mod2=1e9+9, N =1e5+5,M=30,MOD= 998244353, minOO=LLONG_MIN;
///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة
/// :-)
/// a33333333333333333333333333333333333333333333333333333333333333333333333333333333333333



// Switch between even odd: (0, 1), (2, 3).. -->(i,!i)===(i,i^1)
#define NOT(x)    (1^(x))
#define getValue(x) (2*x) // get the hashed value in the algorithm
int n, m, ndfn;
vector< vector<int> > adjList, comps, dagList;
vector<int> inStack, lowLink, dfn, comp, assigned_val, cmp_root_node;
stack<int> stk;

void tarjan(int node) {
    lowLink[node] = dfn[node] = ndfn++, inStack[node] = 1;
    stk.push(node);

    for(int i=0;i< adjList[node].size();i++) {
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
            comp[x] = comps.size() - 1;
        }
        cmp_root_node[ comp[node] ] = node;		// ***
    }
}

void scc() {
    int n = (adjList.size());

    inStack.clear();		inStack.resize(n);
    lowLink.clear();		lowLink.resize(n);
    assigned_val.clear();	assigned_val.resize(n);
    cmp_root_node.clear();		cmp_root_node.resize(n);
    dfn.clear();			dfn.resize(n, -1);
    ndfn = 0;

    comp.clear(), comp.resize(n);
    comps.clear();

    for(int i=0;i< n;i++)
        if (dfn[i] == -1)
            tarjan(i);
}

// acceptable values: (0, 1), (1, 0), (1, 1)
void add_or(int a, int b)
{
    adjList[NOT(a)].push_back(b);
    adjList[NOT(b)].push_back(a);
}

// acceptable values: (0, 1), (1, 0)
void add_or_not_both(int a, int b) //--> for some specific problem
{
    // CNF: (a v b) & (!a v !b)  ==> E.g. can't be true for (1, 1) / (0, 0)
    add_or(a, b);
    add_or(NOT(a), NOT(b));
}

void force_value(int i, bool b)// to force node i to be true or force
{
    if(b)
        adjList[NOT(i)].push_back(i);
    else
        adjList[i].push_back(NOT(i));
}

bool is_solvable() // check if there is solution
{
    for(int i = 0 ; i < n ; i += 2)
        if( comp[i] == comp[NOT(i)] )
            return false;
    return true;
}

void assign_values()
{
    vector<int> comp_assigned_value(comps.size(), -1);

    for(int i=0; i<comps.size();i++) {
        if (comp_assigned_value[i] == -1){
            comp_assigned_value[i] = 1;
            int not_ithcomp = comp[ NOT(cmp_root_node[i]) ];
            comp_assigned_value[ not_ithcomp ] = 0;
        }
    }

    for(int i=0;i< n;i++)
         assigned_val[i] = comp_assigned_value[ comp[i] ];
}

void func(int index){
    cin>>m>>n;
    n=2*n;
    adjList.clear();
    adjList.resize(n);

    for (int i = 0; i <m ; ++i) {
        char ch1,ch2;
        int a,b;
        cin>>ch1>>a>>ch2>>b;
        a--,b--;
        a= getValue(a);
        b= getValue(b);
        if(ch1=='-')a= NOT(a);
        if(ch2=='-')b= NOT(b);
        add_or(a, b);
    }
    scc();
    if (!is_solvable())
    {
        cout<<"IMPOSSIBLE\n";
        return;
    }
    assign_values();	// solution in assign_values array
    for (int i = 0; i < n; i+=2) {
        if(assigned_val[i]==1){
            cout<<"+ ";
        }else {
            cout<<"- ";
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