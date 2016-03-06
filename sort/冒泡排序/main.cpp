#include <iostream>

using namespace std;

int main()
{
    int a[1001],t,n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++){//n个数排序，只用n-1趟
        for(int j=1;j<=n-i;j++){//从第一个数开始比较，知道最后一个尚未归位的数
            if(a[j]<a[j+1]){
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
