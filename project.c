#include<stdio.h>

int pTime = 0; //Process Exec Time
int nProcess = 0; //Number of Processes

struct process{
	int id;
	int arrivalTime ;
	int burstTime ;
	int waitTime ;
	double priority ;
};

int main()
{
	printf("Enter the no. of Process\n");
	scanf("%d",&nProcess);
	while(nProcess < 1){
		printf("Enter Process Count greater than one.\n");
		scanf("%d",&nProcess);
	}
	process pros[nProcess];

	for(int i=0; i<nProcess; ++i){
		printf("Enter the input for Process %d\n", i+1 );
		pros[i].id = i+1;
		pros[i].priority = 1;
		pros[i].waitTime = 0;
		pros[i].arrivalTime = 0;
		while(pros[i].arrivalTime > -1){
			printf("Enter Arrival Time=");
			scanf("%d",&pros[i].arrivalTime);
			if(pros[i].arrivalTime > -1)
				break;
		}
		pros[i].burstTime = 0;
		while(pros[i].burstTime > -1){	
			printf("Enter Burst Time=");
			scanf("%d",&pros[i].burstTime);
			if(pros[i].burstTime > -1)
				break;
		}
		printf("\n");
	}
}
