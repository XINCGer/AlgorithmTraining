#include <iostream>

using namespace std;

int a[51][51];
int book[51][51],n,m,sum;

void dfs(int x,int y){
    int next[4][2]={{0,1},//right
                {1,0},//down
                {0,-1},//left
                {-1,0}//up
                };
    int k,tx,ty;
    for(k=0;k<=3;k++){
        tx = x+next[k][0];
        ty = y+next[k][1];
        if(tx<1 || tx>n || ty<1 || ty>m)continue;
        if(a[tx][ty] >0 &&book[tx][ty] ==0){
            sum++;
            book[tx][ty]=1;
            dfs(tx,ty);
        }
    }
    return;
}
int main()
{
    int startx, starty;
    cin>>n>>m>>startx>>starty;
    for(int i=1;i<=n;i++){
        for(int j =1;j<=m;j++)cin>>a[i][j];
    }
    book[startx][starty]=1;
    sum++;
    dfs(startx,starty);
    cout<<sum<<endl;
    return 0;
}
