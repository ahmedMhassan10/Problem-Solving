#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ull n,a,b,c;cin>>n>>a>>b>>c;
    ull total=0;
        if(n%4==3){
            if(3*c<a&&3*c<b+c)
                total=3*c;
            else if (b+c<a)
                total=b+c;
            else total=a;
        }else if(n%4==2){
            if(b<2*c&&b<2*a){
                total=b;
            }else if(a<c){
                total=2*a;
            }else total=2*c;
        }else if(n%4==1){
            if(c<3*a&&c<a+b)total=c;
            else if(2*a<b)total=3*a;
            else total=a+b;
        }
    cout<<total;
}
