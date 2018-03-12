#include <iostream>
#include <algorithm>
using namespace std;


//先排序再比较
bool isAnagram(string s, string t)
{
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    if(0==s.compare(t))return true;
    return false;
}

int main()
{
    cout<<isAnagram("anagram","nagaram")<<endl;
    cout<<isAnagram("rat", "car")<<endl;
    return 0;
}



