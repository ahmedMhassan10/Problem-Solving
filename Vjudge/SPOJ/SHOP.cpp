#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define clr(v, d)			memset(v, d, sizeof(v))
#define ll long long

#define int long long

#define setp(item) cout<<fixed<<setprecision(item);
#define PI 3.14159265358979323846264338327950

int ceilSqrt(int a){
    return ::ceil(sqrtl(a));
}
int  divC(int a,int b){
    return a/b+(a%b!=0);
}
int gcd(int a, int b) { return ((b == 0) ? a : gcd(b, a % b)); }
int lcm(int a,int b){return (a*b)/gcd(a,b);}
const int OO =1e18, mod = 1e9+7,mod2=1e9+9, N =2e5+5,M=30,MOD= 998244353, minOO=LLONG_MIN;

///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة

/// a33333333333333333333333333333333333333333333333333333333333333333333333333333333333333
vector<int>dx={-1,1,0,0},dy={0,0,-1,1};
ll n,m;

void func(int index){
        vector<string >vs(n);
        ll stX,stY,disX,disY;
        for (int i = 0; i < n; ++i) {
            cin>>vs[i];
            for (int j = 0; j < m; ++j) {
                if(vs[i][j]=='D'){
                    disX=i,disY=j;
                }
                if(vs[i][j]=='S'){
                    stX=i,stY=j;
                }
            }
        }
        vector<vector<int>>dist(n,vector<int>(m,OO));

        dist[stX][stY] = 0;
        priority_queue< pair < ll, pair<int,int> >> pq;
        pq.push({0,{stX,stY}});
        while(!pq.empty())
        {
            ll x = pq.top().second.first,y=pq.top().second.second , distance = -pq.top().first;
            pq.pop();
            if(distance > dist[x][y])
                continue;
            if(x==disX&&y==disY){
                cout<<distance<<'\n';
                return;
            }
            for(int i=0;i<4;i++)
            {
                ll xx=x+dx[i],yy=y+dy[i];
                if(xx<0||yy<0||xx>=n||yy>=m||vs[xx][yy]=='X')continue;

                ll cost=0;
                if(vs[xx][yy]!='D')
                cost=vs[xx][yy]-'0';
                if(dist[x][y] + cost< dist[xx][yy])
                {
                    dist[xx][yy] = dist[x][y] + cost;
                    pq.push({-dist[xx][yy],{xx,yy}});
                }
            }
        }

}
signed main() {
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
//    cin>>t;
    ll index=1;
    while (cin>>m>>n){
        if(n==0&&m==0)break;
        func(index++);
    }
    return 0;
}