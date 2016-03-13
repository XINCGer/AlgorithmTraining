#include <iostream>

using namespace std;

int book[101],sum,n,e[101][101];

void dfs(int cur){//cur 是当前所在的顶点编号
    cout<<cur<<endl;
    sum++;
    if(sum ==n)return;//当所有顶点都访问到时，退出
    for(int i=1;i<=n;i++){//从1号顶点到n点依次尝试，看哪些顶点与当前cur有边相连
            //判断cur到i是否有边，并判断顶点i是否访问过
            if(e[cur][i] ==1 &&book[i]==0){
                book[i] =1;
                dfs(i);
            }
    }
    return;
}
int main()
{
    int i,j,m,a,b;
    cin>>n>>m;
    //初始化矩阵
    for(i=1;i<=n;i++){
        for(j =1;j<=n;j++){
            if(i==j)e[i][j]=0;
            else e[i][j]=99999999999;
        }
    }
    //读入有连接的边
    for(i=1;i<=m;i++){
        cin>>a>>b;
        e[a][b]=1;
        e[b][a]=1;
    }
    book[1]=1;
    dfs(1);
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
