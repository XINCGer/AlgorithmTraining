#include <iostream>

using namespace std;

struct node{
    int x;//城市编号
    int s;//转机次数
};


int main()
{
    struct node que[2501];
    int e[51][51]={0},book[51]={0};
    int head,tail;
    int i,j,n,m,a,b,cur,startP,endP,flag=0;
    cin>>n>>m>>startP>>endP;

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i ==j)e[i][j]=0;
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

    que[tail].x =startP;
    que[tail].s =0;
    tail++;
    book[startP]=1;

    while(head <tail){
        cur =que[head].x;
        for(j=1;j<=n;j++){
            if(e[cur][j] !=99999999 &&book[j]==0){
                que[tail].x =j;
                que[tail].s =que[head].s+1;
                tail++;
                book[j]=1;
            }
            if(que[tail-1].x ==endP){
                flag =1;
                break;
            }
        }
        if(flag ==1)break;
        head++;
    }

    cout<<que[tail-1].s<<endl;
    return 0;
}



/*
测试数据
5表示有5个城市，7表示有7条航线，1表示起点城市，5表示目标城市

5 7 1 5
1 2
1 3
2 3
2 4
3 4
3 5
4 5
*/
