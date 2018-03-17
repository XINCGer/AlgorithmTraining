#include <iostream>

using namespace std;


string reverseVowels(string s)
{
    int i=0,j=s.length()-1;
    if(i>j)
        return s;
    while(i<j)
    {
        while((s[j]!='a'&&s[j]!='e'&&s[j]!='i'&&s[j]!='o'&&s[j]!='u'&&s[j]!='A'&&s[j]!='E'&&s[j]!='I'&&s[j]!='O'&&s[j]!='U')&&i<j)
        {
            j--;
        }
        while((s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'&&s[i]!='A'&&s[i]!='E'&&s[i]!='I'&&s[i]!='O'&&s[i]!='U')&&i<j)
        {
            i++;
        }
        if(i!=j)
        {
            char c=s[i];
            s[i]=s[j];
            s[j]=c;
            i++;
            j--;
        }
    }
    return s;
}


int main()
{
    cout<<reverseVowels("hello")<<endl;
    cout<<reverseVowels("leetcode")<<endl;
    return 0;
}
