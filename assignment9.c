#include <stdio.h>
#include <string.h>
#define MAX 5
typedef struct{char job[50];}Job;
int main(void){Job q[MAX];int front=-1,rear=-1,ch;char name[50];do{printf("\n1.Add job 2.Delete/process job 3.Display queue 0.Exit\nChoice: ");if(scanf("%d",&ch)!=1)return 1;switch(ch){case 1:if(rear==MAX-1){puts("Queue overflow");break;}printf("Job name (one word): ");scanf("%49s",name);if(front==-1)front=0;rear++;strcpy(q[rear].job,name);puts("Job added");break;case 2:if(front==-1){puts("Queue underflow");break;}printf("Processed job: %s\n",q[front].job);if(front==rear)front=rear=-1;else front++;break;case 3:if(front==-1)puts("Queue is empty");else{int i;for(i=front;i<=rear;i++)printf("%s\n",q[i].job);}break;case 0:break;default:puts("Invalid choice");}}while(ch!=0);return 0;}