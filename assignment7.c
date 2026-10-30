#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 200
char st[MAX];int top=-1;
void push(char c){if(top<MAX-1)st[++top]=c;}
char pop(void){return top>=0?st[top--]:'\0';}
int prec(char c){if(c=='^')return 3;if(c=='*'||c=='/')return 2;if(c=='+'||c=='-')return 1;return 0;}
int main(void){char in[MAX],out[MAX];int i=0,j=0;printf("Enter infix expression (single-letter/digit operands): ");if(!fgets(in,sizeof in,stdin))return 1;
 for(i=0;in[i]&&in[i]!='\n';i++){char c=in[i];if(isalnum((unsigned char)c))out[j++]=c;else if(c=='(')push(c);else if(c==')'){while(top>=0&&st[top]!='(')out[j++]=pop();if(top<0){puts("Mismatched parentheses");return 1;}pop();}else if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'){while(top>=0&&st[top]!='('&&(prec(st[top])>prec(c)||(prec(st[top])==prec(c)&&c!='^')))out[j++]=pop();push(c);}else if(!isspace((unsigned char)c)){puts("Invalid character");return 1;}}
 while(top>=0){if(st[top]=='('){puts("Mismatched parentheses");return 1;}out[j++]=pop();}out[j]='\0';printf("Postfix expression: %s\n",out);return 0;}