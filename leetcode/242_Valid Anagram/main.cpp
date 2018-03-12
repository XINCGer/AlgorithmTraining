#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


//sort and solve
//bool isAnagram(string s, string t)
//{
//    sort(s.begin(),s.end());
//    sort(t.begin(),t.end());
//    if(0==s.compare(t))return true;
//    return false;
//}

//use Map solve
//bool isAnagram(string s, string t)
//{
//    if(s.length()!=t.length())return false;
//    map<char,int> m;
//
//    for(int i =0; i<s.length(); i++)
//    {
//        m[s[i]]++;
//        m[t[i]]--;
//    }
//    for(map<char,int>::iterator it = m.begin(); it!=m.end(); it++)
//    {
//        if((*it).second !=0)return false;
//    }
//    return true;
//}

//use vector solve
bool isAnagram(string s, string t)
{
    if(s.length()!=t.length())return false;
    vector<int> cnt(26,0);
    for(int i=0; i<s.length(); i++)
    {
        cnt[s[i]-'a']++;
        cnt[t[i]-'a']--;
    }
    for(int i=0; i<cnt.size(); i++)
    {
        if(cnt[i]!=0)return false;
    }
    return true;
}

int main()
{
    cout<<isAnagram("anagram","nagaram")<<endl;
    cout<<isAnagram("rat", "car")<<endl;
    return 0;
}



