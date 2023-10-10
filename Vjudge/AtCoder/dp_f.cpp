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
const ll OO = 1e5+5, mod = 1e9 + 7, N =  3000+5;
string str1,str2;
int dp[N][N];
ll solve(int fi,int se){
    if(fi==siz(str1)||se==siz(str2))return 0;
    if(dp[fi][se]!=-1)return dp[fi][se];
    int s1=0,s2=0,ans=0;
    if(str1[fi]==str2[se]){
        ans= 1+solve(fi+1,se+1);
    }else{
     s1=solve(fi+1,se),s2=solve(fi,se+1);}
     ans= maxe(ans,s1,s2);
    dp[fi][se]=ans;
    return ans;
}
void path(int fi,int se){
    if(fi==siz(str1)||se==siz(str2))return ;
    if(str1[fi]==str2[se]){
            cout<<str1[fi];
            path(fi+1,se+1);
    }else{
    ll s1=solve(fi+1,se),s2=solve(fi,se+1);
    if(s1>=s2){
            path (fi+1,se);
    }else path(fi,se+1);
}}
int main() {
   // freopen("survive.in "," r ",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
  // cin>>t;
    while(t--){
        clr(dp,-1);
        cin>>str1>>str2;
        path(0,0);
    }
}
