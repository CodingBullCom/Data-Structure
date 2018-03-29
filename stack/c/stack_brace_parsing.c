#include<stdio.h>

int main(){

    int top=0, i = 0;
    int result = 1;    //Default value true
    char *input;
    char temp;
    char *string = (char *)malloc(20*sizeof(char));
    printf("enter string:");
    scanf("%s",&input);

    while(input[i] != '\0'){
        temp = input[i];
        if(temp == '{'){
            push(string, temp, &top);
        }else if(temp == '}' && top > 0){
             pop(string, &top);       
        }else {
            result = 0;
            break;
        }    
    }
    
    
    if(result == 0){
        printf("false");
    } else {
        printf("true");
    }
    
}

void push(char *stack, char temp, int *top){
    stack[*top++] = temp;
}

char pop(char *stack, int *top){
    if(top > 0)
        return stack[*top--];
    else 
        return -1;    //Stack Underflow    
}