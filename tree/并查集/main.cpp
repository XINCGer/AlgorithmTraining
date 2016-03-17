#include <iostream>

using namespace std;

int f[1000]={0},n,m,k,sum=0;

void init(){
    int i;
    for(i=1;i<=n;i++){
        f[i]=i;
    }
    return;
}

//这里是找爹的递归函数，不停地去找爹，知道找到祖宗为止，其实就是去找犯罪团伙的最高领导人
//擒贼先擒王的原则
int getf(int v){
    if (f[v]==v)return v;
    else{
        //路径压缩，每次在函数返回的时候，
//        顺便把路上遇到的人的“BOSS”改为最后找到的祖宗编号，这样可以提高今后找到犯罪团伙的最高领导人的速度
        f[v]=getf(f[v]);
        return f[v];
    }
}

void merge(int v,int u){
    int t1,t2;
    t1 =getf(v);
    t2 =getf(u);
    if(t1!=t2){
        f[t2]=t1;
    }
    return;
}
int main()
{
    int i,x,y;
    cin>>n>>m;
    init();
    for(i=1;i<=m;i++){
        cin>>x>>y;
        merge(x,y);
    }

    //最后扫描有多少个独立的犯罪团伙
    for(i=1;i<=n;i++){
        if(f[i] ==i)sum++;
    }
    cout<<sum<<endl;
    return 0;
}


/*
测试数据
10 9
1 2
3 4
5 2
4 6
2 6
8 7
9 7
1 6
2 4
*/
