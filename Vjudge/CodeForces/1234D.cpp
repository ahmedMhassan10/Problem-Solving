#include <bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()), ((v).end())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < sz(v); ++i)
#define fo(i, n) for (int i = 0; i < (int)(n); ++i)
#define fp(i, j, n) for (long long i = (j); i <= (long long)(n); ++i)
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
const ll OO = 1e9, mod = 1e9 + 7,mod2=1e9+9, N =2e5+5,M=25;
ll seg[N<<2][26];
char arr[N];
ll num;
void Build_seg(ll node,ll l , ll r) {
    if (l == r) {
        seg[node][arr[l]-'a']++;
        return;
    }
    ll mid = (l + r) / 2;
    Build_seg(node * 2, l, mid);
    Build_seg(node * 2 + 1, mid + 1, r);
   fo(i,26)seg[node][i]=seg[2*node][i]+seg[2*node+1][i];
}
void update(ll node,ll l ,ll r,ll idx,char val) {
    if (l == r) {
        seg[node][arr[l]-'a']--;
        seg[node][val-'a']++;
        return;
    }
    ll mid = (l + r) / 2;
    if (idx <= mid) update(node * 2, l, mid, idx,val);
    else update(node * 2 + 1, mid + 1, r, idx,val);
   fo(i,26)seg[node][i]=seg[2*node][i]+seg[2*node+1][i];

}
vll vec(26);
void query(ll node,ll l ,ll r,ll st,ll en) {
       if(l>en || r<st){
            return ;
       }
       if(l>=st && r<=en){
            fo(i,26){
                if(seg[node][i])vec[i]=1;
            }
            //cout<<'\n';
            return ;
       }
       ll md= (l+r)/2 ;
       query(node*2,l,md,st,en);query(node*2+1,md+1,r,st,en);
}

int main() {
        // freopen("survive.in "," r ",stdin);
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        string str;cin>>str;
        fp(i,1,siz(str)){
            arr[i]=str[i-1];
        }
        Build_seg(1,1,siz(str));
        int q;cin>>q;
        while(q--){
            ll u;cin>>u;
            if(u==1){
                    ll v;char c;
                    cin>>v>>c;
                    update(1,1,siz(str),v,c);
                    arr[v]=c;
            }else{
                vec.assign(26,0);
                ll v,k;cin>>v>>k;query(1,1,siz(str),v,k);
                ll sum=0;
                fo(i,26){
                    sum+=vec[i];
                }
                cout<<sum<<'\n';
            }
        }
}
