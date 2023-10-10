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
const double EPS=1e-6;
const ll maximum=5e4+1;

const int NOT_VISITED = -1;

int dfn[N], low[N];
bool visited[N], root;
set<int> artpoints;		    //For removing arts if repetation
vector< vector<int> > graph;

//if we want to print the BI Connected  components

//stack< pair<int, int> > component;	//pair<int, int> is edge[u--v]

int num;

int min(int a, int b)
{
    return (a<b)?a:b;
}

void init(int n)
{

    num = 0;
    root=0;
    artpoints.clear();
    graph.clear();
    graph.resize(n);
    int i;
    for(i=0;i<n;i++)
    {
        visited[i] = false;
        dfn[i] = low[i] = NOT_VISITED;
    }

}

void bicon(int u, int v)	//O(n+e)
{
    int i, w;
    pair<int, int> edge;
    dfn[u] = low[u] = num++;

    for(i=0;i<graph[u].size();i++)
    {
        w = graph[u][i];
//                if we want to print the BI Connected  components

//        if(v!=w && dfn[w]<dfn[u])
//            component.push( make_pair(u, w));

        if(dfn[w] == NOT_VISITED)	// for each bcc, happens once ONLY
        {
            bicon(w, u);
            low[u] = min(low[u], low[w]);

            if(low[w] >= dfn[u])
            {
                if (dfn[u]==0 && root==false)
                    root=true;
                else
                    artpoints.insert(u);

//                if we want to print the BI Connected  components
//                int cnt = 0;
//                do
//                {
//                    cnt++;
//                    edge = component.top();
//                    component.pop();
//                    cout<<edge.first+1<<" "<<edge.second+1<<"\n";
//                }while(edge.first != u || edge.second != w);
//
//                if(cnt == 1)
//                    cout<<edge.second+1<<" "<<edge.first+1<<"\n";
            }
        }
        else if(w != v)
            low[u] = min(low[u], dfn[w]);
    }
}


void func(int index){
    int i, n, links, from, to;
    cin>>n>>links;


    init(n);
    for(i=0;i<links;i++)
    {
        cin>>from>>to;
        graph[from-1].push_back(to-1);
        graph[to-1].push_back(from-1);
    }
    bicon(0, NOT_VISITED);
    cout<<artpoints.size()<<endl;
    for(auto item:artpoints){
        cout<<item+1<<" ";
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