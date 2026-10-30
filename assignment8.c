#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 256
int main(void){char line[1024],*tok;long stack[MAX],a,b;int top=-1;printf("Enter space-separated postfix expression: ");if(!fgets(line,sizeof line,stdin))return 1;tok=strtok(line," \t\r\n");while(tok){char*end;long v=strtol(tok,&end,10);if(*tok&&*end=='\0'){if(top==MAX-1){puts("Stack overflow");return 1;}stack[++top]=v;}else if(strlen(tok)==1&&strchr("+-*/",tok[0])){if(top<1){puts("Invalid expression");return 1;}b=stack[top--];a=stack[top--];switch(tok[0]){case '+':v=a+b;break;case '-':v=a-b;break;case '*':v=a*b;break;default:if(!b){puts("Division by zero");return 1;}v=a/b;}stack[++top]=v;}else{printf("Invalid token: %s\n",tok);return 1;}tok=strtok(NULL," \t\r\n");}if(top!=0){puts("Invalid postfix expression");return 1;}printf("Result: %ld\n",stack[top]);return 0;}