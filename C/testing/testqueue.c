#include "../queues/queue/queue.h"
#include "unittest.h"

int main()
{
    queue q = Queue();

    q.enqueue(q.self, 10);

    assert((int)q.isEmpty(q.self), false);
    assert(q.len, 1);
    assert(q.peek(q.self), 10);

    return 0;
}