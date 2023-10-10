#include <iostream>
#include<cmath>
#include<algorithm>
#include<sstream>
#include<cstring>
#include<vector>
#include<stack>
#include <cstdio>
#include <set>
#include <iomanip>
#include<numeric>
#include <iomanip>

using namespace std;
typedef long long ll;
static vector<int>vec(10);
void solve(vector<int> &vec,int index,int value,string str){
    if(index==str.length()){
        vec.push_back(value);
       }
    else if(str[index]=='+'){
        solve(vec,index+1,value+1,str);}
    else if(str[index]=='-'){
         solve(vec,index+1,value-1,str);}
    else if(str[index]=='?'){
        solve(vec,index+1,value+1,str);
        solve(vec,index+1,value-1,str);}
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string str1,str2;cin>>str1>>str2;
    vector<int>vec;
    vector<int>vec2;
    solve(vec,0,0,str1);
    solve(vec2,0,0,str2);
    double number= count(vec2.begin(),vec2.end(),vec[0]);
     std::cout << std::fixed << std::setprecision(12)<<number/vec2.size();
}