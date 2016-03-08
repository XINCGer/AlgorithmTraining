#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

vector<string> split(const char* src,const char *cmp){
    vector<string> strList;
    int size = strlen(src);
    string srcBak = string(src);
    int startIndex =0;
    int endIndex =0;
    endIndex = srcBak.find(cmp);
    string lineStr;
    while(endIndex>0){
        lineStr = srcBak.substr(startIndex,endIndex);
        strList.push_back(lineStr);
        srcBak = srcBak.substr(endIndex+1,size);
        endIndex = srcBak.find(cmp);
    }
    if(srcBak.compare("")!=0){
        strList.push_back(srcBak);
    }
    return strList;
}
int main()
{
    vector<string> v = split("a#b#c","#");
    for(vector<string>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}
