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
    int num,k;cin>>num>>k;
    set<int ,greater<int>>s;
    for(int i=0;i<num;i++){
        int item;cin>>item;
        s.insert(item);
    }
    for(auto x:s){
        if(k%x==0){cout<<k/x;break;}
    }
}
