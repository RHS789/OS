#include<stdio.h>
int main(){
	int i,j,n;
	printf("Enter Number of Processes: ");
	scanf("%d",&n);
	int processID[n],BurstTime[n],WaitingTime[n],TurnAroundTime[n],Priority[n];
	for(i=0;i<n;i++){
		printf("Enter Burst Time and Priority Value for Process %d: ",i+1);
		scanf("%d %d",&BurstTime[i],&Priority[i]);
		processID[i]=i+1;
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if (Priority[i]<Priority[j]){
				int temp=BurstTime[i];
				BurstTime[i]=BurstTime[j];
				BurstTime[j]=temp;

				temp=Priority[i];
				Priority[i]=Priority[j];
				Priority[j]=temp;

				temp=processID[i];
				processID[i]=processID[j];
				processID[j]=temp;
			}
		}
	}
	WaitingTime[0]=0;
	for(i=1;i<n;i++){
		WaitingTime[i]=WaitingTime[i-1]+BurstTime[i-1];
	}
	for(i=0;i<n;i++){
		TurnAroundTime[i]=WaitingTime[i]+BurstTime[i];
	}
	printf("Order of process Execution is\n");
	int time=0;
	for(i=0;i<n;i++){
		printf("P%d is executed from %d to %d\n", processID[i] , time ,time + BurstTime[i]);
		time+=BurstTime[i];
	}
	printf("Process Id\tBurst Time\tWait Time\tTurnaround Time\n");
	for(i=0;i<n;i++){
		printf("P%d\t\t%d\t\t%d\t\t%d\n",processID[i],BurstTime[i],WaitingTime[i],TurnAroundTime[i]);
	}
}


/*

output:


Enter Number of Processes: 4
Enter Burst Time and Priority Value for Process 1: 6 3
Enter Burst Time and Priority Value for Process 2: 8 1
Enter Burst Time and Priority Value for Process 3: 7 4
Enter Burst Time and Priority Value for Process 4: 3 2
Order of process Execution is
P3 is executed from 0 to 7
P1 is executed from 7 to 13
P4 is executed from 13 to 16
P2 is executed from 16 to 24

Process Id	Burst Time	Wait Time	Turnaround Time
	P3			7			0			7
	P1			6			7			13
	P4			3			13			16
	P2			8			16			24


*/