#include <iostream>
#define Maxsiez 50
using namespace std;


typedef struct Queue{
    int data[Maxsiez];
    int front;
    int rear;
}SqQueue;

void InitQueue(SqQueue &Q){
    Q.front = Q.rear = 0;
}

bool QueueEmpty(SqQueue Q){
    if(Q.front == Q.rear) //队空条件
        return true;
    else
        return false;
}

//入队操作
bool EnQueue(SqQueue &Q,int x){
    if((Q.rear+1)%Maxsiez == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear++%Maxsiez;
    return true;
}
//出队操作
bool DeQueue(SqQueue &Q,int &x){
    if(Q.front == Q.rear)
        return false;
    x = Q.data[Q.front];
    Q.front++%Maxsiez;
    return true;
}

//获取队头元素
bool GetHead(SqQueue Q,int &x){
    if(Q.front == Q.rear)
        return false;
    x = Q.data[Q.front];
    return true;
}
