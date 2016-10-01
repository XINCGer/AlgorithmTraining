#include <iostream>
using namespace std;
#define maxn 50

template<class T>
struct Node{
    T data;
    Node<T> *lchild,*rchild;
};

template<class T>
class BiTree{
private:
    Node<T> *root;  //指向根节点的头指针
    Node<T> *create(Node<T> *bt);   //构造函数调用
    void release(Node<T> *bt);      //析构函数调用
    void preOrder(Node<T> *bt);     //前序遍历调用
    void inOrder(Node<T> *bt);      //中序遍历
    void postOrder(Node<T> *bt);    //后序遍历

public:
    BiTree(){root=create(root);}    //建立一棵二叉树
    ~BiTree(){release(root);}       //析构函数
    void preOrder(){preOrder(root);}   //前序遍历
    void inOrder(){inOrder(root);}      //中序遍历
    void postOrder(){postOrder(root);}  //  后序遍历
    void levelOrder();              //层序遍历
};

//递归方法实现前序遍历
template <class T>
void BiTree<T>::preOrder(Node<T> *bt){
    if(bt==NULL)return;     //递归调用的结束条件
    else{
        cout<<bt->data<<" ";
        preOrder(bt->lchild);
        preOrder(bt->rchild);
    }
}

//递归方法实现中序遍历
template <class T>
void BiTree<T>::inOrder(Node<T> *bt){
    if(bt==NULL)return; //递归调用的结束条件
    else{
        inOrder(bt->lchild);
        cout<<bt->data<<" ";
        inOrder(bt->rchild);
    }
}

//递归方法实现中序遍历
template <class T>
void BiTree<T>::postOrder(Node<T> *bt){
    if(bt==NULL)return; //递归调用的结束条件
    else{
        postOrder(bt->lchild);
        postOrder(bt->rchild);
        cout<<bt->data<<" ";
    }
}

//层序遍历
template <class T>
void BiTree<T>::levelOrder(){
    int m_front=-1,m_rear=-1;
    if(root==NULL)return;   //如果二叉树为空，则算法结束
    Node<T>* Q[maxn];
    Q[++m_rear]=root;   //跟指针入队
    Node<T> *q;
    while(m_front!=m_rear){
        q=Q[++m_front]; //出队操作
        cout<<q->data<<" ";
        if(q->lchild!=NULL)Q[++m_rear]=q->lchild;
        if(q->rchild!=NULL)Q[++m_rear]=q->rchild;
    }
}

//建立二叉树
template <class T>
Node<T>* BiTree<T>::create(Node<T> *bt){
    char ch;
    cin>>ch;
    if(ch=='#')bt=NULL;
    else{
        bt=new Node<T>();   //生成一个节点
        bt->data=ch;
        bt->lchild=create(bt->lchild);  //递归建立左子树
        bt->rchild=create(bt->rchild);  //递归建立右子树
    }
    return bt;
}
//析构函数
template <class T>
void BiTree<T>::release(Node<T> *bt){
    if(bt!=NULL){
        release(bt->lchild);    //释放左子树
        release(bt->rchild);    //释放右子树
        delete bt;
    }
}
int main()
{
    BiTree<char> tree;
    cout<<"前序遍历"<<endl;
    tree.preOrder();
    cout<<endl;
    cout<<"中序遍历"<<endl;
    tree.inOrder();
    cout<<endl;
    cout<<"后序遍历"<<endl;
    tree.postOrder();
    cout<<endl;
    cout<<"层次遍历"<<endl;
    tree.levelOrder();
    return 0;
}
