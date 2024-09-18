#include "queue.h"

// PRIVATE FUNCTIONS
queuenode *createQueueNode(int val)
{
    queuenode *qn = malloc(sizeof(queuenode));

    if (qn == NULL)
    {
        printf("Couldnt Allocate memory for new node\n");
        return NULL;
    }

    qn->data = val;
    qn->next = NULL;

    return qn;
}

int _peek(struct queue* q)
{
    return q->front->data;
}

void _enqueue(struct queue *q, int val)
{
    queuenode *qn = createQueueNode(val);
    if (q->isEmpty(q->self))
    {
        q->rear = qn;
    }

    queuenode *temp = q->front;
    q->front = qn;
    qn->next = temp;

    q->len++;
}

void _dequeue(struct queue *q)
{
    if (q->isEmpty(q->self))
    {
        return;
    }

    queuenode *uwu = q->front;
    q->front = q->front->next;
    q->len--;
    free(uwu);
}

void _printQueue(struct queue *q)
{
    queuenode *temp = q->front;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

bool _isEmpty(struct queue *q)
{
    return q->len == 0;
}

void _freeQueue(struct queue *q)
{
    while (q->front != q->rear)
    {
        queuenode *uwu = q->front;
        q->front = q->front->next;
        free(uwu);
    }

    free(q->front);
    free(q->self);
}

// INSTANCE FUNCTION

queue Queue()
{
    queue *q = malloc(sizeof(queue));

    q->self = q;
    q->front = NULL;
    q->rear = q->front;

    q->len = 0;

    q->enqueue = _enqueue;
    q->dequeue = _dequeue;
    q->print = _printQueue;
    q->isEmpty = _isEmpty;
    q->free = _freeQueue;

    return *q;
}