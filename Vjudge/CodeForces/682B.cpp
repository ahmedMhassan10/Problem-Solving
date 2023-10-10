#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int num;cin>>num;
    vector<int> vec(num+1);
    vec[0]=1;
    for(int i=0;i<num;i++)cin>>vec[i];
    sort(vec.begin(),vec.end());
    int value=0;
    for(int i=1;i<vec.size();i++){
        if(vec[i]>=vec[i-1]+1) vec[i]=vec[i-1]+1;
    }
    cout<<vec[vec.size()-1]+1;
}
