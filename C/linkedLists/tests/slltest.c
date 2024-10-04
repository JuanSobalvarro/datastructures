#include <assert.h>
#include <stdio.h>
#include "singlylinkedlist.h"

void test_create_list() {
    singlyLinkedList ll = createSinglyLinkedList();
    ll.print(ll.self);
    assert(ll.head == NULL);
    assert(ll.len == 0);
    ll.free(&ll);
    printf("test_create_list passed!\n");
}

void test_insert() {
    singlyLinkedList ll = createSinglyLinkedList();
    ll.insert(ll.self, 10);
    ll.print(ll.self);
    assert(ll.len == 1);
    assert(ll.head->data == 10);
    ll.free(ll.self);
    printf("test_insert passed!\n");
}

void test_delete() {
    singlyLinkedList ll = createSinglyLinkedList();
    ll.insert(ll.self, 20);
    ll.delete(ll.self);
    ll.print(ll.self);
    assert(ll.head == NULL);
    assert(ll.len == 0);
    ll.free(ll.self);
    printf("test_delete passed!\n");
}

void test_insertAt() {
    singlyLinkedList ll = createSinglyLinkedList();
    ll.insert(ll.self, 30);
    ll.insertAt(ll.self, 40, 1);
    ll.insertAt(ll.self, 50, 1);
    ll.print(ll.self);
    assert(ll.len == 3);
    assert(ll.head->data == 30);
    assert(ll.head->next->data == 50);
    assert(ll.head->next->next->data == 40);
    ll.free(ll.self);
    printf("test_insertAt passed!\n");
}

void test_deleteAt() {
    singlyLinkedList ll = createSinglyLinkedList();
    ll.insert(ll.self, 60);
    ll.insert(ll.self, 70);
    ll.insert(ll.self, 80);
    ll.deleteAt(ll.self, 1);  // Eliminar el valor 70
    ll.print(ll.self);
    assert(ll.len == 2);
    assert(ll.head->data == 60);
    assert(ll.head->next->data == 80);
    ll.free(ll.self);
    printf("test_deleteAt passed!\n");
}

void test_free() {
    singlyLinkedList ll = createSinglyLinkedList();
    ll.insert(ll.self, 90);
    ll.insert(ll.self, 100);
    ll.free(ll.self);  // Liberar la memoria
    printf("test_free passed!\n");
}

int main() {
    test_create_list();
    // test_insert();
    // test_delete();
    // test_insertAt();
    // test_deleteAt();
    // test_free();
    
    printf("All tests passed!\n");
    return 0;
}
