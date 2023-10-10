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
const ll OO = 1e5+3, mod = 1e8 , N = 200;
ll num1,num2,dp[N][N];
vector<int>vec1(N),vec2(N);
ll solve(int index1,int index2){
    if(index1>num1||index2>num2) return 0;
    if(dp[index1][index2]!=-1)return dp[index1][index2];
    ll s1=0,s2=0,s3=0;

    s3=solve(index1+1,index2+1)+vec1[index1]+vec2[index2];
    s1=solve(index1+1,index2)+vec1[index1];
    s2=solve(index1,index2+1)+vec2[index2];
    ll ans=maxe(s1,s2,max((ll)0,s3));
    dp[index1][index2]=ans;
    return ans;
}
int main() {
   // freopen("survive.in "," r ",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        clr(dp,-1);vec1.clear(),vec2.clear();
        cin>>num1;
        fp(i,1,num1)cin>>vec1[i];
        cin>>num2;
        fp(i,1,num2)cin>>vec2[i];
        cout<<solve(1,1)<<'\n';
    }
}