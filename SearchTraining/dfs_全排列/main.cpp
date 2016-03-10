#include <iostream>

using namespace std;

int a[10],book[10],n;

void dfs(int step){//step表示站在第几个盒子前面
    int i;
    if(step == n+1){
        for(i=1;i<=n;i++)cout<<a[i]<<" ";
        cout<<endl;
        return;
    }
    for(i=1;i<=n;i++){
        if(book[i] ==0){//如果i号扑克牌在手上
            a[step]=i;//将i号扑克牌放入到第step个盒子里面
            book[i]=1;
            dfs(step+1);
            book[i]=0;
        }
    }
    return;

}
int main()
{
    cin>>n;
    dfs(1);
    return 0;
}
