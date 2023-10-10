#include<bits/stdc++.h>
#define all(v)				((v).begin()), ((v).end())
const int OO = (int)1000000000;
using namespace std;
typedef unsigned long long ull;
typedef  long long ll;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int num,counter=0;cin>>num;
    string str;cin>>str;
    if(num>=1)counter++;
    for(int i=1;i<num;i++){
        if(str[i]!=str[i-1])counter++;
    }
    cout<<counter;
}

