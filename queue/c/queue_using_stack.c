// File: queue_using_stack.c
// Created on: 15th Feb 2017
// Updated on: 15th Feb 2017
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com   
//
// This source code is the part of tutorial series provided on http://www.codingbull.com and 
// it can be used/ distributed without any restriction.  

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int array1[100000], array2[100000], top1=-1, top2=-1;

void push(int *array, int *top, int data){
    array[++(*top)] = data;
}

int pop(int *array, int *top){
    return array[(*top)--];
}

void transfer_data_to_stack2(){

    int i = top1;
    top2 = -1;
    while(i-- > -1){
        push(array2, &top2, pop(array1, &top1));
    }
}

void enqueue(int data){
    push(array1, &top1, data);
}

void dequeue(){

    if(top2 < 0){
        transfer_data_to_stack2();
    }     
    pop(array2, &top2);
}

void print_top(){

    if(top2 < 0){
        transfer_data_to_stack2();
    }
    printf("%d\n", array2[top2]);
}
    
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int tests = 0, option = 0, data = 0;
    scanf("%d", &tests);
    while(tests-- > 0){
        scanf("%d", &option);
        switch(option){
            case 1:
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                print_top();
                break;
        }
    }
    return 0;
}