#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//蛮力轮训,时间复杂度O(mn)
bool StringContain(string &a,string &b)
{
    for(int i=0; i<b.size(); i++)
    {
        int j;
        for(j =0; (j<a.size() && a[j]!=b[i]); ++j);
        if(j>=a.size())
        {
            return false;
        }
    }
    return true;
}

//排序后轮询，O(mlogm)+O(nlogn)+O(m+n)
bool StringContainWithSort(string &a,string &b)
{
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    for(int pa=0,pb =0; pb<b.size();)
    {
        while((pa<a.size()) && (a[pa] < b[pb]))
        {
            ++pa;
        }
        if(pa>=a.size() || a[pa]>b[pb])
        {
            return false;
        }
        ++pb;
    }
    return true;
}

int main()
{
    string a = "ABCD";
    string b = "AA";
    string c = "BCD";
    string d = "BCDE";
    cout<<StringContain(a,b)<<endl;
    cout<<StringContain(a,c)<<endl;
    cout<<StringContain(a,d)<<endl;
    cout<<"---------------"<<endl;
    cout<<StringContainWithSort(a,b)<<endl;
    cout<<StringContainWithSort(a,c)<<endl;
    cout<<StringContainWithSort(a,d)<<endl;
    return 0;
}
