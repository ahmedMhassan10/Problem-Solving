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
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<pair<ll,ll>> vp;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
#define setp(item) cout<<fixed<<setprecision(item);
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO = 1e9, mod = 1e9 + 7,mod2=1e9+9, N = 5e5+10,M=25;

int sp[N][M] , sp2[N][M] , a[N] , lg[N]  ,n;
void buildSparse(){
    lg[1] = 0 ;
    for(int i =2;i <=n ; i++){
        lg[i] = lg[i/2]+1;
    }
    for(int i = 0 ; i< n; i++){
        sp[i][0] = a[i] ;
        sp2[i][0] = a[i];
    }
    for(int i = 1;i<M ; i++){
        for(int j = 0 ; j + (1<<i)<= n ;j++){
            sp[j][i] = max(sp[j][i-1], sp[j+(1<<(i-1))][i-1]);            sp2[j][i] = min(sp2[j][i-1], sp2[j+(1<<(i-1))][i-1]);

        }
    }


}

int qsum(int l , int r)
{
    int dist = r-l+1;
    int sum = 1e9 ;
    for(int i = M-1;i>=0;i--){
        if((1<<i) <= dist){
            dist -= (1<<i);
            sum += sp[l][i];
            l += (1<<i);
        }
    }
    return sum;
}

ll qmax(int l , int r)
{
    if(l>r)
        return 0;
    int j = lg[r-l+1];
    return max(sp[l][j],sp[r-(1<<j)+1][j]);
}
ll qmin(int l , int r)
{
    if(l>r)
        return 0;
    int j = lg[r-l+1];
    return min(sp2[l][j],sp2[r-(1<<j)+1][j]);
}

int main() {
        // freopen("survive.in "," r ",stdin);
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int t;cin>>t;
        while(t--){

            ll k;cin>>n>>k;
            string str;cin>>str;
            ll re=0;
            fo(i,n){
                if(str[i]=='-')re--;
                else re++;
                a[i]=re;
            }
          //  n++;
            buildSparse();
            while(k--){
                ll l,r;cin>>l>>r;l--,r--;

                ll dist=a[r],mx1=max((ll)0,qmax(0,l-1)), mn1=min((ll)0,qmin(0,l-1)),mx2=qmax(r+1,n-1),mn2=qmin(r+1,n-1);
               // cout<<mx1<<" "<<mn1<<" "<<mx2<<" "<<mn2<<'\n';

                if(l>0)dist-=a[l-1];
                mx2-=dist;mn2-=dist;
                if(r!=n-1){
                    mn1=min(mn1,mn2);
                    mx1=max(mx1,mx2);
                }
                //cout<<mx1<<" "<<mn1<<" "<<mx2<<" "<<mn2<<'\n';
                cout<<mx1-mn1+1<<'\n';
            }
        }
        return 0;
}
