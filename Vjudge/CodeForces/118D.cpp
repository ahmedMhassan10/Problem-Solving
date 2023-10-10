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
const ll OO = 1e5+3, mod = 1e8 , N = 103;
ll num1,num2,k1,k2;
ll dp[N][N][11][11];
ll solve(int index1,int index2,int counter1,int counter2){
    if(index1==num1&&index2==num2)return 1;
    if(dp[index1][index2][counter1][counter2]!=-1)return dp[index1][index2][counter1][counter2];
    ll s1=0,s2=0,s3=0;
    if(counter1<k1&&index1<num1){
        s1=+solve(index1+1,index2,counter1+1,0);
    }
    if(counter2<k2&&index2<num2){
        s2=+solve(index1,index2+1,0,counter2+1);
    }
    s3=s1+s2;
    s3=(s3+mod)%mod;
    dp[index1][index2][counter1][counter2]=s3;
    return s3;
}
int main() {
   // freopen("survive.in "," r ",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    clr(dp,-1);
    cin>>num1>>num2>>k1>>k2;
    cout<<solve(0,0,0,0);
}
