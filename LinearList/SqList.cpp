#include <iostream>
#define MAXSIZE 10

typedef struct {
    int data[MAXSIZE];
    int length;
}SqList; 

using namespace std;

//初始化线性表
void InitList(SqList &L){
    for(int i=0;i<MAXSIZE;i++){
        L.data[i] = 0;
    }
    L.length = 0;
}

//插入元素
bool InsertList(SqList &L,int i,int e){
    if(i<1||i>L.length+1){
        cout<<"插入位置不合法"<<endl;
        return false;
    }
    if(L.length>=MAXSIZE){
        cout<<"线性表已满"<<endl;
        return false;
    }
    for(int j=L.length;j>=i;j--){
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

//删除元素
bool DeleteList(SqList &L,int i,int &e){
    if(i<1||i>L.length){
        cout<<"删除位置不合法"<<endl;
        return false;
    }
    e = L.data[i-1];
    for(int j=i;j<L.length;j++){
        L.data[j-1] = L.data[j];
    }
    L.length--; 
    cout<<"删除元素成功！删除的元素为"<<e<<endl;
    return true;
}

//按位查找
bool GetElement(SqList &L,int i){
    if(i<1||i>L.length){
        cout<<"查找位置不合法"<<endl;
        return false;
    }
    cout<<"第"<<i<<"个元素为"<<L.data[i-1]<<endl;
    return true;
}

///按值查找
void LocateElement(SqList &L,int e){
    for(int i=0;i<L.length;i++){
        if(L.data[i]==e){
            cout<<"第"<<i+1<<"个元素为"<<e<<endl;
            
        }
        else{
            cout<<"未找到该元素"<<endl;
        }
    }
}

//打印线性表
void PrintList(SqList &L){
    cout<<"线性表元素为："<<endl;
    for(int i=0;i<L.length;i++){
        cout<<L.data[i]<<" ";
    }
    cout<<endl;
}


int main(){
    SqList L;
    InitList(L);
    int e= -1 ;
    InsertList(L,1,1);
    InsertList(L,2,2);
    InsertList(L,3,3);
    InsertList(L,4,114514);
    InsertList(L,5,666123);
    DeleteList(L,2,e);
    GetElement(L,4);
    LocateElement(L,3);
    PrintList(L);
    return 0;
}