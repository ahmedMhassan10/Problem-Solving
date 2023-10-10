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
typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef unsigned long long ull;
typedef  long long ll;
const ll OO =10e7;
const int N=200005;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        ll num,m;cin>>num>>m;
        map<ull,ull>mm;
        fo(i,num){
            ull x,y;cin>>x>>y;
            mm[x]+=y;
        }
        int s=mm.size();
        ll maxi=0,re=0;
        vector<pair<ll,ull>>vec;
        fvec(it,mm){
            vec.pb({it.first,it.second});
        }
        s=vec.size();
        int index1=0,index2=0;
        while(index1<s&&index2<s){
            if(vec[index2].first-vec[index1].first<m){
                re+=vec[index2].second;
                index2++;
            }else {
                re-=vec[index1].second;
                index1++;
            }
            maxi=max(re,maxi);
        }
        cout<<maxi;
}

