#include <iostream>
typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode;

typedef struct {
    LinkNode *front, *rear;
}LinkQueue;