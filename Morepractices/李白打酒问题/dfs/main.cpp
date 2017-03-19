//题目描述：
//话说大诗人李白，一生好饮。幸好他从不开车。
//一天，他提着酒壶，从家里出来，酒壶中有酒2斗。他边走边唱：
//
//无事街上走，提壶去打酒。
//逢店加一倍，遇花喝一斗。
//
//这一路上，他一共遇到店5次，遇到花10次，已知最后一次遇到的是花，他正好把酒喝光了。
//
//请你计算李白遇到店和花的次序，可以把遇店记为a，遇花记为b。则：babaabbabbabbbb 就是合理的次序。
//像这样的答案一共有多少呢？请你计算出所有可能方案的个数（包含题目给出的）。
#include <iostream>
using namespace std;

int count=0;
void dfs(int,int,int);
int main()
{
	dfs(0,0,2);
	cout<<count<<endl;
	return 0;
}

//遇到了多少店，遇到了多少花，还有多少酒
void dfs(int store,int flow,int acho)
{
	if(store>5||flow>9)return;	//注意不符合条件的情况的排除
	if(store==5&&flow==9)
	{
		if(acho==1)
		{
			count++;
			return;
		}
		else
			return;
	}

    //每次或者遇到酒店或者遇到花，两种选择
	dfs(store+1,flow,acho*2);
	dfs(store,flow+1,acho-1);
}
