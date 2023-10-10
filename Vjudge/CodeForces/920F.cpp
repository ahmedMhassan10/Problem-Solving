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
const ll OO = 1e9, mod = 1e9 + 7,mod2=1e9+9, N =3e5 +5,M=1e6+6;
ll seg[N<<2], mx[N<<2];
ll arr[N];
ll num;
ll D[M];
void Build_seg(ll node,ll l , ll r) {// DONT FORGET BUILD IN MAIN YA 7OMAR
    if (l == r) {
        seg[node] = arr[l];
        mx[node]=arr[l];
        return;
    }
    ll mid = (l + r) / 2;
    Build_seg(node * 2, l, mid);
    Build_seg(node * 2 + 1, mid + 1, r);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];// DONT FORGET BUILD IN MAIN YA 7OMAR
    mx[node]=max(mx[node * 2] , mx[node * 2 + 1]);
}
void update(ll node,ll l ,ll r,ll st,ll en) {// DONT FORGET BUILD IN MAIN YA 7OMAR
    if(l>en|| r<st||mx[node]<3)return ;
    if (l == r) {
        //cout<<arr[l]<<" "<<l<<" "<<D[arr[l]]<<'\n';

        arr[l]=D[arr[l]];

        seg[node] = arr[l];
        mx[node]=arr[l];
        return;
    }
    ll mid = (l + r) / 2;
    update(node * 2, l, mid, st,en);
     update(node * 2 + 1, mid + 1, r, st,en);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];// DONT FORGET BUILD IN MAIN YA 7OMAR
    mx[node]=max(mx[node * 2] , mx[node * 2 + 1]);
}
ll query(ll node,ll l ,ll r,ll st,ll en) {// DONT FORGET BUILD IN MAIN YA 7OMAR
       if(l>en || r<st){
        return 0;
       }
       if(l>=st && r<=en){
             return seg[node];
       }
       ll md= (l+r)/2 ;
       return (query(node*2,l,md,st,en)+query(node*2+1,md+1,r,st,en));// DONT FORGET BUILD IN MAIN YA 7OMAR
}

int main() {
        // freopen("survive.in "," r ",stdin);
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        cin>>num;ll q;cin>>q;
        ll maxi=0;
        fp(i,1,num){
            cin>>arr[i];
        }
        //clr(D,1);
        fp(i,1,M-1){
            for(ll j=i;j<=M-1;j+=i){
                D[j]++;
            }
        }
        Build_seg(1,1,num);
        while(q--){
            int t;cin>>t;
            if(t==1){
                int u,v;cin>>u>>v;
                update(1,1,num,u,v);
            }else{
                int u,v;cin>>u>>v;
                cout<<query(1,1,num,u,v)<<'\n';
            }
        }
}
