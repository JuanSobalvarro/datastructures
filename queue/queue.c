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

void enqueue(struct queue *q, int val)
{
    queuenode *qn = createQueueNode(val);
    if (q->len == 0)
    {
        q->rear = qn;
    }

    queuenode *temp = q->front;
    q->front = qn;
    qn->next = temp;

    q->len++;
}

void dequeue(struct queue *q)
{
    if (q->len == 0)
    {
        return;
    }

    queuenode *uwu = q->front;
    q->front = q->front->next;
    q->len--;
    free(uwu);
}

void printQueue(struct queue *q)
{
    queuenode *temp = q->front;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeQueue(struct queue *q)
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

    q->enqueue = enqueue;
    q->dequeue = dequeue;
    q->print = printQueue;
    q->free = freeQueue;

    return *q;
}