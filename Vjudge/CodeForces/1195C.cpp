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
const ll OO = 1e5+3, mod = 1e9 + 7, N = 1e5+3;
ll num,dp[N][3];
vector<int>vec1(N),vec2(N);
ll solve(int index,int tr){
    if(index==num)return 0;
    if(dp[index][tr]!=-1)return dp[index][tr];
    ll s1=0,s2=0,s3=0;
    if(tr!=1){
        s1=vec1[index]+solve(index+1,1);
    }
    if(tr!=2){
        s2=vec2[index]+solve(index+1,2);
    }
    s3=solve(index+1,tr);
    ll ans=maxe(s1,s2,s3);
    dp[index][tr]=ans;
    return ans;
}
int main() {
   // freopen("survive.in "," r ",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    clr(dp,-1);
    cin>>num;
    fo(i,num)cin>>vec1[i];
    fo(i,num)cin>>vec2[i];
    cout<<solve(0,0);

}
