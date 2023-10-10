#include<bits/stdc++.h>
using namespace std;
#define all(v)				((v).begin()), ((v).end())
#define siz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define fo(i, n)		for(int i=0;i<(int)(n);++i)
#define fp(i, j, n)	for(int i=(j);i<=(int)(n);++i)
#define fn(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define fvec(i,vec) for(auto i:vec)
#define pb				push_back
#define MP			make_pair
#define mine(x,y,z) min(x,min(y,z))
#define maxe(x,y,z) max(x,min(y,z))
#define F first
#define S second
typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef unsigned long long ull;
typedef  long long ll;
const ll OO =5*10e5+5;
const int N =10e5+10 , M = 23 , mod = 1e9+7, sqr = 45;

int main()
{

        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        ll n,st,en;cin>>n>>st>>en;
        vector<ll>vec(n);
        fo(i,n)cin>>vec[i];
        ll maxi=0;
        vector<ll>vec2;
        for (int b = 0; b < (1<<min(n,(ll)18)); b++) {
            ll sum=0;
            for (int i = 0; i < min(n,(ll)18); i++) {
                    if (b&(1<<i)){
                        sum+=vec[i];
                    }
            }
            vec2.push_back(sum);
            if(sum>=st&&sum<=en)maxi++;
        }
        if(n<=18)cout<<maxi<<'\n';
        else {
            ll maximum=0;
            sort(all(vec2));
            for (int b = 0; b < (1<<(n-18)); b++) {
            ll sum=0;
            for (int i = 0; i < (n-18); i++) {
                    if (b&(1<<i)){
                        sum+=vec[i+18];
                    }
            }
            maximum+=(ll)(upper_bound(all(vec2),en-sum)
            -lower_bound(all(vec2),st-sum));
        }
        cout<<maximum<<'\n';
    }
}


