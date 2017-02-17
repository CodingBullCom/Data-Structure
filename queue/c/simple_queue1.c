// File: simple_queue1.c
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

int array[QUEUE_SIZE], front, rear;

void enqueue(int data){

    if(rear < QUEUE_SIZE)
	array[rear++] = data;
    else
	printf("\nError! Queue overflow");
}

int dequeue(){

    if( front < rear)
        return array[front++];
    else 
        printf("\nError! Queue unerflow");
    
    return -9999999;   //error code
}

void print_queue(){
    
    int i = front;
    for( ; i < rear; i++)
	printf("%d ", array[i]);

    printf("\n");
}  	

int main(){
    
    enqueue(10);
    enqueue(20);
    enqueue(30);
    print_queue();
    dequeue();
    dequeue();
    print_queue();
    enqueue(40);
    enqueue(50);
    print_queue();
    return 0;
} 
