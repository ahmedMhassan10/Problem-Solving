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
        int num,maxi=0;cin>>num;
        vector<int>vec(num);
        set<int>s;
        for(int i=0;i<num;i++){
            cin>>vec[i];
            s.insert(vec[i]);
            maxi=max(maxi,vec[i]);
        }
        if(s.size()==1)cout<<"-1\n";
        else{
            if(vec[0]==maxi&&vec[1]<maxi)cout<<"1\n";
            else if(vec[num-1]==maxi&&vec[num-2]<maxi)cout<<num<<endl;
            else{
            for(int i=1;i<num;i++){
                if( vec[i]==maxi){
                    if(vec[i+1]<maxi||vec[i-1]<maxi){cout<<i+1<<endl;break;}
                }
            }
        }}

    }
}
