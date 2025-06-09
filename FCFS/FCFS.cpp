#include <stdio.h>
int main() {
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processes[n], burstTime[n], waitingTime[n], turnAroundTime[n];
    printf("Enter process IDs:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &processes[i]);
    }
    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &burstTime[i]);
    }
    waitingTime[0] = 0;
    for (i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i-1] + burstTime[i-1];
    }
    for (i = 0; i < n; i++) {
        turnAroundTime[i] = burstTime[i] + waitingTime[i];
    }
    float totalWaitingTime = 0, totalTurnAroundTime = 0;
    for (i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
    }
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i], burstTime[i], waitingTime[i], turnAroundTime[i]);
    }
    printf("\nAverage waiting time = %.2f\n", totalWaitingTime / n);
    printf("Average turnaround time = %.2f\n", totalTurnAroundTime / n);
    return 0;
}

/*
output:

Enter the number of processes: 5
Enter process IDs:
1 2 3 4 5
Enter burst times:
9 10 12 11 12

Process ID	Burst Time	Waiting Time	Turnaround Time
    1          	9	        0           	9
    2           10	        9	            19
    3       	12	        19	            31
    4       	11	        31	            42
    5       	12	        42	            54


Average waiting time = 20.20
Average turnaround time = 31.00
*/