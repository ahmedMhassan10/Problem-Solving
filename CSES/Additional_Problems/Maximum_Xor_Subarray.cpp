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
int ceilSqrt(int a){
    return ::ceil(sqrtl(a));
}
int  divC(int a,int b){
    return a/b+(a%b!=0);
}
int gcd(int a, int b) { return ((b == 0) ? a : gcd(b, a % b)); }
int lcm(int a,int b){return (a*b)/gcd(a,b);}
const ll OO =1e18+10, mod = 1e9+7,mod2=1e9+9,  N=1e5+5,M=25,MOD= 998244353, minOO=LLONG_MIN;
const double EPS=1e-10;
const double PI=acos(-1);
const ll maximum=500+6;
const int NOT_VISITED = -1;


struct Node{
    Node *nxt[2];
    int cnt;
    Node()
    {
        cnt = 0;
        memset(nxt,0,sizeof nxt);
    }
}*root;

void insert(  int num)
{
    Node *cur = root;
    for( int i = 30 ; i >= 0;i--)
    {
        int tr=(bool)((1<<i)&num);
        if(!cur->nxt[tr])
            cur->nxt[tr] = new Node();
        cur = cur->nxt[tr];
    }
}
bool get( int num){
    Node *cur = root;
    for( int i = 30 ; i >= 0;i--)
    {
        int tr=(bool)((1<<i)&num);

        if(!cur->nxt[tr]){
            return false;
        }
        cur = cur->nxt[tr];
    }
    return true;
}
int search( int num){
    Node *cur = root;
    ll res=0;
    for( int i = 30 ; i >= 0;i--)
    {
        int tr=(1-(bool)((1<<i)&num));
        if(cur->nxt[tr]){
            cur = cur->nxt[tr];
            if(tr){
                res+=(1<<i);
            }
        }else if(cur->nxt[1-tr]) {
            cur = cur->nxt[1 - tr];
            if(tr==0){
                res+=(1<<i);
            }
        }else{
            return res;
        }
    }
    return res;
}
void func(int index){
    root=new Node();
    ll n;cin>>n;
    vector<int>vec(n);
    vector<int>prif(n);
    ll res=0;
    for (int i = 0; i < n; ++i) {
        cin>>vec[i];
        prif[i]=vec[i];
        if(i)
        {
            prif[i]^=prif[i-1];
            ll val= search(prif[i]);
            res=max({res,val^prif[i],prif[i]});
        }else{
            res=max(res,prif[i]);
        }
        insert(prif[i]);
    }
    cout<<res;
}
signed main() {
//    freopen("ysys.in","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
//    cin>>t;
    ll index=1;
    while (t--){
        auto start=chrono::system_clock::now();
        func(index++);
        auto end=chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
//        cout<<elapsed_seconds.count()<<endl;
    }
    return 0;
}