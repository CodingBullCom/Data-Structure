#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

typedef struct node {
    char ch;
    int count;
} node;


char *compress(char *str) {
     int  j = 0, index=0;
     char *new_str;
     node *temp_array = (node *)malloc(strlen(str)*sizeof(node));
     node temp = {str[0], 1};
     while(str[index] != '\0') {
         if( index > 0 && temp.ch == str[index]) {
            temp.count++;
         } else {
             temp_array[j++] = (node){temp.ch, temp.count};
             temp = (node){str[index], 1};
         }
         index++ ;
     }
     temp_array[j++] = (node){temp.ch, temp.count};

     new_str = (char *)malloc((2*j + 1)*sizeof(char));
     new_str[2*j] = '\0';
     while ( j-- != 0 ) {
          temp = temp_array[j];
          new_str[2*j - 1] = '0'+temp.count;
          new_str[2*j - 2] = temp.ch;
     }
     return new_str;
}

int main() {
    printf("\n");
    printf("%s\n", compress("aaaabbbcdd"));     //a4b3c1d2
    printf("%s\n", compress("abcde"));     //a1b1c1d1e1
    printf("%s\n", compress("abbcccddddeeeeeffffff"));     //a4b3c1d2
    printf("\n");
}
