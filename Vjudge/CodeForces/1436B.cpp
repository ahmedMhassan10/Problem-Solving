#include<bits/stdc++.h>
#define all(v)				((v).begin()), ((v).end())
using namespace std;
typedef unsigned long long ull;
typedef  long long ll;
#define pb push_back
const ll OO =10e9;
#define mine(x,y,z) min(x,min(y,z))
#define maxe(x,y,z) max(x,min(y,z))
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;cin>>t;
    while(t--){
        int num;cin>>num;
        for(int i=0;i<num-1;i++){
            for(int j=0;j<num-1;j++){
                if(j==i){
                  cout<<"1 1 ";
                }
                else cout<<"0 ";
            }
            cout<<'\n';
        }
        for(int i=0;i<num;i++){
            if(i==0||i==num-1)cout<<"1 ";
            else cout<<"0 ";
        }
                    cout<<'\n';

    }
}
