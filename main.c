//
//  main.c
//  memoryAlloc
//
//  Created by Danilo Mative on 17/08/2018.
//  Copyright © 2018 Danilo Mative. All rights reserved.
//

#include <stdio.h>
#include "custom_memory.h"

typedef struct t_node {
    uint32_t data;
    struct t_node* next;
    struct t_node* prev;
} node;

void append(node** head_ref, uint32_t new_data)
{
    
    node* new_node = (node*)aloca(sizeof(node));
    
    node* last = *head_ref;
    
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    
    while (last->next != NULL)
    last = last->next;
    
    last->next = new_node;
    new_node->prev = last;
    
    return;
}

void printList(node *list)
{
    node *last;
    printf("\nReading from Head to Tail\n");
    while (list != NULL) {
        printf(" %u ", list->data);
        last = list;
        list = list->next;
    }
    
    printf("\nReading backwards\n");
    while (last != NULL) {
        printf(" %u ", last->data);
        last = last->prev;
    }
    
    printf("\n");
}

void freeList(node *list) {
    printf("Freeing List...\n");
    
    while (list != NULL) {
        node *next = list->next;
        libera(list);
        list = next;
    }
}

int main() {
    clear_heap();
    
    char *pointer = aloca(15);
    libera(pointer);
    
    /*
    node* head2 = NULL;
    node* head = NULL;
    
    append(&head, 32);
    append(&head, 4);
    append(&head2, 15);
    append(&head2, 27);
    append(&head, 44);
    append(&head, 1);
    append(&head2, 16);
    
    printf("Created Doubly Linked List is: ");
    printList(head);
    printf("Created Doubly Linked List 2 is: ");
    printList(head2);
    print_heap();
    freeList(head);
    print_heap();
    */
    
    return 0;
}

