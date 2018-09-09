#include <iostream>
#include <string>

using namespace std;

// 时间复杂度O(n),空间复杂度O(1)
bool isPalindrome(const string& s){
    if(s.size() < 1){
        return false;
    }
    int sFront = 0;
    int sBack = s.size() -1;
    while(sFront < sBack){
        if(s[sFront] != s[sBack]){
            return false;
        }
        ++sFront;
        -- sBack;
    }
    return true;
}

bool isPalindrome2(const string& s){
    if(s.size() <1){
        return false;
    }
    int n = s.size();
    int m = ((n>>1) -1) >= 0 ? (n>>1)-1 :0;
    int sFirst = m;
    int sBack = n-1-m;

    while(sFirst >= 0){
        if(s[sFirst] != s[sBack]){
            return false;
        }
        -- sFirst;
        ++ sBack;
    }
    return true;
}


int main()
{
    string s = "aabb";
    string ss = "level";
    cout<<isPalindrome(s)<<endl;
    cout<<isPalindrome(ss)<<endl;

    cout<<isPalindrome2(s)<<endl;
    cout<<isPalindrome2(ss)<<endl;
    return 0;
}
