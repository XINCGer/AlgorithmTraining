#include <iostream>

using namespace std;

int main()
{
    int n,m,i,j,k;
    int u[8],v[8],w[8];
    int first[6],next[8];//fisrt 要比n的最大值大1，next要比m的最大值大1
    int dis[6]={0},book[6]={0};
    int que[101]={0};
    int head =1,tail =1;

    int inf =99999999;
    cin>>n>>m;

    for(i=1;i<=n;i++)dis[i]=inf;
    dis[1]=0;
    for(i=1;i<=n;i++)book[i]=0;//刚开始都不在队列中
    for(i=1;i<=n;i++)first[i]=-1;//-1表示1-n顶点暂时都没有边

    for(i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
        next[i]=first[u[i]];
        first[u[i]] =i;
    }

    que[tail]=1;
    tail++;
    book[1]=1;
    while(head <tail){
        k =first[que[head]];//当前需要处理的队首顶点
        while(k!= -1){//扫描当前顶点所有的边
            if(dis[v[k]] >dis[u[k]] +w[k]){//判断是否松弛成功
               dis[v[k]] =dis[u[k]] +w[k];//更新顶点1到顶点v[k]的路程
                //这里的book属猪用来判断顶点v[k]是否在队列中
                //如果不使用一个数组来标记的话，判断一个顶点是否在队列中每次都需要从
                //队列的head 到tail 扫描一遍，很浪费时间
                if(book[v[k]] ==0){//0表示不在队列中，将顶点v[k]加入队列
                    //入队操作
                    que[tail]=v[k];
                    tail++;
                    book[v[k]] =1;//同时标记v[k]已经入队
                }
            }
            k=next[k];
        }
        //出队
        book[que[head]] =0;
        head++;
    }
    cout<<endl;
    for(i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }

    return 0;
}


/*
测试数据
5 7
1 2 2
1 5 10
2 3 3
2 5 7
3 4 4
4 5 5
5 3 6
*/
