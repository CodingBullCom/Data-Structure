// File: simple_queue2.c
// Created on: 16th Feb 2017
// Updated on: 16th Feb 2017
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com   
//
// This source code is the part of tutorial series provided on http://www.codingbull.com and 
// it can be used/ distributed without any restriction.  

#include<stdio.h>
#include<stdlib.h>
#define QUEUE_SIZE 10

int array[QUEUE_SIZE], front=0, rear=0;

void enqueue(int data){
    if(rear < QUEUE_SIZE){
       array[rear++] = data;
    }else{
       printf("\n\tError! Queue Overflow");
    }
}

int dequeue(){

    if(front > rear || front == QUEUE_SIZE ){
        printf("\n\tError! Queue underflow");
        return -99999999;
    }else{
        return array[front++];
    }
}

void print_queue(){

    printf("\nPrinting contents of queue\n");
    int i;
    for(i = front; i < rear; i++){
        printf("%d ", array[i]);
    }
    printf("\n"); 
}

int main(){

    int option, data;
    while(1){
       printf("\n1. Enqueue(Add data in queue)\n2. Dequeue(Remove data from queue)\n3. Exit");
       printf("\nEnter your choice: ");
       scanf("%d",&option);
       switch(option){
           case 1:
                  printf("\nEnter data: ");
                  scanf("%d", &data);
                  enqueue(data);
                  break;
           case 2:
                  dequeue();
                  break;
           case 3:
                  exit(0);
      }
      print_queue();
    }
}
