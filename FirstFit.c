#include <stdio.h>

void FirstFit(int blockSize[], int m, int processSize[], int n) {
    int i, j;
    int allocation[n];

    for (i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("Process No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int m, n;
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};

    m = sizeof(blockSize) / sizeof(blockSize[0]);
    n = sizeof(processSize) / sizeof(processSize[0]);

    FirstFit(blockSize, m, processSize, n);

    return 0;
}
/*
Process No.     Process Size    Block no.
1               212             2
2               417             5
3               112             2
4               426             Not Allocated
*/