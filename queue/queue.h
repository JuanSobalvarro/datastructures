/**
 * USAGE:
 * The queue structure operates as a "pseudo class",
 * allowing you to work with queues similarly to classes in other languages.
 * Example:
 * queue q = Queue(); // This creates an instance of a queue
 * q.enqueue(q.self, 1); // Enqueues the number 1 to the queue
 * q.dequeue(q.self); // Dequeues the front element from the queue
 * q.print(q.self); // Prints the current queue
 * 
 * Since this is C, not a true class, 
 * you need to free the memory once you're done using the queue:
 * q.free(q.self); // Frees the memory used
 * 
 * !IMPORTANT
 * REMEMBER TO COMPILE YOUR FILE INCLUDING THE queue.h IN YOUR FILE
 * AND ADDING queue.c TO THE COMPILE COMMAND
 * #include "'path'/queue.h"
 * ...
 * 
 * Command: gcc myfile.c (...) 'path'/queue.c
**/
#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct queuenode
{
    int data;
    struct queuenode *next;
} queuenode;

typedef struct queue 
{
    struct queue *self;
    struct queuenode *front;
    struct queuenode *rear;
    int len;

    void (*enqueue)(struct queue*, int);
    void (*dequeue)(struct queue*);
    void (*print)(struct queue*);

    void (*free)(struct queue*);
} queue;

queue Queue();

#ifdef _PRIVATE_

queuenode *createQueueNode(int val);

void enqueue(struct queue *q, int val);

void dequeue(struct queue *q);

void printQueue(struct queue *q);

void freeQueue(struct queue *q);

#endif

#endif
