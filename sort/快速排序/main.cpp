#include <iostream>

using namespace std;
int a[101],n;

void quicksort(int left,int right){
    int i,j,t,temp;
    if(left >right){
        return;
    }
    temp = a[left];//temp存的就是基准数
    i=left;
    j=right;
    while(i!=j){
        //顺序很重要，要先从右往左找
        while(a[j]>=temp &&i<j){
            j--;
        }
        while(a[i]<=temp && i<j){
            i++;
        }
        if(i<j){//当哨兵i和哨兵j没有相遇的时候
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    a[left]=a[i];
    a[i]=temp;
    quicksort(left,i-1);
    quicksort(i+1,right);
    return;
}
int main()
{
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    quicksort(1,n);
    for(i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
