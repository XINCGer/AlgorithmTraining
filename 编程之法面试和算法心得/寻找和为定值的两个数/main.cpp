#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//方法1：散列映射，将所有的书放入dic中，查找另外一个数是否也在dic中
//方法2：排序夹逼

void TwoSum(vector<int> v ,int sum){
    sort(v.begin(),v.end());

    int mBegin =0;
    int mEnd = v.size()-1;

    //两头扫描或者称两个指针两端扫描法是很经典的方法，时间复杂度为O(n)
    while(mBegin <mEnd){
        long curSum = v[mBegin]+v[mEnd];
        if(curSum == sum){
            //题目只要求输出任意一对即可
            cout<<v[mBegin]<<" "<<v[mEnd]<<endl;
            //如果需要所有满足条件的数对，则打开以下两条注释并去掉break
            mBegin++;
            mEnd--;
            //break;
        }
        else{
            if(curSum <sum){
                mBegin++;
            }
            else{
                mEnd--;
            }
        }
    }
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(100);
    v.push_back(11);
    v.push_back(1);
    v.push_back(19);
    v.push_back(18);
    v.push_back(20);

    TwoSum(v,20);
    return 0;
}
