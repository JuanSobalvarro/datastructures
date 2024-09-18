#include "../stack/stack.h"

int main()
{
    stack s = Stack();

    s.pop(&s);

    s.push(&s, 10);

    s.print(&s);

    s.pop(&s);

    s.push(&s, 3);
    
    s.push(&s, -5);
    
    s.print(&s);
    
    s.push(&s, -999);

    s.print(&s);

    s.pop(&s);

    s.print(&s);

    printf("Size of stack: %d\n", s.len);

    return 0;
}