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
const double EPS=1e-6;
const ll maximum=5000+6;
const int NOT_VISITED = -1;
vector<int>dp(maximum,0);
struct Node{
    Node *nxt[26];
    int cnt;
    int isEnd=0;
    Node()
    {
        // any data You created up intialize it here
        cnt = 0;
        memset(nxt,0,sizeof nxt);
    }
}*root;

void insert( string& st)
{
    Node *cur = root;
    for( int i = 0 ; i < st.size();i++)
    {
        if(!cur->nxt[st[i]-'a'])
            cur->nxt[st[i]-'a'] = new Node();
        cur = cur->nxt[st[i]-'a'];
        cur->cnt++;
    }
    cur->isEnd=1;
}
int get( string& st){
    Node *cur = root;
    for( int i = 0 ; i < st.size();i++)
    {
        if(!cur->nxt[st[i]-'a']){
            return 0;
        }
        if(i<st.size())
            cur = cur->nxt[st[i]-'a'];
    }
    return 1;
}
ll add ( ll a , ll b, ll mod)
{
    return (a + b) % mod;
}
ll sub ( ll a , ll b, ll mod)
{
    return (a - b +mod) % mod;
}
ll mul ( ll a , ll b, ll mod)
{
    return (1LL * a * b) % mod;
}
void func(int index){
    root=new Node();
    string str;cin>>str;
    ll n=str.size();
    ll k;cin>>k;
    for (int i = 0; i < k; ++i) {
        string s;cin>>s;
        insert(s);
    }
    dp[n]=1;
    string st="";

    for (int j = n-1; j >=0 ; j--) {
        st=str[j]+st;
        Node *cur = root;
        for( int i = 0 ; i < st.size();i++)
        {
            if(!cur->nxt[st[i]-'a']){
                break;
            }
            if(i<st.size())
                cur = cur->nxt[st[i]-'a'];
            if(cur->isEnd)
                dp[j]= add(dp[j], dp[i+1+j],mod);
        }
    }
    cout<<dp[0];
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