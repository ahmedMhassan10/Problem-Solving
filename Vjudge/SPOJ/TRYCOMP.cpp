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
struct Node{
    Node *nxt[26];
    int cnt;
    int maxFreq;
    set<pair<int,int>>se;
    Node(){
    	// any data You created up intialize it here
	    cnt = 0;
        maxFreq=0;
        memset(nxt,0,sizeof nxt);
    }
}*root;

void insert( string st,int index,int counter)
{
    Node *cur = root;
    for( int i = 0 ; i < st.size();i++)
    {
        if(!cur->nxt[st[i]-'a'])
            cur->nxt[st[i]-'a'] = new Node();
        cur = cur->nxt[st[i]-'a'];
        cur->cnt++;
        cur->se.insert({-counter,index});
    }
}
int get( string st){
    Node *cur = root;
    for( int i = 0 ; i < st.size();i++)
    {
        if(!cur->nxt[st[i]-'a']){
		    return -1;
        }
	    if(i<st.size())
            cur = cur->nxt[st[i]-'a'];
    }
    return (cur->se.begin()->second);
}
void func(int index){
    root=new Node();
    ll n;cin>>n;
    vector<string>vs(n);
    map<string ,ll>ma;
    for (int i = 0; i < n; ++i) {
        cin>>vs[i];
        ma[vs[i]]++;
    }
    sort(vs.begin(),vs.end());
    for (int i = 0; i < n; ++i) {
        insert(vs[i],i,ma[vs[i]]);
    }
    ll q;cin>>q;
    for (int i = 0; i < q; ++i) {
        string st;cin>>st;
        ll v= get(st);
        if(v==-1){
            cout<<"-1\n";
        }else{
            cout<<vs[v]<<" "<<ma[vs[v]]<<'\n';
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