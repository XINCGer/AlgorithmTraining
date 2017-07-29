#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);


    return 0;
}

//next_permutation库解法
/*
vector< vector<int> > permute(vector<int>& nums){
    vector< vector<int> > result;
    sort(nums.begin(),nums.end());
    do{
        result.push_back(nums);
    }while(next_permutation(nums.begin(),nums.end()));
    return result;
}
*/

void dfs(vector<int>&num,int begin,vector< vector<int> >& result){
    if(begin>=num.size()){
        result.push_back(num);
        return;
    }

    for(int i=begin;i<num.size();i++){
        swap(num[begin],num[i]);
        dfs(num,begin+1,result);
        swap(num[begin],num[i]);
    }
}

//DFS解法
vector< vector<int> > permute(vector<int>& nums){
    vector< vector<int> > result;
    dfs(nums,0,result);
    return result;
}


