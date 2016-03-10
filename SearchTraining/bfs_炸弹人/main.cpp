#include <iostream>

using namespace std;

struct node{
    int x;
    int y;
};
char a[20][21];

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
int main()
{
    struct node que[401];
    int head,tail;
    int book[20][20]={0};
    int i,j,k,sum,maxn =0,mx,my,n,m,startx,starty,tx,ty;

    int next[4][2]={{0,1},//right
                {1,0},//down
                {0,-1},//left
                {-1,0}//up
                };
    cin>>n>>m>>startx>>starty;

    for(i=0;i<n;i++){
            for(j=0;j<m;j++)cin>>a[i][j];
    }

    //queue init
    head =1;
    tail =1;
    que[tail].x =startx;
    que[tail].y =starty;
    tail++;
    book[startx][starty]=1;
    maxn =getNum(startx,starty);
    mx =startx;
    my =starty;

    while(head <tail){
        for(k=0;k<=3;k++){
            tx =que[head].x +next[k][0];
            ty =que[head].y +next[k][1];
            if(tx<0 || tx>n-1 ||ty<0 || ty>m-1)continue;
            if(a[tx][ty] =='.' &&book[tx][ty] ==0){
                book[tx][ty] =1;
                que[tail].x =tx;
                que[tail].y =ty;
                tail++;
                sum = getNum(tx,ty);
                if(sum>maxn){
                    maxn =sum;
                    mx =tx;
                    my =ty;
                }
            }
        }
        head++;
    }
    cout<<"将炸弹放置在("<<mx<<","<<my<<")处，可以消灭"<<maxn<<"个敌人"<<endl;
    return 0;
}

/*测试数据
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
