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
        int siz1,siz2;cin>>siz1>>siz2;
        vector<int>vec1(siz1),vec2(siz2);
        fo(i,siz1)cin>>vec1[i];
        fo(i,siz2)cin>>vec2[i];
        sort(all(vec1));
        fo(i,siz2){
            cout<<upper_bound(all(vec1),vec2[i])-vec1.begin()<<" ";
        }
}

