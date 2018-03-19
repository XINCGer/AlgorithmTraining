#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool containsDuplicate(vector<int>& nums)
{
    if(nums.empty())return false;
    sort(nums.begin(),nums.end());
    for(int i=0; i<nums.size()-1; i++)
    {
        if(nums[i] == nums[i+1])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(1);
    v1.push_back(5);
    cout<<containsDuplicate(v1)<<endl;
    return 0;
}
