#include"QueueT.h"
#include <stdlib.h>
#include <stdio.h>


QNode* newNode(TNode data){
    QNode *MyNode = (QNode*) malloc(sizeof(QNode));
    MyNode->Ndata = data;
    MyNode->next = NULL;
    return MyNode;
}

Queue* newQueue(){
    Queue *MyQueue = (Queue*)malloc(sizeof(Queue));
    MyQueue->Head = MyQueue->Tail = NULL;
    return MyQueue;
}

void Enqueue(Queue *Q,TNode data){
    QNode *MyNode = newNode(data);
    if (Q->Head == NULL)
        Q->Head = Q->Tail = MyNode;
    else{
        Q->Tail->next = MyNode;
        Q->Tail = MyNode;
    }
}

QNode* Dequeue(Queue *Q){
    if (Q->Tail == NULL)
    {
        printf("The Queue is empty!\n");
        return NULL;
    }
    else{
        QNode *MyNode = Q->Head;
        Q->Head = Q->Head->next;
        //printf("Dequeue: %d\n",MyNode->Ndata.data );
        if (Q->Head == NULL)
            Q->Tail = NULL;
        return MyNode;
    }
}