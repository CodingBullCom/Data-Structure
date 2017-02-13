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

SLLNode *reverse_linked_list(SLLNode *head){
    
    if(head != NULL){
        SLLNode *temp_node_ptr1 = head->next;
        SLLNode *temp_node_ptr2 = head->next;

        while(temp_node_ptr2 != NULL){
            temp_node_ptr2 = temp_node_ptr2->next;
            temp_node_ptr1->next = head;
            if (head->next == temp_node_ptr1)
                head->next = NULL;
            head = temp_node_ptr1;
            temp_node_ptr1 = temp_node_ptr2;
        }    
    }
    return head;
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
    insert_node(head, 20);
    insert_node(head, 30);
    insert_node(head, 40);
    insert_node(head, 50);
    insert_node(head, 60);
    insert_node(head, 70);
    insert_node(head, 80);
    insert_node(head, 90);
    insert_node(head, 100);
    print_linked_list(head);   

    //Reverse the linked list
    printf("\nCalling Reverse Linked List function");
    head = reverse_linked_list(head);
    printf("\nLinked List after executing the reverse function");    
    print_linked_list(head);   

    destroy_linked_list(&head);
    printf("\nLinked List destroyed/ deleted");
    print_linked_list(head); 

    return 0; 
}
