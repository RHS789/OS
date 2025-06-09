#include<stdio.h>
#include<stdlib.h>
int mutex=1, full=0,empty=3,x=0;
void producer();
void consumer();

void producer(){
	--mutex;
	++full;
	x++;
	printf("Producer produces item %d\n",x);
	++mutex;
}

void consumer(){
	--mutex;
	--full;
	++empty;
	printf("Consumer consumes item %d\n",x);
	x--;
	++mutex;
}


int main(){
	int n,i;
	printf("1. Press 1 for Producer\n");
	printf("2. Press 2 for Consumer\n");
	printf("3. Press 3 for Exit\n");
	for(i=1;i>0;i++){
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
			exit(0);	
			
			default:
			printf("Invalid choice! Please enter 1,2 or 3.\n");
		}
	}
	return 0;
}



/*

output: 

1. Press 1 for Producer
2. Press 2 for Consumer
3. Press 3 for Exit
Enter your choice: 1
Producer produces item 1
Enter your choice: 1
Producer produces item 2
Enter your choice: 2
Consumer consumes item 2
Enter your choice: 2
Consumer consumes item 1
Enter your choice: 2
Buffer is empty!
Enter your choice: 3

*/