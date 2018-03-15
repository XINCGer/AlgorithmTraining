#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;


int singleNumber(vector<int>& nums)
{
    if(nums.empty())
        return 0;
    map<int,int> m;
    for(int i=0; i<nums.size(); i++)
    {
        m[nums[i]]++;
    }
    for(map<int,int>::iterator it = m.begin(); it!=m.end(); it++)
    {
        if((*it).second == 1)
        {
            return (*it).first;
        }
    }
    return 0;
}


int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    cout << singleNumber(nums)<< endl;
    return 0;
}
