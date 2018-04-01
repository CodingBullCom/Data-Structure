// File: simple_linked_list3.c
// Created on: 13th Feb 2017
// Updated on: 13th Feb 2017
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of tutorial series provided on http://www.codingbull.com and
// it can be used/ distributed without any restriction.

#include<stdio.h>
#include<stdlib.h>

typedef struct node {

    struct node *next;
    int data;

} SLLNode;

SLLNode *create_new_node(int data){

    SLLNode *new_node = (SLLNode *)malloc(sizeof(SLLNode));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node(SLLNode *head, int data){

    SLLNode *new_node = create_new_node(data);
    while(head->next != NULL){
        head = head->next;
    }
    head->next = new_node;
}

SLLNode *delete_node(SLLNode *head, int key){

    SLLNode *start_node = head;
    SLLNode *current_node = head;
    SLLNode *previous_node = NULL;

    if (start_node == NULL)
         return start_node;

    if (start_node->data == key) {
        current_node = start_node->next;
        start_node->next = NULL;
        free(start_node);
        return current_node;
    }

    while(current_node != NULL && current_node->data != key) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    
    if (current_node != NULL) {
        previous_node->next = current_node->next;
        current_node->next = NULL;
        free(current_node);
    } 
    return start_node;
}

void print_linked_list(SLLNode *head){

    printf("\nContent in Linked List -\n");
    if(head == NULL){
        printf("\tEmpty Linked List\n");
        return;
    }

    while(head != NULL){
        printf("\n\t%p :: %d, %p", head, head->data, head->next);
        head = head->next;
    }
    printf("\n");
}

int main(){

    SLLNode *head = create_new_node(10);
 //   printf("%p %p\n", &head, head);     //Unblock this line and check output to understand address better.
    print_linked_list(head);

    insert_node(head, 20);
    insert_node(head, 30);
    print_linked_list(head);

    printf("\nAdding 40, 50, 60");
    insert_node(head, 40);
    insert_node(head, 50);
    insert_node(head, 60);
    print_linked_list(head);
    
    printf("\nAdding 70, 80, 90, 100");
    insert_node(head, 70);
    insert_node(head, 80);
    insert_node(head, 90);
    insert_node(head, 100);
    print_linked_list(head);

    //delete node containing values 10, 30, 70 and 100
    printf("\nDeleting 10, 30, 70, 100");
    head = delete_node(head, 10);
    head = delete_node(head, 30);
    head = delete_node(head, 70);
    head = delete_node(head, 100);
    print_linked_list(head);

    return 0;
}
