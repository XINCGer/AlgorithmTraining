#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//µ›πÈ µœ÷
void CalcAllPermutation(string &s,int from , int to){
    if(to<=1){
        return;
    }
    if(from == to){
        for(int i=0;i<=to;i++){
            cout<<s[i];
        }
        cout<<endl;
    }
    else{
        for(int j=from;j<=to;j++){
            swap(s[j],s[from]);
            CalcAllPermutation(s,from+1,to);
            swap(s[j],s[from]);
        }
    }
}
int main()
{
    string ss= "abcd";
    CalcAllPermutation(ss,0,ss.size()-1);
    return 0;
}
