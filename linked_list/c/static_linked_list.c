// File: simple_linked_list1.c
// Created on: 13th Feb 2017
// Updated on: 13th Feb 2017
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com   
//
// This source code is the part of tutorial series provided on http://www.codingbull.com and 
// it can be used/ distributed without any restriction.  

#include<stdio.h>

typedef struct node {
    struct node *next;
    int data;
} SLLNode;   

void print_linked_list(SLLNode *head){
    
    SLLNode *tempNodePtr = head;
    printf("\nContent in Linked List -\n");
    while(tempNodePtr != NULL){
        printf("\n\t%p :: %d, %p",tempNodePtr, tempNodePtr->data, tempNodePtr->next);
        tempNodePtr = tempNodePtr->next;
    }
    printf("\n");
}

int main() {

    SLLNode node0, node1, node2, node3, node4;
    SLLNode *head = &node0;
    node0.data = 10;
    node0.next = NULL;
    print_linked_list(head);

    node1.data = 20;
    node1.next = NULL;
    node0.next = &node1;
    print_linked_list(head);    

    node2.data = 30;
    node2.next = NULL;
    node1.next = &node2;
    print_linked_list(head);    

    node3.data = 40;
    node3.next = NULL;
    node2.next = &node3;
    print_linked_list(head);    

    node4.data = 50;
    node4.next = NULL; 
    node3.next = &node4;
    print_linked_list(head);

    return 0;    
}
