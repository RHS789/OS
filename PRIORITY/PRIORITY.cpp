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
