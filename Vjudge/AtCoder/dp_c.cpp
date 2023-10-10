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
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef unsigned long long ull;
typedef long long ll;
const ll OO = 1e17, mod = 1e9 + 7, N = 1e5+5;
ll dp[N][4],num,k;
bool vis[N][4];
struct edge{
    ll a,b,c;
};
vector<edge>vec(N);
ll solve(ll index,ll pre){
    if(index==num)return 0;
   if(vis[index][pre])return dp[index][pre];
    ll s1=0,s2=0,s3=0;
    vis[index][pre]=1;
    if(pre!=1){
        s1=solve(index+1,1)+vec[index].a;
      //cout<<s1<<" "<<pre<<" "<< index<<endl;
    }
     if(pre!=2){
        s2=solve(index+1,2)+vec[index].b;
       //cout<<s2<<" "<<pre<<" "<< index<<endl;
    }
     if(pre!=3){
        s3=solve(index+1,3)+vec[index].c;
        //cout<<s3<<" "<<pre<<" "<< index<<endl;
    }
    ll  ans=maxe(s3,s2,s1);
    dp[index][pre]=ans;
    return ans;
}
int main() {
   // freopen("survive.in "," r ",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>num;
    fo(i,num){
        cin>>vec[i].a>>vec[i].b>>vec[i].c;
        //cout<<vec[i].a<<vec[i].b<<vec[i].c<<endl;
    }
    cout<<solve(0,0)<<'\n';
}
