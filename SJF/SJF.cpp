#include <stdio.h>
int main() {
    int n, i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processID[n], burstTime[n], waitingTime[n], turnAroundTime[n];
    printf("Enter Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        processID[i] = i + 1; 
		printf("Process P %d: ",processID[i]);
        scanf("%d", &burstTime[i]);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (burstTime[i] > burstTime[j]) {
                int temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;
                
                temp = processID[i];
                processID[i] = processID[j];
                processID[j] = temp;
            }
        }
    }
    waitingTime[0] = 0; 
    for (i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }
    for (i = 0; i < n; i++) {
        turnAroundTime[i] = burstTime[i] + waitingTime[i];
    }
    printf("\nProcessID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", processID[i], burstTime[i], waitingTime[i], turnAroundTime[i]);
    }
    float totalWaitingTime = 0, totalTurnAroundTime = 0;
    for (i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
    }

    printf("\nAverage Waiting Time = %.2f\n", totalWaitingTime / n);
    printf("Average Turnaround Time = %.2f\n", totalTurnAroundTime / n);

    return 0;
}

