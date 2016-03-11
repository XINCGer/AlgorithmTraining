#include <iostream>

using namespace std;

struct node{
    int x;
    int y;
};
int main()
{
    struct node que[2501];
    int head,tail;
    int a[51][51];
    int book[51][51]={0};
    int i,j,k,sum,maxn=0,mx,my,n,m,startx,starty,tx,ty;
    int next[4][2]={{0,1},//right
                {1,0},//down
                {0,-1},//left
                {-1,0}//up
                };
    cin>>n>>m>>startx>>starty;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)cin>>a[i][j];
    }

    head =1;
    tail =1;
    que[tail].x =startx;
    que[tail].y =starty;
    tail++;
    book[startx][starty] =1;
    sum=1;

    while(head<tail){
        for(k=0;k<=3;k++){
            tx = que[head].x +next[k][0];
            ty = que[head].y +next[k][1];
            if(tx<0 || tx>n-1 ||ty<1 ||ty >m-1){
                continue;
            }
            if(a[tx][ty] >0 &&book[tx][ty] ==0){
                sum++;
                book[tx][ty] =1;
                que[tail].x =tx;
                que[tail].y =ty;
                tail++;
            }
        }
        head++;
    }

    cout<<sum<<endl;
    return 0;
}


/*
10 10 6 8
1 2 1 0 0 0 0 0 2 3
3 0 2 0 1 2 1 0 1 2
4 0 1 0 1 2 3 2 0 1
3 2 0 0 0 1 2 4 0 0
0 0 0 0 0 0 1 5 3 0
0 1 2 1 0 1 5 4 3 0
0 1 2 3 1 3 6 2 1 0
0 0 3 4 8 9 7 5 0 0
0 0 0 3 7 8 6 0 1 2
0 0 0 0 0 0 0 0 1 0
*/
