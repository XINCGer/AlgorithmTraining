#include <iostream>
#include <string>
using namespace std;

//将第一个元素放到最后面
void LeftShiftOne(string &str,int n)
{
    char first = str[0]; //保存第一个元素
    for(int i=1; i<n; i++)
    {
        str[i-1] = str[i];
    }
    str[n-1] = first;
}

//旋转整个字符串 时间复杂度O(mn),空间复杂度O(1)
void LeftRotateString(string &s,int n, int m)
{
    while(m--)
    {
        LeftShiftOne(s,n);
    }
}

//反转一个字符串
void RevertString(string &str,int from,int to)
{
    while(from < to)
    {
        char t = str[from];
        str[from++] = str[to];
        str[to--] = t;
    }
}

//三步反转法，时间复杂度O(n),空间复杂度O(1)
void LeftRotateString3Step(string &s,int n,int m)
{
    //若要移动的位数大于n即字符串的长度的话，那么和%n效果一样
    m %=n;
    RevertString(s,0,m-1);
    RevertString(s,m,n-1);
    RevertString(s,0,n-1);
}

int main()
{
    string s = "abcdef";
    LeftRotateString(s,s.size(),3);
    cout<<s<<endl;
    s = "abcdef";
    LeftRotateString3Step(s,s.size(),3);
    cout<<s<<endl;
    s = "abcdef";
    LeftRotateString3Step(s,s.size(),8);
    cout<<s<<endl;
    return 0;
}
