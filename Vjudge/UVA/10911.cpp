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
typedef vector<pair<double,double>> vp;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef unsigned long long ull;
typedef long long ll;
#define setp(item) cout<<fixed<<setprecision(item);
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO = 1e9, mod = 1e9 + 7, N = 18;
double getdist(double x1,double x2,double y1,double y2){
        double ans=pow(abs(x1-x2),2)+pow(abs(y1-y2),2);
        return sqrt(ans);
}
int num;
vp vec(N);
vd dp(66000,-1);
double solve(int msk){

    if(msk==(1<<num)-1){
        //cout<<3<<'\n';
        return 0;
    }
    if(abs(dp[msk]+1)>1e-4)return dp[msk];
    double ans=1e9;
    fo(i,num){
        if(msk&(1<<i)){
                   // cout<<2<<" "<<msk<<" "<<step<<'\n';
                    continue;
        }
        fp(j,i+1,num-1){

            if((msk&(1<<j))){
                    //cout<<1<<'\n';
                    continue;
            }

           // cout<<"4 "<<" "<<i<<" "<<j<<" "<<(msk|(1 << i)|(1 << j))<<'\n';
            ans=min(ans,getdist(vec[i].F,vec[j].F,vec[i].S,vec[j].S)+solve(msk|(1 << i)|(1 << j)));
        }
    }
    return dp[msk]=ans;
}
int main() {
       // freopen("survive.in "," r ",stdin);
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int index=1;
        while(cin>>num){
            if(num==0)break;
            num=num*2;
            vec.clear();
            dp.assign(66000,-1);
            fo(i,num){
                string str;cin>>str;
                cin>>vec[i].F>>vec[i].S;
            }
            setp(2);
            cout<<"Case "<<index++<<": "<<solve(0)<<'\n';
        }
}
