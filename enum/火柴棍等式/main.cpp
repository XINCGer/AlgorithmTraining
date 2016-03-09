#include <iostream>

using namespace std;

int fun(int x){
    int num =0;
    int f[10]={6,2,5,5,4,5,6,3,7,6};
    //用一个数组来记录0-9每个数字要用多少根火柴
    while(x/10!=0){//如果x/10不等于0的话，说明这个数至少有两位
            num+=f[x%10];
            x=x/10;
    }
    num+=f[x];
    return num;
}

int main()
{
    int a,b,c,m,sum=0;
    cin>>m;
    for(a=0;a<=1111;a++){
        for(b=0;b<=1111;b++){
            c=a+b;//通过a、b计算出c
            if(fun(a)+fun(b)+fun(c)==m-4){
                cout<<a<<"+"<<b<<"="<<c<<endl;
                sum++;
            }
        }
    }
    cout<<"一共可以拼出"<<sum<<"个不等式"<<endl;
    return 0;
}
