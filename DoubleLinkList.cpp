#include  <iostream>
using namespace std;


//双向链表
typedef struct Dnode{
    int data;
    struct Dnode *next; //后继指针域
    struct Dnode *prev; //前驱指针域
}Dnode, *Dlinklist; 

//初始化双向链表
bool InitDlinkList(Dlinklist &L){
    L = new Dnode;
    if(!L) return false; //申请空间失败
    L->next = NULL;
    L->prev = NULL;
    return true;
}

//在p结点之后插入s结点
bool InsertNextDnode(Dnode *p, Dnode *s){
    if(!p || !s) return false;
    s->next = p->next;
    if(!!p->next) //如果p结点有后继结点
    {p->next->prev = s;}
    p->next = s;
    s->prev = p;
    return true;
}

//删除p的后继节点
bool DeleteNextDnode(Dnode *p){
    if(!p) return false;
    Dnode *q = p->next;
    if(!q) return false; 
    p->next = q->next;
    if(!!q->next) //如果q结点有后继结点
    {q->next->prev = p;}
    delete q;
    return true;
}


//销毁双向链表
void DestroyDlinkList(Dlinklist &L){
    while(!!L->next)
    {DeleteNextDnode(L);}
    delete L;
    L = NULL;
}
