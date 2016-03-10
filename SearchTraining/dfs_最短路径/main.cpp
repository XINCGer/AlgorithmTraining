#include <iostream>

using namespace std;

int n,m,p,q,minx=9999999999;
int a[51][51],book[51][51];

void dfs(int x,int y,int step){
    int next[4][2]={{0,1},//right
                    {1,0},//down
                    {0,-1},//left
                    {-1,0}//up
                    };
    int tx,ty,k;
    //判读是否到达指定位置
    if(x==p && y==q){
        //更新最小值
        if(step<minx)minx=step;
        return;
    }

    //枚举4种走法
    for(k=0;k<=3;k++){
        //计算下一个坐标
        tx =x+next[k][0];
        ty =y+next[k][1];
        //判断是否越界
        if(tx<1 || tx>n || ty<1 || ty>m)continue;
        //判断该点是否为障碍物或者已经在路径中
        if(a[tx][ty] ==0 &&book[tx][ty] ==0){
            book[tx][ty] =1;
            dfs(tx,ty,step+1);
            book[tx][ty]=0;
        }
    }
    return;
}
int main()
{
    int i,j,startx,starty;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)cin>>a[i][j];
    }
    cin>>startx>>starty>>p>>q;

    book[startx][starty]=1;
    dfs(startx,starty,0);
    cout<<minx<<endl;
    return 0;
}


/*测试样例
5 4
0 0 1 0
0 0 0 0
0 0 1 0
0 1 0 0
0 0 0 1
1 1 4 3
*/
