#include <iostream>
#include <vector>
#include <list>
using namespace std;

list<int> list1;

//解法1：转换为n-1问题，01背包
void SumOfKNumber(int sum,int n){
    //递归出口
    if(n<=0 || sum <=0){
        return;
    }
    //输出找到的结果
    if(sum == n){
        //反转List
        list1.reverse()
        for(list<int>::iterator it = list1.begin();it!=list1.end();it++){
            cout<<*it<<" + ";
        }
        cout<<n<<endl;
    }

    list1.push_front(n);
    SumOfKNumber(sum-n,n-1); //放n，前n-1个数满足sum-n
    list1.pop_front();
    SumOfKNumber(sum,n-1); //不放n，前n-1个数满足sum
}

int main()
{
    return 0;
}
