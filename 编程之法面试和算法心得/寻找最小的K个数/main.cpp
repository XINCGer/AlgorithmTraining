#include <iostream>

using namespace std;

//解法1：全部排序然后输出
//解法2：部分排序
//解法3：用怼代替数组

//解法4：线性选择算法（快速选择算法 O(n)）,quickSelect将第k小的元素放在S[k-1]
void quickSelect(int s[],int k, int left,int right){
    int i,j;
    int pivot;

    if(left<right){
        pivot = mediad3(s,left,right);
        //取3个数的中值作为主元，可以很大程度上避免最坏情况
        i = left;j = right -1;
        for(;;){
            while(s[++i]<pivot){}
            while(s[--j] > pivot){}
            if(i<j){
                swap(s[i],s[j]);
            }
            else{
                break;
            }

        }
        swap(s[i],s[right-1]);
        if(k<=i){
            quickSelect(s,k,left,i-1);
        }
        else if(k>i+1){
            quickSelect(s,k,i+1,right);
        }
    }
    else{
        //如果left>right，利用插入排序调整一下
        InsertSort(s+left,right-left+1);
    }
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
