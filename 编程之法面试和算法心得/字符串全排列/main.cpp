#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//递归实现
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

//字典序
bool CalcAllPermutationDic(string &s, int num){
    int i;
    //step1:找出排列中最后(最右)一个升序的首位位置i, x=ai
    for(int i=num-2;(i>=0) && (s[i]>=s[i+1]); --i){
        ;
    }
    //已经找到所有排列
    if(i<0){
        return false;
    }
    int k;
    //step2:找到排列中第i位右边最后一个比ai大的位置j,y=ai
    for(k = num-1;(k>i) && (s[k]<=s[i]);--k){
        ;
    }
    //step3:交换x,y
    swap(s[i],s[k]);
    //step4:把第i+1位到最后的部分翻转;
    reverse(s.begin()+i+1,s.begin()+num);
    return true;
}

int main()
{
    string ss= "abcd";
    CalcAllPermutation(ss,0,ss.size()-1);
    return 0;
}
