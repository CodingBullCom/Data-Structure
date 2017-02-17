// File: simple_circular_queue.c
// Created on: 17th Feb 2017
// Updated on: 17th Feb 2017
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
    
    if(front <= rear || (rear != front && front > rear)){
        if(front > 0 && rear == QUEUE_SIZE)
           rear = -1;
        if(rear+1 != front)
            array[rear++] = data;
        else
            printf("\nError! Queue Overflow\n");
    } else {
        printf("\nError! Queue Overflow\n");
    }
}

int dequeue(){

    int data = -9999999;
    if(front != rear){
         data = array[front++];
         if(front > rear && front >= QUEUE_SIZE){
             front = 0;
         }
    } else {
         printf("\nQueue underflow");
    }
    return data; 
}

void print_queue(){
   
    int i = front;
    while(1){
      if( i == rear)
         break;
      printf("%d ",array[i++]);
      if(i == QUEUE_SIZE){
         i = 0;
      }
   }
   printf("\n");
}

int main(){
   
     enqueue(10);
     enqueue(20);
     enqueue(30);
     enqueue(40);
     enqueue(50);
     dequeue();
     dequeue();
     dequeue();
     print_queue();
     enqueue(60);
     enqueue(70);
     enqueue(80);
     enqueue(90);
     enqueue(100);
     enqueue(110);
     enqueue(120);
     print_queue();
     enqueue(130);
     enqueue(140);
     enqueue(150);
     print_queue();
     return 0;

}
