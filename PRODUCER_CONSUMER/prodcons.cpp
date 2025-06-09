#include<stdio.h>
#include<stdlib.h>
int mutex=1, full=0,empty=3,x=0;
void producer();
void consumer();
int wait(int);
int signal(int);
int main(){
	int n;
	printf("1. Press 1 for Producer\n");
	printf("2. Press 2 for Consumer\n");
	printf("3. Press 3 for Exit\n");
	while(1){
		printf("Enter your choice: ");
		scanf("%d",&n);
		switch(n){
			case 1:
			if((mutex == 1)&&(empty != 0))
				producer();
			else
				printf("Buffer is full!\n");
			break;
			case 2:
			if((mutex == 1)&&(full!=0))
				consumer();
			else
				printf("Buffer is empty!\n");
			break;
			case 3:
			exit(0);			default:
			printf("Invalid choice! Please enter 1,2 or 3.\n");
		}
	}
	return 0;
}
int wait(int s){
	return(--s);
}
	int signal(int s){
		return(++s);
	}
void producer(){
	mutex = wait(mutex);
	full=signal(full);
	empty=wait(empty);
	x++;
	printf("Producer produces item %d\n",x);
	mutex=signal(mutex);
}
void consumer(){
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	printf("Consumer consumes item %d\n",x);
	x--;
	mutex=signal(mutex);
}

