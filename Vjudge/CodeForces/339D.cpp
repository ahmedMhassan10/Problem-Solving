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
ll seg[N<<2];
ll arr[N];
ll num;
bool getpo(ll n,ll num){
    ll re=ceil(log2(n));
    if(n<pow(2,re))re--;
   // cout<<re<<" "<<num<<'\n';
    return ((re)%2)==(num%2);
}

void Build_seg(ll node,ll l , ll r,ll num) {
    if (l == r) {
        seg[node] = arr[l];
        return;
    }
    ll mid = (l + r) / 2;
    Build_seg(node * 2, l, mid,num);
    Build_seg(node * 2 + 1, mid + 1, r,num);
    if(getpo(node,num)){
        seg[node]=seg[node * 2] ^ seg[node * 2 + 1];
    }else
        seg[node]=seg[node * 2] | seg[node * 2 + 1];
}

void update(ll node,ll l ,ll r,ll idx,ll val,ll num) {
    if (l == r) {
        seg[node] = val;
        return;
    }
    ll mid = (l + r) / 2;
    if (idx <= mid) update(node * 2, l, mid, idx,val,num);
    else update(node * 2 + 1, mid + 1, r, idx,val,num);
    if(getpo(node,num)){
        seg[node]=seg[node * 2] ^ seg[node * 2 + 1];
    }else
        seg[node]=seg[node * 2] | seg[node * 2 + 1];
}


int main() {
        // freopen("survive.in "," r ",stdin);
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        ll num;cin>>num;
        ll q;cin>>q;
        fp(i,1,1 << num)cin>>arr[i];
        Build_seg(1,1,1 << num,num);
        while(q--){
            ll u,v;cin>>u>>v;
           // cout<<num<<'\n';
           // if(getpo(1,num))cout<<"xor\n";
            //else cout<<"or\n";
            update(1,1,1<< num,u,v,num);
            cout<<seg[1]<<"\n";
        }
}
