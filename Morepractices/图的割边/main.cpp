#include <iostream>

using namespace std;

int n,m,e[9][9],root;
int num[9],low[9],index;//index用来进行时间戳的递增

int min(int a,int b){
    return a<b?a:b;
}

//割点算法核心
void dfs(int cur ,int father){//需要传入两个参数，当前顶点的编号和父顶点的编号
    int i;//i用来记录在生成树中当前顶点cur的儿子个数

    index++;//时间戳加+1
    num[cur]=index;//当前cur顶点的时间戳
    low[cur]=index;

    for(i=1;i<=n;i++){//枚举与当前顶点cur有边相连的顶点i
        if(e[cur][i] ==1){
            if(num[i] ==0){
                dfs(i,cur);
                low[cur] =min(low[cur],low[i]);
                //如果当前顶点不是根节点并且满足low[i]>=num[cur],则当前顶点为割点
                if(low[i]>num[cur])cout<<cur<<"--"<<i<<endl;
            }
            else if(i!= father){
                low[cur] =min(low[cur],num[i]);
            }
        }
    }
    return;
}
int main()
{
    int i,j,x,y;
    cin>>n>>m;

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            e[i][j]=0;
        }
    }

    for(i=1;i<=m;i++){
        cin>>x>>y;
        e[x][y]=1;
        e[y][x]=1;
    }

    root=1;
    dfs(1,root);
    return 0;
}


/*
测试数据
6 6
1 4
1 3
4 2
3 2
2 5
5 6
*/
