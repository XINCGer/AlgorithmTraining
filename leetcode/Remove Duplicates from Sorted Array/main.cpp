#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


int removeDuplicates(vector<int>& nums) {
    //unique()函数将重复的元素放到vector的尾部 然后返回指向第一个重复元素的迭代器
    //再用erase函数擦除从这个元素到最后元素的所有的元素
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    return nums.size();
}

int removeDuplicates(vector<int>& nums)
{
    if (nums.empty()) return 0;
    int index = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[index] != nums[i])
            nums[++index] = nums[i];
    }
    return index + 1;
}


int main()
{

    return 0;
}
