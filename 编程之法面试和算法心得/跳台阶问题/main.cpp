#include <iostream>

using namespace std;

//递归实现，原理为斐波那契数列
//如果一个人一次可以上1、2、3个台阶的话，公式可以为 f(n-1)+f(n-2)+f(n-3) 1\2\4
__int64 Fibonacci(int n)
{
    int result[] = {0,1,2};
    if(n<=2)
    {
        return result[n];
    }
    return Fibonacci(n-1)+Fibonacci(n-2);
}

__int64 ClimbStairs(int n)
{
    int dp[3] = {1,1};
    if(n<2)
    {
        return 1;
    }
    for(int i=2; i<=n; i++)
    {
        dp[2] = dp[0]+dp[1];
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    return dp[2];
}
int main()
{
    int testData[] = {1,2,3,4,5,6,7,8,9,10};
    for(int i=0; i<10; i++)
    {
        cout<<Fibonacci(testData[i])<<endl;
    }
    cout<<"----------------------"<<endl;
    for(int i=0; i<10; i++)
    {
        cout<<ClimbStairs(testData[i])<<endl;
    }
    return 0;
}
