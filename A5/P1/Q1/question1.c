#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/*
Author: Teghveer Ateliey
Date created: Dec 8, 2022
Last modified: Dec 8, 2022
Purpose: To be able to add and delete elements in a double linked list
*/

// function definition
struct node *element(struct node *dll, int i);
struct node *add(struct node *dll, int i, int value);
struct node *delete(struct node *dll, int i);

// defining structure of node with integer value and self-referential pointers next and prev
struct node {
    int value;
    struct node *next;
    struct node *prev;
}; // end of structure

// size function returns size of dll as integer, takes first node of dll as input
int size(struct node *dll) {
    int size = 0;
    // iterates through dll while adding to size counter
    while (dll->next != NULL){
        size++;
        dll = dll->next;
    }
    return size;
} // end of size function

// struct function for finding the pointer reference for specific element
// takes first node of dll as input along with wanted index
struct node *element(struct node *dll, int i) {
    struct node *temporary = dll;
    // iterates through dll until it finds the desired index
    for (int j = 0; j < i; j++) {
        temporary = temporary->next;
    }
    // returns pointer at index i
    return temporary;
} // end of element function

// struct function add which adds a node before the index i with int value
// returns the pointer of the first node in the dll
struct node *add(struct node *dll, int i, int value) {
    // creates the new node to be added in
    struct node* added_node = (struct node*)malloc(sizeof(struct node));
    struct node* original = dll;
    // obtains size of the dll
    int indexes = (size(original));

    // if the node to be added is going to be first in the new dll
    if (i == 0) {
        added_node->value = value;
        added_node->next = dll;
        added_node->prev = NULL;
        dll->prev = added_node;
        // returns pointer of first node
        return added_node;
    // if the node to be added is not in the indexes of the dll, it will add to the end of the dll
    } else if (i > indexes || i < 0) {
        // iterates to last node in dll
        while (dll->next != NULL){
            dll = dll->next;
        }
        dll->next = added_node;
        added_node->value = value;
        added_node->next = NULL;
        added_node->prev = dll;
        // returns pointer of first node
        return original;
    // if the node to be added is somewhere inside the indexes of the dll, will add before the node indexed
    } else {
        // obtains the pointers before and after the index desired
        struct node *before = element(dll, i-1);
        struct node *after = element(dll, i);
        before->next = added_node;
        added_node->next = after;
        added_node->value = value;
        added_node->prev = before;
        after->prev = added_node;
        // returns pointer of first node
        return original;
    }
} // end of add function

// struct function delete which deletes the node at index i in the dll
// returns the pointer of the first node in the modified dll
struct node *delete(struct node *dll, int i) {
    // obtains the size of the dll
    struct node* original = dll;
    int indexes = (size(original));

    // if and only if the dll has one node left when the delete function is called
    if (indexes == 0) {
        dll->next = NULL;
        // returns NULL
        return NULL;
    // if the node to be deleted is first in the dll
    } else if (i == 0) {
        dll = dll->next;
        dll->prev = NULL;
        // returns pointer of first node
        return dll;
    // if the node to be deleted is between the first and last node in the dll
    } else if (0 < i && i < indexes) {
        struct node *before = element(dll, i-1);
        struct node *after = element(dll, i+1);
        before->next = after;
        after->prev = before;
        // returns pointer of first node
        return dll;
    // if the node to be deleted is the last node in the dll
    } else if (i == indexes) {
        struct node *before = element(dll, i-1);
        before->next = NULL;
        // returns pointer of first node
        return dll;
    // if the node to be deleted is outside the indexes of the dll
    } else {
        // does nothing, returns pointer of first node
        return dll;
    }
} // end of the delete function

void printNode (struct node *dll) {
    if (dll != NULL) {
        printf("< This: %p - %d - P : %p - N : %p >\n", dll, dll->value, dll->prev, dll->next);
    } else {
        printf("Null Pointer");
    }
}

void printLL (struct node *dll) {
    struct node* ptr = dll;
    printf("---\n");
    while (ptr != NULL) {
        printNode(ptr);
        ptr = ptr->next;
    }
    printf("---\n\n");
}

int main () {
 
    // Testing code! 
    struct node *dll = malloc(sizeof(struct node));
    dll->value = 1;
    printLL(dll);
    dll = add(dll, -1, 3);
    printLL(dll);
    dll = add(dll, -1, 4);
    printLL(dll);
    dll = add(dll, 1, 2);
    printLL(dll);
    dll = add(dll, 2, 7);
    printLL(dll);
    dll = add(dll, 9, -1);
    printLL(dll);
    dll = delete(dll, 2);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll);
    dll = delete(dll, 4);
    printLL(dll);
    dll = delete(dll, 0);
    dll = delete(dll, 0);
    dll = delete(dll, 0);
    dll = delete(dll, 0);
    printLL(dll);
}

/* Expected Output: 

---
< This: 0x1cf8590 - 1 - P : (nil) - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8590 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8590 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf85f0 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf8610 >
< This: 0x1cf8610 - 7 - P : 0x1cf85f0 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8610 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf85f0 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

*/ 