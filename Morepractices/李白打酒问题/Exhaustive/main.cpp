//题目描述：
// 话说大诗人李白，一生好饮。幸好他从不开车。
//一天，他提着酒壶，从家里出来，酒壶中有酒2斗。他边走边唱：
// 无事街上走，提壶去打酒。
//逢店加一倍，遇花喝一斗。
//
//这一路上，他一共遇到店5次，遇到花10次，已知最后一次遇到的是花，他正好把酒喝光了。
//请你计算李白遇到店和花的次序，可以把遇店记为a，遇花记为b。
//则：babaabbabbabbbb 就是合理的次序。像这样的答案一共有多少呢？
//请你计算出所有可能方案的个数（包含题目给出的）

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isFit(char* str){
    int value =2;
    str[14]='b';
    for(int i=0;i<15;i++){
        if(str[i]=='a')value*=2;
        else if(str[i]=='b')value-=1;
    }
    if(value ==0)return true;
    else return false;
}
int main()
{
    int sum=0;
    char ss[16] = "aaaaabbbbbbbbb";
    sort(ss,ss+14);
    while(next_permutation(ss,ss+14)){
            if(isFit(ss)){
                sum++;
            }
    }
    cout<<sum<<endl;
}
