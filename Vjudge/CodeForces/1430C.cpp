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
            stack<int>ss;
            vector<pair<int,int>>vec;
            for(int i=1;i<=num;i++){
                ss.push(i);
            }
            while(ss.size()>1){
                int num1=ss.top();ss.pop();
                int num2=ss.top();ss.pop();
                vec.pb(make_pair(num1,num2));
                ss.push(ceil((num1+num2)/2.0));
            }
            cout<<ss.top()<<endl;
            for(int i=0;i<vec.size();i++){
                cout<<vec[i].second<<" "<<vec[i].first<<endl;
            }
    }
}
