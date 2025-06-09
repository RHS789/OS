#include<stdio.h> 
#include<conio.h> 
int main() 
{ 
    int n,i,j,b[20],sb[20],t[20],x,c[20][20];  
    printf("Enter no.of files:"); 
    scanf("%d",&n); 
    for(i=0;i<n;i++) 
    { 
        printf("Enter no. of blocks occupied by file%d:",i+1); 
        scanf("%d",&b[i]); 
        printf("Enter the starting block of file%d:",i+1); 
        scanf("%d",&sb[i]); 
        t[i]=sb[i]; 
        for(j=0;j<b[i];j++) 
        c[i][j]=sb[i]++; 
    } 
    printf("Filename\tStart block\tlength\n"); 
    for(i=0;i<n;i++) 
    printf("%d\t\t  %d \t\t%d\n",i+1,t[i],b[i]); 
    printf("Enter file name:"); 
    scanf("%d",&x); 
    printf("File name is:%d\n",x); 
    printf("length is:%d\n",b[x-1]); 
    printf("blocks occupied:"); 
    for(i=0;i<b[x-1];i++) 
    printf("%4d",c[x-1][i]); 
    return 0;
} 


 /*Output

Enter no.of files:2
Enter no. of blocks occupied by file1:1
Enter the starting block of file1:1
Enter no. of blocks occupied by file2:2
Enter the starting block of file2:1
Filename        Start block     length
1                 1             1
2                 1             2
Enter file name:1
File name is:1
length is:1
blocks occupied:   1

 */