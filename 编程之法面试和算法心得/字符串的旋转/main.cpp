#include <iostream>
#include <string>
using namespace std;

//将第一个元素放到最后面
void LeftShiftOne(string &str,int n){
    char first = str[0]; //保存第一个元素
    for(int i=1;i<n;i++){
        str[i-1] = str[i];
    }
    str[n-1] = first;
}

//旋转整个字符串 时间复杂度O(mn),空间复杂度O(1)
void LeftRotateString(string &s ,int n, int m){
    while(m--){
        LeftShiftOne(s,n);
    }
}

int main()
{
    string s = "abcdef";
    LeftRotateString(s,s.size(),3);
    cout<<s<<endl;
    return 0;
}
