// File: queue_using_stack1.c
// Created on: 18th Feb 2017
// Updated on: 18th Feb 2017
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com   
//
// This source code is the part of tutorial series provided on http://www.codingbull.com and 
// it can be used/ distributed without any restriction.  

#include<stdio.h>
#include<stdlib.h>
#define ARRAY_SIZE 10

int array1[ARRAY_SIZE], array2[ARRAY_SIZE], top1 = 0, top2 = -1;

void push(int *array, int *top, int data){
	
	if(*top < ARRAY_SIZE)
		array[(*top)++] = data;
	else
		printf("\nError! Stack Overflow");	
} 

int pop(int *array, int *top){
	
	if(*top > 0){
		return array[--(*top)];
	}else{
		printf("\nError! Stack underflow");
		return -1;
	}
}

void transfer_stack1_to_stack2(){
	
	top2 = 0;
	while(top1 > 0){
		push(array2, &top2, pop(array1, &top1));
	}
	top1 = 0;
}

void print_queue(){
	
	int count = 0, i = top2-1;
	printf("\nPrinting Contents of Queue\n");
	while(i >= 0){
		printf("%d ", array2[i--]);
		count++;
	}
	
	i = 0;
	while(i < top1){
		printf("%d ", array1[i++]);
		count++;
	}
	if(count == 0)
		printf("\tEmpty Queue");

	printf("\n");
}

void enqueue(int data){
	push(array1, &top1, data);
}

int dequeue(){

	if(top2 < 0){
		transfer_stack1_to_stack2();
	}
	return pop(array2, &top2); 
}

int main(){

	int option, data;
	while(1){
		printf("\n1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Exit");
		printf("\nEnter your option: ");
		scanf("%d", &option);
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
				print_queue();
				break;
			case 4:
			default:
				exit(0);	

		}
	}
	return 0;
}
