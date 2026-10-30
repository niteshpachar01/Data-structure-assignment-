#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{int prn;char name[40];struct Node*next;}Node;
Node* add_end(Node*h,int p,const char*n){Node*x=malloc(sizeof(Node)),*t;if(!x)return h;x->prn=p;strncpy(x->name,n,39);x->name[39]='\0';x->next=NULL;if(!h)return x;for(t=h;t->next;t=t->next);t->next=x;return h;}
Node* delete_prn(Node*h,int p){Node*t=h,*prev=NULL;while(t&&t->prn!=p){prev=t;t=t->next;}if(!t){puts("Member not found");return h;}if(prev)prev->next=t->next;else h=t->next;free(t);puts("Member deleted");return h;}
void display(Node*h){if(!h){puts("No members");return;}while(h){printf("%d %s\n",h->prn,h->name);h=h->next;}}
void sort(Node*h){Node*a,*b;int p;char n[40];for(a=h;a;a=a->next)for(b=a->next;b;b=b->next)if(a->prn>b->prn){p=a->prn;a->prn=b->prn;b->prn=p;strcpy(n,a->name);strcpy(a->name,b->name);strcpy(b->name,n);}}
Node* reverse(Node*h){Node*p=NULL,*c=h,*n;while(c){n=c->next;c->next=p;p=c;c=n;}return p;}
Node* merge(Node*a,Node*b){Node dummy,*t=&dummy;dummy.next=NULL;while(a&&b){if(a->prn<=b->prn){t->next=a;a=a->next;}else{t->next=b;b=b->next;}t=t->next;}t->next=a?a:b;return dummy.next;}
void free_list(Node*h){Node*t;while(h){t=h->next;free(h);h=t;}}
int main(void){Node*head=NULL,*other=NULL;int ch,p;char name[40];do{printf("\n1.Add member 2.Delete member 3.Count 4.Display 5.Sort 6.Merge another list 7.Reverse 0.Exit\nChoice: ");if(scanf("%d",&ch)!=1)break;switch(ch){case 1:printf("PRN and name: ");scanf("%d%39s",&p,name);head=add_end(head,p,name);break;case 2:printf("PRN: ");scanf("%d",&p);head=delete_prn(head,p);break;case 3:{int c=0;Node*t;for(t=head;t;t=t->next)c++;printf("Total members: %d\n",c);break;}case 4:display(head);break;case 5:sort(head);puts("Sorted by PRN");display(head);break;case 6:printf("Number of members in second list: ");scanf("%d",&p);while(p-->0){int id;printf("PRN and name: ");scanf("%d%39s",&id,name);other=add_end(other,id,name);}sort(head);sort(other);head=merge(head,other);other=NULL;display(head);break;case 7:head=reverse(head);display(head);break;case 0:break;default:puts("Invalid choice");}}while(ch!=0);free_list(head);free_list(other);return 0;}