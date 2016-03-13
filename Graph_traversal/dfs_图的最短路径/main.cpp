#include <iostream>

using namespace std;

int minx =99999999999,book[101],n,e[101][101];

void dfs(int  cur,int dis){//dis是已经走过的路程
    int j;
    if(dis >minx)return;//如果走过的路程大于之前的最短路程，就返回，没有必要再走了
    if(cur ==n){//判断
        if(dis<minx)minx=dis;
        return;
    }
    for(j=1;j<=n;j++){//从1号城市到n依次尝试
        if(e[cur][j]!=99999999999 &&book[j]==0){
            book[j]=1;
            dfs(j,dis+e[cur][j]);
            book[j]=0;
        }
    }
    return;
}
int main()
{
    int i,j,m,a,b,c;
    cin>>n>>m;
    //初始化矩阵
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i ==j)e[i][j]=0;
            else e[i][j]=99999999999;
        }
    }

    //读入城市之间的道路
    for(i=1;i<=m;i++){
        cin>>a>>b>>c;
        e[a][b]=c;
    }
    book[1]=1;
    dfs(1,0);
    cout<<endl;
    cout<<minx<<endl;
    return 0;
}


/*
测试数据
5表示有5个城市，8表示有8条公路，c为路程公里数
5 8
1 2 2
1 5 10
2 3 3
2 5 7
3 1 4
3 4 4
4 5 5
5 3 3
*/
