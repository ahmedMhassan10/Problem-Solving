#include <bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()), ((v).end())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < sz(v); ++i)
#define fo(i, n) for (int i = 0; i < (int)(n); ++i)
#define fp(i, j, n) for (int i = (j); i <= (int)(n); ++i)
#define fn(i, j, n) for (int i = (j); i >= (int)(n); --i)
#define fvec(i, vec) for (auto i : vec)
#define pb push_back
#define MP make_pair
#define mine(x, y, z) min(x, min(y, z))
#define maxe(x, y, z) max(x, max(y, z))
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<pair<ll,ll>> vp;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
#define setp(item) cout<<fixed<<setprecision(item);
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO = 1e9, mod = 1e9 + 7,mod2=1e9+9, N = 5e5+10;
struct Node{
    Node *nxt[26];
    int cnt;
    bool end_ofword;
    Node()
    {
        end_ofword =false;
        cnt = 0;
        memset(nxt,0,sizeof nxt);
    }
}*root;
ll ans=0;
void insert( string st)
{
    Node *cur = root;
    for( int i = 0 ; i < st.size();i++)
    {
        if(!cur->nxt[st[i]-'a'])
            cur->nxt[st[i]-'a'] = new Node();
        cur = cur->nxt[st[i]-'a'];
        cur->cnt++;
    }
    ans+=!(cur->end_ofword);
    cur->end_ofword=true;
}
bool get( string st){
    Node *cur = root;
    for( int i = 0 ; i < st.size();i++)
    {
        if(!cur->nxt[st[i]-'a'])
         {
		return false;
	 }
	if(i<st.size())
        cur = cur->nxt[st[i]-'a'];
    }
    return true;
}

void testCase(){
        ans=0;
        root=new Node();
        int n,nc;cin>>n>>nc;
        string str;cin>>str;
        for(int i=0;i+n-1<str.size();i++){
            string ss=str.substr(i,n);
            set<char>s;
            fvec(item,ss)s.insert(item);
            if(s.size()<=nc){
                insert(ss);
            }
        }
        cout<<ans<<'\n';
}
int main() {
        // freopen("survive.in "," r ",stdin);
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int t=1;cin>>t;
        while(t--){
            testCase();
            if(t!=0)cout<<"\n";
        }
        return 0;
}
