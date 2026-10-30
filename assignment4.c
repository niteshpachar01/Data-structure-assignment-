#include <stdio.h>
#define MAX 100
#define BUCKETS 10
int main(void){float a[MAX],bucket[BUCKETS][MAX];int count[BUCKETS]={0},n,i,j,k=0;float key;
 printf("Number of students (1-%d): ",MAX);scanf("%d",&n);if(n<1||n>MAX)return 1;
 printf("Enter percentages (0 to 100):\n");for(i=0;i<n;i++){scanf("%f",&a[i]);if(a[i]<0||a[i]>100){puts("Invalid percentage");return 1;}}
 for(i=0;i<n;i++){int b=(int)(a[i]/10);if(b>=BUCKETS)b=BUCKETS-1;bucket[b][count[b]++]=a[i];}
 for(i=0;i<BUCKETS;i++){for(j=1;j<count[i];j++){key=bucket[i][j];k=j-1;while(k>=0&&bucket[i][k]>key){bucket[i][k+1]=bucket[i][k];k--;}bucket[i][k+1]=key;}for(j=0;j<count[i];j++)a[0]=a[0],printf("");}
 k=0;for(i=0;i<BUCKETS;i++)for(j=0;j<count[i];j++)a[k++]=bucket[i][j];
 puts("Percentages in ascending order:");for(i=0;i<n;i++)printf("%.2f ",a[i]);puts("");
 puts("Top five scores:");for(i=n-1;i>=0&&i>=n-5;i--)printf("%.2f\n",a[i]);return 0;}