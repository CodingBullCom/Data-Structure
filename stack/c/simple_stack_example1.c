// File: simple_stack_example1.c
// Created on: 11th Feb 2017
// Updated on: 11th Feb 2017
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com   
//
// This source code is the part of tutorial series provided on http://www.codingbull.com and 
// it can be used/ distributed without any restriction.  

#include<stdio.h>
#include<stdlib.h>
#define stack_size 10

void push(int *array, int array_size, int *top, int number){
 
  if(*top >= array_size){
      printf("\n\tError! Stack Overflow");
   }else{
      printf("\n\tSuccessful operation! Stack push");
      array[(*top)++] = number;
   }
}

int pop(int *array, int *top){
   
   if(*top <= 0){
       printf("\n\tError! Stack underflow");
   }else{
       printf("\n\tSuccessful operation! Stack pop");
       return array[--(*top)];
   }
   return -1;
}

void print_stack(int *array, int top){
   
    printf("\n\nCurrent stack content:\n");
    if(top==0){
      printf("\n\tEmpty Stack");
      return;
    }

    while(--top > -1 ){
        printf("\n\t%d - %d ", top+1, array[top]);
    }
}

int main(){

    int array[stack_size], number, option, top=0;
    do{
       printf("\n1: push \n2: pop \n3: exit \nChoose your option: ");
       scanf("%d",&option);
       switch(option){
           case 1:
                  printf("\nEnter number:");
                  scanf("%d",&number);
                  push(array, stack_size, &top, number);
                  break;
           case 2:
                 pop(array, &top);
                 break;
           case 3:
           default:
                 printf("\nThank you for using our program. Please visit http://www.codingbull.com for more\n");
                 exit(0);
       }
       print_stack(array, top);

    }while(1);

    return 0;
}

