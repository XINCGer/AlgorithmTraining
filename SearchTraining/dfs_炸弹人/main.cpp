#include <iostream>

using namespace std;

char a[20][21];
int book[20][20],maxn,mx,my,n,m;

int getNum(int i,int j){
    int sum,x,y;
    sum =0;
    x=i;
    y=j;
    while(a[x][y]!= '#'){//判断是否是墙
            //如果是敌人则计数
            if(a[x][y] =='G')sum++;
            x--;//向上统计
        }

        //向下统计敌人数目
        x=i;y=j;
        while(a[x][y] !='#'){
            if(a[x][y] == 'G')sum++;
            x++;
        }

        //向左统计敌人数目
        x=i;
        y=j;
        while(a[x][y] !='#'){
            if(a[x][y] == 'G')sum++;
            y--;
        }

        //向右统计敌人数目
        x=i;
        y=j;
        while(a[x][y] !='#'){
            if(a[x][y] =='G')sum++;
            y++;
        }
        return sum;
}
void dfs(int x,int y){
    int next[4][2]={{0,1},//right
                {1,0},//down
                {0,-1},//left
                {-1,0}//up
                };
    //计算当前点可以消灭的敌人数量
    int k,sum,tx,ty;
    sum =getNum(x,y);
    if(sum >maxn){
        maxn =sum;
        mx =x;
        my =y;
    }

    for(k=0;k<=3;k++){
        tx =x+next[k][0];
        ty =y+next[k][1];
        if(tx<0 || tx>n-1 || ty<0 || ty>m-1){
            continue;
        }
        if(a[tx][ty] =='.' &&book[tx][ty] ==0){
            book[tx][ty]=1;
            dfs(tx,ty);
        }
    }
    return ;
}
int main()
{
    int i,startx,starty;
    cin>>n>>m>>startx>>starty;
    for(i =0;i<n;i++){
        for(int j=0;j<m;j++)cin>>a[i][j];
    }
    book[startx][starty] =1;
    maxn = getNum(startx,starty);
    mx =startx;
    my =starty;
    dfs(startx,starty);
    cout<<"将炸弹放置在("<<mx<<","<<my<<")处，可以消灭"<<maxn<<"个敌人"<<endl;
    return 0;
}

/*
测试数据
13 13 3 3
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.#.#
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############
*/
