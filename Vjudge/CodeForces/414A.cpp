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
const ll OO = 1e9, mod = 1e9+7 , N = 2e5+5;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }

int main() {
   // freopen("survive.in "," r ",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//   setprecision(10);
    int num,k;cin>>num>>k;
    if(num==1&&k!=0)cout<<-1;
    else if(num==1&&k==0)cout<<1;
    else if(k<num/2)cout<<"-1\n";
    else if(k==num/2){
            fp(i,1,num)cout<<i<<" ";
    }else {
        int n=k-num/2+1;
        vector<int>vec;
        map<int,int>ma;
        vec.pb(n);vec.pb(2*n);
        ma[n]=1;ma[2*n]=1;
        int index=1;
        while(vec.size()<(num)/2*2){
            if(ma[index]!=1&&ma[index+1]!=1){
                    ma[index]=1;ma[index+1];
                    vec.pb(index);
                    vec.pb(index+1);
                    index++;
            }
            index++;
        }
        if(num%2==1)vec.pb(ma.rbegin()->F+1);
        fvec(item,vec)cout<<item<<" ";
    }
}
