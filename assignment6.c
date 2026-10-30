#include <stdio.h>
#include <stdlib.h>
typedef struct Term{int coeff,exp;struct Term*next;}Term;
Term* append(Term*h,int c,int e){Term*n=malloc(sizeof(Term)),*t;if(!n)return h;n->coeff=c;n->exp=e;n->next=NULL;if(!h)return n;for(t=h;t->next;t=t->next);t->next=n;return h;}
Term* create(void){Term*h=NULL;int n,i,c,e;printf("Number of terms: ");scanf("%d",&n);for(i=0;i<n;i++){printf("Coefficient and exponent: ");scanf("%d%d",&c,&e);h=append(h,c,e);}return h;}
void display(Term*h){if(!h){puts("0");return;}while(h){printf("%+dx^%d ",h->coeff,h->exp);h=h->next;}puts("");}
Term* add(Term*a,Term*b){Term*r=NULL;while(a&&b){if(a->exp==b->exp){if(a->coeff+b->coeff)r=append(r,a->coeff+b->coeff,a->exp);a=a->next;b=b->next;}else if(a->exp>b->exp){r=append(r,a->coeff,a->exp);a=a->next;}else{r=append(r,b->coeff,b->exp);b=b->next;}}while(a){r=append(r,a->coeff,a->exp);a=a->next;}while(b){r=append(r,b->coeff,b->exp);b=b->next;}return r;}
void free_list(Term*h){Term*t;while(h){t=h->next;free(h);h=t;}}
int main(void){Term*a=NULL,*b=NULL,*sum;int ch;do{printf("\n1.Create polynomial A 2.Create polynomial B 3.Display 4.Addition 0.Exit\nChoice: ");scanf("%d",&ch);switch(ch){case 1:free_list(a);a=create();break;case 2:free_list(b);b=create();break;case 3:printf("A = ");display(a);printf("B = ");display(b);break;case 4:sum=add(a,b);printf("A + B = ");display(sum);free_list(sum);break;case 0:break;default:puts("Invalid choice");}}while(ch!=0);free_list(a);free_list(b);return 0;}