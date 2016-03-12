#include <iostream>

using namespace std;

int a[51][51];
int book[51][51],n,m,flag =0;

struct node{
    int x;
    int y;
}s[100];
int top=0;
void dfs(int x,int y,int f){
    if(x ==n && y==m+1){
        flag =1;//找到铺设方案
        for(int i=1;i<=top;i++)cout<<s[i].x<<" "<<s[i].y<<endl;
        return;
    }
    if(x<1 ||x >n || y<1 ||y>m){
        return;
    }
    if(book[x][y] ==1)return;
    book[x][y] =1;
    top++;
    s[top].x =x;
    s[top].y =y;

    //当前的水管是直的
    if(a[x][y] >=5 && a[x][y] <=6){
        if(f ==1)//进水口在左边
            dfs(x,y+1,1);
        if(f ==2)//进水口在上边
            dfs(x+1,y,2);
        if(f ==3)//进水口在右边
            dfs(x,y-1,3);
        if(f ==4)//进水口在下边
            dfs(x-1,y,4);
    }
    //如果当前水管是弯管
    if(a[x][y] >=1 && a[x][y]<=4){
        if(f ==1){
            dfs(x+1,y,2);//3号状态
            dfs(x-1,y,4);//4号状态
        }
        if(f ==2){
            dfs(x,y+1,1);//1号状态
            dfs(x,y-1,3);//4号状态
        }
        if(f ==3){
            dfs(x-1,y,4);//1号状态
            dfs(x+1,y,2);//2号状态
        }
        if(f ==4){
            dfs(x,y+1,1);//2号状态
            dfs(x,y-1,3);//2号状态
        }
    }
    book[x][y]=0;
    top--;
    return;
}
int main()
{
    int num=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)cin>>a[i][j];
    }
    dfs(1,1,1);
    if(flag ==0){
        cout<<"没有找到解决方案"<<endl;
    }
    return 0;
}


/*
测试数据
5 4
5 3 5 3
1 5 3 0
2 3 5 1
6 1 1 5
1 5 5 4
*/
