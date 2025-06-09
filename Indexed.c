#include <stdio.h>

int main() 
{ 
    int n, m[20], i, j, sb[20], s[20], b[20][20]; 

    printf("Enter no. of files: "); 
    scanf("%d", &n); 

    for(i = 0; i < n; i++) 
    { 
        printf("Enter starting block and size of file %d: ", i + 1); 
        scanf("%d%d", &sb[i], &s[i]); 
        
        printf("Enter number of blocks occupied by file %d: ", i + 1); 
        scanf("%d", &m[i]); 
        
        printf("Enter blocks of file %d: ", i + 1); 
        for(j = 0; j < m[i]; j++) 
        {
            scanf("%d", &b[i][j]); 
        }
    } 

    printf("\nFile\tIndex\tLength\n"); 
    for(i = 0; i < n; i++) 
    { 
        printf("%d\t%d\t%d\n", i + 1, sb[i], m[i]); 
    }

    return 0;
}


/*

Enter no. of files: 2
Enter starting block and size of file 1: 1
3
Enter number of blocks occupied by file 1: 7
Enter blocks of file 1: 8
9
6
3
4
Enter starting block and size of file 2: 10
2
Enter number of blocks occupied by file 2: 3
Enter blocks of file 2: 11
12
13

File    Index   Length
1       1       7
2       10      3

*/