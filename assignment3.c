#include <stdio.h>
#include <string.h>
#define N 100
typedef struct { int roll; char name[40]; float marks; } Student;
void show(Student a[],int n){int i;printf("\nRoll\tName\tMarks\n");for(i=0;i<n;i++)printf("%d\t%s\t%.2f\n",a[i].roll,a[i].name,a[i].marks);}
void insertion(Student a[],int n){int i,j;Student key;for(i=1;i<n;i++){key=a[i];j=i-1;while(j>=0&&a[j].roll>key.roll){a[j+1]=a[j];j--;}a[j+1]=key;}}
void selection(Student a[],int n){int i,j,m;Student t;for(i=0;i<n-1;i++){m=i;for(j=i+1;j<n;j++)if(a[j].roll<a[m].roll)m=j;t=a[i];a[i]=a[m];a[m]=t;}}
void shell(Student a[],int n){int gap,i,j;Student t;for(gap=n/2;gap>0;gap/=2)for(i=gap;i<n;i++){t=a[i];for(j=i;j>=gap&&a[j-gap].roll>t.roll;j-=gap)a[j]=a[j-gap];a[j]=t;}}
int main(void){Student a[N];int n,i,ch,key,found=-1,lo,hi,mid;
 printf("Number of students (1-%d): ",N);scanf("%d",&n);if(n<1||n>N)return 1;
 for(i=0;i<n;i++){printf("Roll, name (one word), marks: ");scanf("%d%39s%f",&a[i].roll,a[i].name,&a[i].marks);}
 printf("1.Linear search 2.Binary search (sorts by roll) 3.Insertion sort 4.Selection sort 5.Shell sort\nChoice: ");scanf("%d",&ch);
 if(ch==1||ch==2){printf("Roll to search: ");scanf("%d",&key);if(ch==1){for(i=0;i<n;i++)if(a[i].roll==key){found=i;break;}}else{insertion(a,n);lo=0;hi=n-1;while(lo<=hi){mid=(lo+hi)/2;if(a[mid].roll==key){found=mid;break;}if(a[mid].roll<key)lo=mid+1;else hi=mid-1;}}if(found>=0)printf("Found: %d %s %.2f\n",a[found].roll,a[found].name,a[found].marks);else puts("Student not found");}
 else if(ch==3)insertion(a,n);else if(ch==4)selection(a,n);else if(ch==5)shell(a,n);else{puts("Invalid choice");return 1;}
 if(ch>=3&&ch<=5)show(a,n);return 0;}