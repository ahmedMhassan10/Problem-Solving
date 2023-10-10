using namespace std;
#include<bits/stdc++.h>
typedef long long ll;




int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    int n,m;
    cin>>n>>m;
    int z=abs(n-m);
    if(z!=1){
    if(n>m ){
        cout<<"Dr. Chaz needs "<< n-m <<" more pieces of chicken!";
    }
    else{
        cout<<"Dr. Chaz will have "<<m-n<<" pieces of chicken left over!";
    }
    }
    else{
        if(n>m ){
        cout<<"Dr. Chaz needs "<< n-m <<" more piece of chicken!";
    }
    else{
        cout<<"Dr. Chaz will have "<<m-n<<" piece of chicken left over!";
    }
    }
}