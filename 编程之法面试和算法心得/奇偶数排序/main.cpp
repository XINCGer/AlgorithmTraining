#include <iostream>
#include <vector>

using namespace std;

//头尾指针向中间扫描
bool isOddNumber(int n)
{
    return (n & 1) == 1;
}

void OddEvrnSort1(vector<int> & v)
{
    if(v.size() == 0)
    {
        return;
    }
    int mBegin = 0;
    int mEnd = v.size()-1;
    while(mBegin< mEnd)
    {
        if(isOddNumber(v[mBegin]))
        {
            mBegin++;
        }
        else if(!isOddNumber(v[mEnd]))
        {
            mEnd--;
        }
        else
        {
            swap(v[mBegin],v[mEnd]);
        }

    }
}

void OddEvrnSort2(vector<int> & v,int low,int hight){
    int i = low - 1;
    for(int j = low;j<hight;j++){
        //指向奇数的话，交换
        if(isOddNumber(v[j])){
            i = i+1;
            swap(v[i],v[j]);
        }
        swap(v[i+1],v[hight]);
    }
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(11);
    v.push_back(72);
    v.push_back(0);
    v.push_back(3);
    v.push_back(8);
    OddEvrnSort2(v,0,v.size()-1);

    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
