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
            ll n,k;cin>>n>>k;
            if(k==1){cout<<n;return 0;}
            ll re=0;
            map<int,int>vec;
            while (n%2 == 0){
                vec[2]++;re++;
                n = n/2;
            }
            for (int i = 3; i <= sqrt(n); i = i+2){
                while (n%i == 0){
                    vec[i]++;re++;
                    n = n/i;
                }
            }
            if (n > 2){
            vec[n]++;re++;}

            if(re<k)cout<<-1;
            else if(vec.size()>k){
                ll sum=1;
                ll nu=vec.size()-k+1;
                fvec(item,vec){
                    if(nu==0)break;
                    sum*=pow(item.F,item.S);
                    vec[item.F]=0;
                    nu--;
                }
                cout<<sum<<" ";
                fvec(item,vec){
                            if(item.S==0)continue;
                            cout<<(ll)pow(item.F,item.S)<<" ";
                }
            }
            else{
                if(re==k){
                        fvec(item,vec){
                            while(item.S--)cout<<item.F<<" ";
                        }
                }else{
                    if(vec.size()==k){
                        fvec(item,vec){
                            cout<<(ll)pow(item.F,item.S)<<" ";
                        }
                    }else {
                        ll nu=k-vec.size();
                        while(nu){
                            fvec(item,vec){
                                if(nu==0)break;
                                cout<<item.F<<" ";
                                nu--;vec[item.F]--;
                            }
                        }
                        fvec(item,vec){
                            cout<<(ll)pow(item.F,item.S)<<" ";
                        }
                    }
                }
            }
}
