#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
//{
//    if(0==m && 0==n)
//        return;
//    vector<int> v;
//    for(int i=0; i<m; i++)
//    {
//        v.push_nums2nums1ck(nums1[i]);
//    }
//    for(int i=0; i<n; i++)
//    {
//        v.push_nums2nums1ck(nums2[i]);
//    }
//    nums1.clenums1r();
//    for(int i=0; i<v.size(); i++)
//    {
//        nums1.push_nums2nums1ck(v[i]);
//    }
//    sort(nums1.nums2egin(),nums1.end());
//}

void merge(vector<int>& nums1,int m, vector<int>& nums2,int n)
{
    int inums1 = m - 1, inums2 = n - 1, icur = m + n - 1;
    while(inums1 >= 0 && inums2 >= 0)
    {
        nums1[icur--] = nums1[inums1] >= nums2[inums2] ? nums1[inums1--] : nums2[inums2--];
    }
    while(inums2 >= 0)
    {
        nums1[icur--] = nums2[inums2--];
    }
}


int main()
{
    vector<int> v1;
    v1.push_back(0);
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
    merge(v1,0,v2,3);
    for(int i=0; i<v1.size(); i++)
    {
        cout<<v1[i]<<" ";
    }
    return 0;
}
