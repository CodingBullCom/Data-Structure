// File: array_simple_example.c
// Created on: 15th Jan 2017
// Updated on: 15th Jan 2017
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com   
//
// This source code is the part of tutorial series provided on http://www.codingbull.com and 
// it can be used/ distributed without any restriction.  

#include <stdio.h>

int main(){

   int i=0, array[] = {1,2,3,4,5,6,7,8,9,10};
   
   //print the content of array
   printf("\nContent of array:: \n");
   for(i=0; i < 10; i++){
     printf("%d ", array[i]);
   }
   
   //print the content of array in reverse order
   printf("\nContent of array in reverse order:: \n");
   for(i=9; i > -1; i--){
       printf("%d ",array[i]);
   }
   

   //printing array content at index 3, 5 and 8
   printf("\nArray content at 3rd position is %d", array[2]);
   printf("\nArray content at 5th position is %d", array[4]);
   printf("\nArray content at 8th position is %d", array[7]);
   
   printf("\n");
}
