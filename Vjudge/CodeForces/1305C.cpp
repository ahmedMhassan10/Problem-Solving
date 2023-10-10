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
        int n,m;cin>>n>>m;
        if(n>m)cout<<0;
        else{
        vector<int>vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        bool tr=true;ll sum=1;
        for(int i=0;i<n&&tr;i++){
            for(int j=i+1;j<n&&tr;j++){
                sum=(sum*abs(vec[j]-vec[i]))%m;
                if(sum==0)tr=false;
            }
        }
        cout<<sum<<endl;
}}
