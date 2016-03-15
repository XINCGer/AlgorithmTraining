#include <iostream>

using namespace std;

int main()
{
    int e[10][10],k,i,j,n,m,t1,t2,t3;
    int inf =99999999;
    cin>>n>>m;//n表示顶点个数，m表示边的条数

    //初始化
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i ==j)e[i][j]=0;
            else e[i][j]=inf;
        }
    }

    for(i =1;i<=m;i++){
        cin>>t1>>t2>>t3;
        e[t1][t2]=t3;
    }

    //Floyd-Warshall 算法核心
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(e[i][j]>e[i][k] + e[k][j])
                    e[i][j]=e[i][k] + e[k][j];
            }
        }
    }
    cout<<endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            cout<<e[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}


/*
测试数据
4 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
*/
