#include <iostream>

using namespace std;

int main()
{
    int i,j,n,m,a,b,cur,book[101]={0},e[101][101];
    int que[10001],head,tail;
    cin>>n>>m;
    //初始化矩阵
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j)e[i][j]=0;
            else e[i][j]=99999999;
        }
    }
    for(i=1;i<=m;i++){
        cin>>a>>b;
        e[a][b]=1;
        e[b][a]=1;
    }
    head =1;
    tail =1;
    que[tail]=1;
    tail++;
    book[1]=1;

    while(head<tail){
        cur =que[head];
        for(i=1;i<=n;i++){
            if(e[cur][i] ==1 &&book[i]==0){
                que[tail]=i;
                tail++;
                book[i]=1;
            }
            if(tail>n){
                break;//如果tail>n 则表明所有的顶点已经被访问完毕
            }
        }
        head++;
    }

    for(i=1;i<tail;i++)cout<<que[i]<<endl;
    return 0;
}


/*
测试数据
5 5
1 2
1 3
1 5
2 4
3 5
*/
