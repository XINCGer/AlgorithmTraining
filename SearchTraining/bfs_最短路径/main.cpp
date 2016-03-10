#include <iostream>

using namespace std;

struct node{
    int x;
    int y;
    int f;//父亲在队列中的编号，用于路径输出
    int s;//步数
};

int main()
{
    struct node que[2501];

    int a[51][51]={0},book[51][51]={0};

    int next[4][2]={{0,1},//right
                     {1,0},//down
                     {0,-1},//left
                     {-1,0} };//up
    int head,tail;
    int i,j,k,n,m,startx,starty,p,q,tx,ty,flag;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)cin>>a[i][j];
    }
    cin>>startx>>starty>>p>>q;

    //queue init
    head=1;
    tail=1;
    que[tail].x =startx;
    que[tail].y =starty;
    que[tail].f =0;
    que[tail].s =0;
    tail++;
    book[startx][starty] =1;

    flag=0;//用来标记是否达到目标点，0表示暂时还没有，1表示到达
    while(head<tail){
        //枚举4个方向
        for(k=0;k<=3;k++){
            tx =que[head].x +next[k][0];
            ty =que[head].y +next[k][1];
            if(tx<1 ||tx>n ||ty<1 || ty>m)continue;
            if(a[tx][ty] ==0 &&book[tx][ty] ==0){
                //把这个点标记为已经走过，宽搜每个点只入队一次
                book[tx][ty] =1;
                que[tail].x =tx;
                que[tail].y =ty;
                que[tail].f =head; //因为这个点是从head拓展出来的所以他的父节点是head
                que[tail].s = que[head].s+1;
                tail++;
            }
            //如果目标点到了，停止拓展
            if(tx ==p &&ty ==q){
                flag =1;
                break;
            }
        }
        if(flag ==1)break;
        head++;//当一个点拓展结束之后，head++才能对后面的点进行拓展
    }
    cout<<que[tail-1].s<<endl;
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
