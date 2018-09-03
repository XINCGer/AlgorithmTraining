#include <iostream>
#include <string>

using namespace std;

//²»¿¼ÂÇÒç³ö
int string2IntSimple(string &s){
    int n = 0;
    for(int i=0;i<s.size();i++){
        int num = s[i]-'0';
        n = n*10+num;
    }
    return n;
}

int main()
{
    string s = "12345";
    cout<<string2IntSimple(s)<<endl;
    return 0;
}
