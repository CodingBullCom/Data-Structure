// File: simple_stack_example.c
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

int array[stack_size], top=0; //Global variable array and top

void push(int number){
 
  if(top >= stack_size){
      printf("\n\tError! Stack Overflow");
   }else{
      printf("\n\tSuccessful operation! Stack push");
      array[top++] = number;
   }
}

int pop(){
   
   if(top <= 0){
       printf("\n\tError! Stack underflow");
   }else{
       printf("\n\tSuccessful operation! Stack pop");
       return array[--top];
   }
   return -1;
}

void print_stack(){
   
    int counter = top;
    printf("\n\nCurrent stack content:\n");
    if(counter==0){
      printf("\n\tEmpty Stack");
      return;
    }

    while(--counter > -1 ){
        printf("\n\t%d - %d ", counter+1, array[counter]);
    }
}

int main(){

    int number, option;
    do{
       printf("\n1: push \n2: pop \n3: exit \nChoose your option: ");
       scanf("%d",&option);
       switch(option){
           case 1:
                  printf("\nEnter number:");
                  scanf("%d",&number);
                  push(number);
                  break;
           case 2:
                 pop();
                 break;
           case 3:
           default:
                 printf("\nThank you for using our program. Please visit http://www.codingbull.com for more\n");
                 exit(0);
       }
       print_stack();

    }while(1);
}

