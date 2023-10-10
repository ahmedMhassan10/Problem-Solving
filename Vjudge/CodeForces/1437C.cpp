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
const ll OO = 1e9, mod = 1e8 , N = 400;
vector<ll>vec(N);
ll num,dp[N][N];
ll solve(int index1,int index2){
    if(index2>=N)return OO;
    if(index1>=num) {
                return 0;
    }
    if(dp[index1][index2]!=-1)return dp[index1][index2];
    ll s1=0,s2=0;
    s1+=solve(index1+1,index2+1)+abs(vec[index1]-index2);
    s2+=solve(index1,index2+1);

    ll ans =min(s1,s2);
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
        clr(dp,-1);
        vec.clear();
        cin>>num;
        fo(i,num)cin>>vec[i];
        sort(vec.begin(),vec.begin()+num);
        cout<<solve(0,1)<<'\n';
    }
}
