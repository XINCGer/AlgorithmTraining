//首先按照边的权值从小到大排序，每次从剩余的边中选择权值较小
//且边的两个顶点不在同一个集合内的边（就是不会产生回路的边），加入到生成树中
//直到加入了n-1条边为止
#include <iostream>

using namespace std;

struct edge{
    int u;
    int v;
    int w;
};
struct edge e[10];
int n,m;
int f[7]={0},sum=0,countx=0;

void quicksort(int left,int right){
    int i,j;
    struct edge t;
    if(left >right){
        return;
    }
    i=left;
    j=right;
    while(i!=j){
        while(e[j].w >=e[left].w &&i<j)j--;
        while(e[i].w <=e[left].w && i<j)i++;
        //swap
        if(i<j){
            t=e[i];
            e[i]=e[j];
            e[j]=t;
        }
    }
    t=e[left];
    e[left] =e[i];
    e[i]=t;

    quicksort(left,i-1);
    quicksort(i+1,right);
    return;
}

int getf(int v){
    if(f[v]==v)return v;
    else{
        //路径压缩
        f[v]=getf(f[v]);
        return f[v];
    }
}

int Merage(int v,int u){
    int t1,t2;
    t1 =getf(v);
    t2 =getf(u);
    if(t1 !=t2){
        f[t2]=t1;
        return 1;
    }
    return 0;
}

int main()
{
    int i;
    cin>>n>>m;
    for(i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    quicksort(1,m);
    for(i=1;i<=n;i++)f[i]=i;

    //Kruskal算法核心部分
    for(i=1;i<=m;i++){//从小到大枚举每一条边
        //判断一条边的两个顶点是否已经连通，即判断是否已经在同一个集合中
        if(Merage(e[i].u,e[i].v)){//如果目前尚未连通，则选用这条边
            countx++;
            sum=sum+e[i].w;
        }
        if(countx ==n-1)break;//直到选用了n-1条边之后退出循环
    }
    cout<<endl;
    cout<<sum<<endl;
    return 0;
}

/*
测试数据
6 9
2 4 11
3 5 13
4 6 3
5 6 4
2 3 6
4 5 7
1 2 1
3 4 9
1 3 2
*/
