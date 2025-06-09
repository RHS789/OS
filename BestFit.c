#include <stdio.h>

void bestFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[50], occupied[50];
    int i, j;

    for (i = 0; i < processes; i++)
        allocation[i] = -1;

    for (i = 0; i < blocks; i++)
        occupied[i] = 0;

    for (i = 0; i < processes; i++) {
        int indexPlaced = -1;

        for (j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i] && !occupied[j]) {
                if (indexPlaced == -1 || blockSize[j] < blockSize[indexPlaced]) {
                    indexPlaced = j;
                }
            }
        }

        if (indexPlaced != -1) {
            allocation[i] = indexPlaced;
            occupied[indexPlaced] = 1;
        }
    }

    printf("Process No.\tProcess Size\tBlock No.\n");

    for (i = 0; i < processes; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int blocks = sizeof(blockSize) / sizeof(blockSize[0]);
    int processes = sizeof(processSize) / sizeof(processSize[0]);

    bestFit(blockSize, blocks, processSize, processes);

    return 0;
}
/*
Process No.     Process Size    Block No.
1               212             4
2               417             2
3               112             3
4               426             5
*/