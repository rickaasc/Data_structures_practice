#include <iostream>
using namespace std;

typedef struct LNode{
    int data;  //数据域
    struct LNode *next; //指向下一个结点的指针
}Lnode, *LinkList;

bool InitList(LinkList &L){
    L = new Lnode; //分配一个头结点
    if(!L) return false; //分配失败
    L->next = NULL;  //头结点之后暂时没有结点
    return true;  //初始化成功
}

//指定结点前插 (牛逼啊我草)
bool insertPriorNode(Lnode *p, int e){
    if(!p) return false;
    Lnode *s = new Lnode;
    if(!s) return false;
    s->next = p->next; //s指向p的后继结点
    p->next = s;  //p指向s
    s->data = p->data; //s的数据域与p相同
    p->data = e; //p的数据域改为e
    return true;
}


//指定结点后插
bool insertNextNode(Lnode *p, int e){
    if(!p) return false;
    Lnode *s = new Lnode;
    if(!s) return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}


//按位序插入（带头结点）
bool insert(LinkList &L, int i, int e){
    if (i<1) return false;
    Lnode *p = L;
    int j = 0;
    while(p && j<i-1){
        p = p->next;
        j++;
    }
    return insertNextNode(p, e);
}

//按位序删除
bool deleteNode(LinkList &L, int i, int &e){
    if(i<1) return false;
    Lnode *p = L;
    int j = 0;
    while(p && j<i-1){
        p = p->next;
        j++;
    }
    if(!p->next) return false;
    Lnode *q = p->next;
    e = q->data;
    p->next = q->next;
    delete q;
    return true;
}

//头插法建表
LinkList headInsert(LinkList &L){
    L = new Lnode;
    L->next = NULL;
    int x;
    cin >> x;
    Lnode *s;
    while(x!=9999){
        s = new Lnode;
        s->data = x;
        s->next = L->next;
        L->next = s;
        cin >> x;
    }
}

int main(){
    LinkList L;
    InitList(L);
    return 0;
}