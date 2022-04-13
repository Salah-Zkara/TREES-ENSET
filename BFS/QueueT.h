#ifndef _QueueT
#define _QueueT

typedef struct TNode
{
    int data;
    struct TNode *left;
    struct TNode *right;
} TNode ;

typedef struct Tree{
    TNode *root;
} Tree;


typedef struct QNode
{
    TNode Ndata;
    struct QNode *next;
} QNode ;

typedef struct Queue{
	QNode *Head,*Tail;
} Queue;

QNode* newNode(TNode);
Queue* newQueue();
void Enqueue(Queue *,TNode);
QNode* Dequeue(Queue *);

#endif