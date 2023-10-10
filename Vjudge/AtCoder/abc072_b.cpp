#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int main()
{
    string str1,str2;cin>>str1;

    for(int i=0;i<str1.size();i++){
        if(i%2==0) str2+=str1[i];
    }
    cout<<str2;
    return 0;
}
