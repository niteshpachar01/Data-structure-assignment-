#include <stdio.h>
#define MAX 10
void read(int a[MAX][MAX], int r, int c) { int i,j; for(i=0;i<r;i++) for(j=0;j<c;j++) scanf("%d",&a[i][j]); }
void print(int a[MAX][MAX], int r, int c) { int i,j; for(i=0;i<r;i++){ for(j=0;j<c;j++) printf("%d\t",a[i][j]); puts(""); } }
int main(void) {
 int a[MAX][MAX],b[MAX][MAX],x[MAX][MAX],t[MAX][MAX],r,c,r2,c2,i,j,k,ch;
 printf("1.Add 2.Subtract 3.Multiply 4.Transpose\nChoice: "); if(scanf("%d",&ch)!=1)return 1;
 printf("Rows and columns of matrix A: "); scanf("%d%d",&r,&c);
 if(r<1||r>MAX||c<1||c>MAX){puts("Invalid dimensions");return 1;}
 printf("Enter matrix A:\n"); read(a,r,c);
 if(ch==4){for(i=0;i<r;i++)for(j=0;j<c;j++)t[j][i]=a[i][j]; puts("Transpose:");print(t,c,r);return 0;}
 printf("Rows and columns of matrix B: "); scanf("%d%d",&r2,&c2);
 if(r2<1||r2>MAX||c2<1||c2>MAX){puts("Invalid dimensions");return 1;}
 printf("Enter matrix B:\n");read(b,r2,c2);
 if((ch==1||ch==2)&&(r!=r2||c!=c2)){puts("Addition/subtraction requires equal dimensions");return 1;}
 if(ch==3&&c!=r2){puts("Multiplication requires columns of A = rows of B");return 1;}
 if(ch==1||ch==2){for(i=0;i<r;i++)for(j=0;j<c;j++)x[i][j]=(ch==1)?a[i][j]+b[i][j]:a[i][j]-b[i][j];}
 else if(ch==3){for(i=0;i<r;i++)for(j=0;j<c;j++){x[i][j]=0;for(k=0;k<c;k++)x[i][j]+=a[i][k]*b[k][j];}}
 else {puts("Invalid choice");return 1;}
 puts("Result:");print(x,r,(ch==3)?c2:c);return 0;
}