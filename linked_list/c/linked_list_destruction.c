// File: simple_linked_list2.c
// Created on: 13th Feb 2017
// Updated on: 13th Feb 2017
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of tutorial series provided on http://www.codingbull.com and
// it can be used/ distributed without any restriction.

#include<stdio.h>
#include<stdlib.h>

typedef struct SLLNode {
    int data;
    struct SLLNode *next;
} SLLNode;

SLLNode *insert(SLLNode *head, int data){

   if(head == NULL){
       SLLNode *newNode = (SLLNode *)malloc(sizeof(SLLNode));;
       newNode->data = data;
       newNode->next = NULL;
       return newNode;
    }else {
       head->next = insert(head->next, data);
    }
    return head;
}

void print_linked_list(SLLNode *head){

   int i = 0;
   SLLNode *tempNode = head;
   printf("\nPrinting the linked list content\n");
   while(tempNode != NULL){
       printf("\n%p, %d %p",tempNode, tempNode->data, tempNode->next);
       tempNode = tempNode->next;
       i++;
   }
   printf("\n");
   if (i == 0)
      printf("\tNO DATA FOUND TO PRINT\n");
}

SLLNode *destroy_linked_list(SLLNode *head) {
   
    SLLNode *current_node = head;

    while(head != NULL) {
       head = head->next; 
       current_node->next = NULL;
       free(current_node);
       current_node = head;
    }
    return head; 
}

int main(){

   SLLNode *head = NULL;
   head = insert(head, 10);
   head = insert(head, 20);
   head = insert(head, 30);
   print_linked_list(head);

   head = destroy_linked_list(head);
   print_linked_list(head);
   return 0;
}
