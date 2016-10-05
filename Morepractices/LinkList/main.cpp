#include <iostream>

using namespace std;
/**
数据结构~链表复习
*/
template<class T>
struct Node
{
    T data;
    Node<T> *next;
};

template<class T>
class LinkList
{
public:
    LinkList();     //无参构造函数，建立空链表
    LinkList(T a[],int n);  //有参构造函数，建立有n个元素的单链表
    ~LinkList();
    int Length();   //求链表长度
    T Get(int i);   //返回第i个结点的值
    int Locate(T x);    //查找值为x的序号
    void Insert(int i,T x);  //在第i个位置插入x
    T Delete(int i);        //删除第i个节点
    void PrintList();       //遍历链表
    void ReverseList();     //链表逆置
private:
    Node<T> *first;     //头指针
};

template<class T>
LinkList<T>::LinkList()
{
    first=new Node<T>();
    first->next=NULL;
}

//头插法
template<class T>
LinkList<T>::LinkList(T a[],int n)
{
    first=new Node<T>();
    first->next=NULL;
    Node<T> *s;
    for(int i=0;i<n;i++){
        s=new Node<T>();
        s->data=a[i];
        s->next=first->next;
        first->next=s;
    }
}

//尾插法
//template<class T>
//LinkList<T>::LinkList(T a[],int n)
//{
//    first=new Node<T>();
//    Node<T> *r=first;    //尾指针初始化
//    Node<T> *s;
//    for(int i=0;i<n;i++){
//        s=new Node<T>();
//        s->data=a[i];
//        r->next=s;
//        r=s;
//    }
//    r->next=NULL;
//}

template<class T>
LinkList<T>::~LinkList()
{
    while(first!=NULL){
        Node<T> *q;
        q=first;
        first=first->next;
        delete q;
    }
}

template<class T>
void LinkList<T>::PrintList()
{
    Node<T> *p;
    p=first->next;
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
}

template<class T>
int LinkList<T>::Length(){
    Node<T> *p;
    p=first->next;
    int countn=0;
    while(p!=NULL){
        p=p->next;
        countn++;
    }
    return countn;
}

template<class T>
T LinkList<T>::Get(int i){
    Node<T> *p;
    p=first->next;
    int countn=1;
    while(p!=NULL&&countn<i){
        p=p->next;
        countn++;
    }
    if(p==NULL)throw "位置非法";
    else return p->data;
}

template<class T>
int LinkList<T>::Locate(T x){
    Node<T> *p=first;
    p=p->next;
    int countn=1;
    while(p!=NULL){
        if(p->data==x)return countn;
        p=p->next;
        countn++;
    }
    return 0;
}

template<class T>
void LinkList<T>::Insert(int i,T x){
    Node<T> *p=first;
    int countn=0;
    while(p!=NULL &&countn<i-1){
        p=p->next;
        countn++;
    }
    if(p==NULL)throw "位置非法";
    else{
        Node<T> *s= new Node<T>();
        s->data=x;
        s->next=p->next;
        p->next=s;
    }
}

template<class T>
T LinkList<T>::Delete(int i){
    Node<T> *p=first;
    int countn=0;
    while(p!=NULL&&countn<i-1){
        p=p->next;
        countn++;
    }
    if(p==NULL||p->next==NULL){
        throw "位置非法";
    }
    else{
        Node<T> *q;
        q=p->next;
        T x=q->data;
        p->next=q->next;
        delete q;
        return x;
    }
}

//template<class T>
//void LinkList<T>::ReverseList(){
//    if(first==NULL||first->next==NULL)return;
//        Node<T> *p, *q;
//    p = first->next;    //P指向链表第一个元素
//    first->next = NULL; //断开头结点与链表
//    while(p != NULL)
//    {
//        q = p;
//        p = p->next;
//        q->next = first->next;  //相当于前插法构建新的链表，和原来的相反
//        first->next = q;
//    }
//}

template<class T>
void LinkList<T>::ReverseList(){
    if(first==NULL||first->next==NULL)return;
    Node<T> *pre=first;
    Node<T> *cur=pre->next;
    Node<T> *next=NULL;
    Node<T> *cur1=cur;
    while(cur!=NULL){
        next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    first->next=pre;
    cur1->next=NULL;
}

int main()
{
    int a[]={1,2,3,4,5};
    LinkList<int> l(a,5);
    l.PrintList();
    cout<<endl;
    cout<<l.Length()<<endl;
    cout<<endl;
    l.ReverseList();
    l.PrintList();
    return 0;
}
