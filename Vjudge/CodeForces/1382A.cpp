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
const int N = 2e5+10 , M = 23 , mod = 1e9+7, sqr = 45;
int main()
{

        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int t;cin>>t;
        while(t--){
            int siz1,siz2;cin>>siz1>>siz2;
            map<int,int>m;
            fo(i,siz1){
                int temp;cin>>temp;
                m[temp]=i+1;
            }
            pair<int,int>p={0,0};
            fo(i,siz2){
                int temp;cin>>temp;
                if(m[temp]){
                    p={1,temp};
                }
            }
            pair<int ,int>re={0,0};
            if(p==re)cout<<"NO\n";
            else {
                cout<<"YES\n";
                cout<<p.F<<" "<<p.S<<'\n';

            }
        }
}


