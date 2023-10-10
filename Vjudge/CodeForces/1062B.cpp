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
            while (n%2 == 0){
                ma[2]++;
                n = n/2;
            }
            for (int i = 3; i <= sqrt(n); i = i+2){
                while (n%i == 0){
                        ma[i]++;
                    n = n/i;
                }
            }
            if (n > 2){
                        ma[n]++;
            }

}
int main() {
        // freopen("survive.in "," r ",stdin);
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int num;cin>>num;
        if(num==1){cout<<1<<" 0";return 0;}
        PrimeFactors(num);
        ll re=1,maxi=0,mini=OO,maxi2=0;
        int odds=0,evens=0,ones=0;
        fvec(item,ma){
            re*=item.F;
            if(item.S==1)ones++;
            if(item.S%2==1){odds++;maxi2=max(maxi2,item.S);}
            else {
                    evens++;
                    mini=min(mini,item.S);
                    maxi=max(maxi,item.S);
            }
        }
        if(ones==ma.size()){cout<<num<<" 0";return 0;}
        if(odds==0){
            if(mini==maxi&&__builtin_popcount(maxi)==1){
                cout<<re<<" "<<round(log2(maxi));
            }else if(__builtin_popcount(maxi)==1){
                cout<<re<<" "<<round(log2(maxi))+1;
            }
            else cout<<re<<" "<<(int)log2(maxi)+2;
        }else{
            if(maxi>maxi2&&__builtin_popcount(maxi)==1){
                cout<<re<<" "<<round(log2(maxi))+1;
            }else if(maxi>maxi2){
                cout<<re<<" "<<(int)log2(maxi)+2;
            }else cout<<re<<" "<<(int)log2(maxi2)+2;
        }
}
