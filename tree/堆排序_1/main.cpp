#include <iostream>

using namespace std;

int h[101];//用来存放堆的数组
int n;//用来存放堆中元素的个数，也就是堆的大小

void swap(int x,int y){
    int t;
    t=h[x];
    h[x]=h[y];
    h[y]=t;
    return;
}

//向下调整函数
void siftdown(int i){//传入一个需要向下调整的节点编号i
    int t,flag =0;//flag 用来标记是否需要继续向下调整
    //当i节点有儿子（至少是左儿子），并且有需要继续调整的时候循环就继续执行
    while(i*2 <=n && flag ==0){
        //首先判断他和左儿子的关系。用t记录比较小的编号
        if(h[i] >h[i*2]){
            t =i*2;
        }
        else t=i;

        //再对右儿子进行讨论
        if(i*2+1 <=n){
            if(h[t] >h[i*2+1]){
                t=i*2+1;
            }
        }

        if(t !=i){
            swap(t,i);
            i =t;
        }
        else{
            flag =1;
        }
    }
    return;
}

void create(){
    int i;
    for(i=n/2;i>=1;i--){//从最后一个非叶子节点到第一个节点一次进行向下调整
        siftdown(i);
    }
    return;
}

int deleteMax(){
    int t;
    t =h[1];
    h[1]=h[n];
    n--;
    siftdown(1);
    return t;
}

int main()
{
    int i,num;
    cin>>num;
    for(i=1;i<=num;i++)cin>>h[i];
    n =num;
    create();
    for(i=1;i<=num;i++){
        cout<<deleteMax()<<" ";
    }
    cout<<endl;
    return 0;
}

/*
测试数据
14
99 5 36 7 22 17 46 12 2 19 25 28 1 92
*/
