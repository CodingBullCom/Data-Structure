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

void destroy_linked_list(SLLNode **head){

    SLLNode *temp_node_ptr1 = *head, *temp_node_ptr2 = *head;
    *head = NULL;
    while(temp_node_ptr1 != NULL){

        temp_node_ptr2 = temp_node_ptr1->next;
        temp_node_ptr1->next = NULL;
        free(temp_node_ptr1);
        temp_node_ptr1 = temp_node_ptr2;
    }
}

int main(){

    SLLNode *head = create_new_node(10);
 //   printf("%p %p\n", &head, head);     //Unblock this line and check output to understand address better.
    print_linked_list(head);

    insert_node(head, 20);
    insert_node(head, 30);
    print_linked_list(head);    

    insert_node(head, 40);
    insert_node(head, 50);
    insert_node(head, 60);
    print_linked_list(head);    

    insert_node(head, 70);
    insert_node(head, 80);
    insert_node(head, 90);
    insert_node(head, 100);
    print_linked_list(head);   

    destroy_linked_list(&head);
//  Unblock this line and block Line #55 and Line #90 to verify that the 
//  destroy_linked_list function has really destroyed/ free up the memory location.    
//  printf("\n\n\n %p %d %p\n\n\n", head, head->data, head->next);  
    print_linked_list(head);    
}
