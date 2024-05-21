#include "../queue/queue.h"

int main()
{
    queue q = Queue();

    q.enqueue(q.self, 4);

    q.print(q.self);

    q.enqueue(q.self, 5);

    q.print(q.self);

    q.dequeue(q.self);

    q.print(q.self);

    q.enqueue(q.self, -1);

    q.print(q.self);

    q.dequeue(q.self);

    q.print(q.self);

    q.free(q.self);

    return 0;
}