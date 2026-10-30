#include <stdio.h>
#define MAX 100
typedef struct { int row,col,val; } Term;
int main(void) {
 Term a[MAX],simple[MAX],fast[MAX]; int r,c,n,i,j,k,choice,count[MAX]={0},pos[MAX];
 printf("Rows columns: ");scanf("%d%d",&r,&c);
 if(r<1||c<1||r*c>=MAX){puts("Invalid dimensions (max 9x9)");return 1;}
 printf("Enter matrix elements:\n"); n=1;a[0].row=r;a[0].col=c;
 for(i=0;i<r;i++)for(j=0;j<c;j++){int v;scanf("%d",&v);if(v){a[n].row=i;a[n].col=j;a[n].val=v;n++;}}
 a[0].val=n-1;
 printf("Sparse triplet (row col value):\n");for(i=0;i<n;i++)printf("%d %d %d\n",a[i].row,a[i].col,a[i].val);
 printf("1.Simple transpose 2.Fast transpose: ");scanf("%d",&choice);
 simple[0].row=c;simple[0].col=r;simple[0].val=n-1;
 if(choice==1){k=1;for(i=0;i<c;i++)for(j=1;j<n;j++)if(a[j].col==i){simple[k].row=a[j].col;simple[k].col=a[j].row;simple[k].val=a[j].val;k++;}}
 else if(choice==2){for(i=1;i<n;i++)count[a[i].col]++;pos[0]=1;for(i=1;i<c;i++)pos[i]=pos[i-1]+count[i-1];for(i=1;i<n;i++){k=pos[a[i].col]++;fast[k].row=a[i].col;fast[k].col=a[i].row;fast[k].val=a[i].val;}fast[0]=simple[0];}
 else {puts("Invalid choice");return 1;}
 puts("Transpose triplet (row col value):");
 if(choice==1)for(i=0;i<n;i++)printf("%d %d %d\n",simple[i].row,simple[i].col,simple[i].val);
 else for(i=0;i<n;i++)printf("%d %d %d\n",fast[i].row,fast[i].col,fast[i].val);
 return 0;
}