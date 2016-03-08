//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int queue[102]={0,6,3,1,7,5,8,9,2,4},head,tail;
//    //init queue
//    head =1;
//    tail =10;
//    while(head<tail){
//        cout<<queue[head]<<" ";
//        head++;
//        queue[tail] = queue[head];
//        tail++;
//        head++;
//    }
//    return 0;
//}

#include <iostream>

using namespace std;

struct queue{
    int data[100];
    int head;
    int tail;
};

int main(){
    struct queue q;
    int i;
    //init queue
    q.head =1;
    q.tail =1;
    for(i=1;i<=9;i++){
        cin>>q.data[i];
        q.tail++;
    }
    while(q.head<q.tail){
        cout<<q.data[q.head]<<" ";
        q.head++;
        q.data[q.tail]=q.data[q.head];
        q.tail++;
        q.head++;
    }
    return 0;
}
