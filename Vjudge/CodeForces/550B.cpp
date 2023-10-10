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
#define maxe(x, y, z) max(x, min(y, z))
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
const ll OO = 1e15, mod = 1e9 + 7, N = 1e5;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,l,r,x;cin>>n>>l>>r>>x;
    vll vec(n);
    ll maxi=0;
    fo(i,n)cin>>vec[i];
    for (int b = 0; b < (1<<n); b++) {
        ll sum=0,counter=0,mini=OO,maxii=0;
        for (int i = 0; i < n; i++) {
                if (b&(1<<i)) {
                    sum+=vec[i];
                    mini=min(vec[i],mini);maxii=max(maxii,vec[i]);
                    counter++;
                }
        }
        if(maxii-mini>=x&&sum>=l&&sum<=r&&counter>=2){
            maxi++;
        }
    }
    cout<<maxi;
}
