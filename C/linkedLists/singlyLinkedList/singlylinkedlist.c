#include "singlylinkedlist.h"

// PRIVATE FUNCTIONS

node *createNode(int val)
{
    node *n = malloc(sizeof(node));

    if (!n)
    {
        return NULL;
    }
    n->data = val;
    n->next = NULL;

    return n;
}

void __insert(struct singlyLinkedList* ll, int val)
{
    if (ll->len == 0)
    {
        ll->head = createNode(val);
        ll->len++;
        return;
    }

    node* temp = ll->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = createNode(val);
    ll->len++;
}

void __deleteHead(struct singlyLinkedList* ll)
{
    if (!ll->head)
    {
        return;
    }

    node* temp = ll->head;
    ll->head = ll->head->next;
    free(temp);
}

void __insertat(struct singlyLinkedList *ll, int val, int pos)
{
    if (pos < 0)
    {
        return;
    }
    else if (pos > ll->len)
    {
        pos = ll->len;
    }
    else if (pos == 0)
    {
        node *head = ll->head;
        ll->head = createNode(val);
        ll->head->next = head;

        ll->len++;
        return;
    }
    
    
    node *temp = ll->head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    
    node *next = temp->next;
    temp->next = createNode(val);
    temp->next->next = next;
    ll->len++;
}

void __deleteat(struct singlyLinkedList *ll, int pos)
{
    if (pos < 0)
    {
        printf("Position not valid\n");
        return;
    }
    else if (pos > ll->len)
    {
        printf("Position not valid deleting at the end\n");
        pos = ll->len - 1;
    }
    else if (pos == 0 && ll->head != NULL)
    {
        node *tmp = ll->head->next;

        free(ll->head);
        ll->head = tmp;

        ll->len--;
        return;
    }

    node *temp = ll->head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    node *next = temp->next;
    temp->next = next->next;
    free(next);
    ll->len--;
}

void __print(struct singlyLinkedList *ll)
{
    printf("List with len %d:\n", ll->len);
    node *temp = ll->head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}   

void __freell(struct singlyLinkedList *ll)
{
    while(ll->len != 0)
    {
        __deleteHead(ll);
    }
    free(ll->self);
}

singlyLinkedList createSinglyLinkedList()
{
    singlyLinkedList *ll = malloc(sizeof(singlyLinkedList));
    
    ll->self = ll;

    ll->head = NULL;
    ll->len = 0;

    ll->insert = __insert;
    ll->delete = __deleteHead;
    ll->insertAt = __insertat;
    ll->deleteAt = __deleteat;
    ll->print = __print;
    ll->free = __freell;

    return *ll;
}
