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
ll maxi=0;
map<int,ll>ma;
void PrimeFactors(ll n) {
            vector<bool> vis(n+4);
            while (n%2 == 0){
                if(vis[2]==false){
                    ma[2]++;vis[2]=true;
                    maxi=max(maxi,ma[2]);
                }
                n = n/2;
            }
            for (int i = 3; i <= sqrt(n); i = i+2){
                while (n%i == 0){
                    if(vis[i]==false){
                        ma[i]++;vis[i]=true;
                        maxi=max(maxi,ma[i]);
                    }
                    n = n/i;
                }
            }
            if (n > 2){
                if(vis[n]==false){
                        ma[n]++;vis[n]=true;
                        maxi=max(maxi,ma[n]);
                }
            }

}
int main() {
           // freopen("survive.in "," r ",stdin);
            ios_base::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            int num;cin>>num;
            vector<int>vec(num);
            fo(i,num){
                cin>>vec[i];
                PrimeFactors(vec[i]);
            }
            cout<<max(maxi,(ll)1);
}
