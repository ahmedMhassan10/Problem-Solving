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
        vector<int>vec(4*num);
        for(int i=0;i<4*num;i++){
            cin>>vec[i];
        }
        sort(all(vec));
        set<int>s;
        bool tr=true;
        int index1=0,index2=4*num-1;
        while(index1<=index2&&tr){
            s.insert(vec[index1]*vec[index2]);
            if(vec[index1]!=vec[index1+1]||vec[index2]!=vec[index2-1])tr=false;
            index1+=2;index2-=2;
        }
        if(s.size()==1&&tr)cout<<"YES\n";
        else cout<<"NO\n";
    }
}
