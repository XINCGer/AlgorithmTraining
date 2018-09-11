#include <iostream>
#include <string>

using namespace std;

//中心拓展法
int LongestPalindrome(const string& s){
    int i,j,mmax,c;
    if(s.size() < 1){
        return 0;
    }
    mmax = 0;

    //i为回文的中心位置
    for(i =0;i<s.size();++i){
        //回文长度为奇数
        for(j=0;(i-j >=0) && (i+j < s.size());++j){
            if(s[i-j] != s[i+j]){
                break;
            }
            c = j*2+1;
        }
        if(c>mmax){
            mmax = c;
        }
        //回文长度为偶数 leel
        for(j =0;(i-j>=0) && (i+j+1 < s.size());++j){
            if(s[i-j] != s[i+j+1]){
                break;
            }
            c = j*2+2;
        }
        if(c>mmax){
            mmax = c;
        }
    }
    return mmax;
}
void Manacher(){
    int i;
    int mx =0;
    int id;
    for(i =1;i<n;i++){
        //mx > i时，p[i] >= Min(p[2*id-i],mx-i)
        if(mx>i){
            p[i] = min(p[2*id-i],mx-i);
        }
        else{
            p[i] =1;
        }
        while(s[i+p[i] == s[i-p[i]){
            p[i]++;
        }
        if(p[i]+i > mx){
            mx = p[i]+i;
            id = i;
        }
    }
}

int main()
{
    string s = "hello";
    string ss = "leelevel";
    cout<<LongestPalindrome(s)<<endl;
    cout<<LongestPalindrome(ss)<<endl;
    return 0;
}
