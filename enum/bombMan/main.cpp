#include <iostream>

using namespace std;

int main()
{
    char a[20][21];
    int sum,maxn =0,p,q,x,y,n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            cin>>a[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == '.'){//先判断是否是空地
                sum=0;
                //将当前坐标i，j复制到新变量x，y中。
                //向上统计敌人数目
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
                //更新max值
                if(sum>maxn){
                    maxn =sum;
                    //记录当前坐标
                    p=i;q=j;
                }
            }
        }
    }
    cout<<"将炸弹放置在("<<p<<","<<q<<")最多可以消灭"<<maxn<<"个敌人"<<endl;
    return 0;
}
/*
测试数据
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.###
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############
*/