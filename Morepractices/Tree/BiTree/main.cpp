#include <iostream>

using namespace std;

template<class T>
struct Node{
    T data;
    Node<T> *lchild,rchild;
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
    void levelOrder();              //层序遍历

public:
    BiTree(){root=create(root);}    //建立一棵二叉树
    ~BiTree(){release(root);}       //析构函数
    void preOrder(){preOrder(root);}   //前序遍历
    void inOrder(){inOrder(root);}      //中序遍历
    void postOrder(){postOrder(root);}
};

//递归方法实现前序遍历
template<class T>
void BiTree<T>::preOrder(Node<T> *bt){
    if(bt==NULL)return;     //递归调用的结束条件
    else{
        cout<<bt->data<<" ";
        preOrder(bt->lchild);
        preOrder(bt->rchild);
    }
}

void BiTree<T>::inOrder(Node<T> *bt){

}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
