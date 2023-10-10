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
const ll OO = 1e9, mod = 1e9 + 7,mod2=1e9+9, N = 100+10;
int fail[N];

void KMP( string &st)
{
    for ( int i = 1 ; i < st.size() ; i++){
        int j = fail[i-1];
        while(j > 0 and st[i] != st[j])
            j = fail[j-1];
        if(st[i] == st[j])
            fail[i] = j+1;
        else
            fail[i] = 0;
    }
}
string st1 , st2, virus;
int dp[N][N][N];
int solve ( int i , int j , int mtch)
{
    if ( i == st1.size() || j == st2.size())
        return 0;
    int &ret = dp[i][j][mtch];
    if(~ret)
        return ret;
    if(st1[i] == st2[j])
    {
        // skip
        ret = solve(i+1,j+1,mtch);
        while(mtch > 0 and st1[i] != virus[mtch])
            mtch = fail[mtch-1];
        if(st1[i] == virus[mtch])
            mtch++;
        // take
        if(mtch != virus.size())
            ret = max(ret,1 + solve(i+1,j+1,mtch));
    }
    else
        ret = max(solve(i+1,j,mtch),solve(i,j+1,mtch));
    return ret;
}
string ans ;
void build ( int i , int j , int mtch)
{
    if(i == st1.size() || j == st2.size())
        return ;
    int ret = solve(i,j,mtch);
    if(st1[i] == st2[j])
    {
        if(solve(i+1,j+1,mtch) == ret)
            build(i+1,j+1,mtch);
        else
        {
            ans.push_back(st1[i]);
            while(mtch > 0 and st1[i] != virus[mtch])
                mtch = fail[mtch-1];
            if(st1[i] == virus[mtch])
                mtch++;
            build(i+1,j+1,mtch);
        }
    }
    else
    {
        if(solve(i+1,j,mtch) > solve(i,j+1,mtch))
            build(i+1,j,mtch);
        else
            build(i,j+1,mtch);
    }
}
void testCase() {
    cin >> st1 >> st2 >> virus;
    KMP(virus);
    memset(dp,-1,sizeof dp);
    build(0,0,0);
    if(ans.empty())
        cout << "0\n";
    else
        cout << ans << '\n';
}
int main()
{
        testCase();
}
