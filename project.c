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

void sortOnArrival(struct process proc[]);
void startProcessing(struct process proc[]);
void updateProcesses(struct process proc[], int processTime, int currentProcess);
void printProcess(struct process proc[]);

int main()
{
	printf("Enter the no. of Process\n");
	scanf("%d",&nProcess);
	while(nProcess < 1){
		printf("Enter Process Count greater than one.\n");
		scanf("%d",&nProcess);
	}
	process proc[nProcess];

	for(int i=0; i<nProcess; ++i){
		printf("Enter the input for Process %d\n", i+1 );
		proc[i].id = i+1;
		proc[i].priority = 1;
		proc[i].waitTime = 0;
		proc[i].arrivalTime = 0;
		while(proc[i].arrivalTime > -1){
			printf("Enter Arrival Time=");
			scanf("%d",&proc[i].arrivalTime);
			if(proc[i].arrivalTime > -1)
				break;
		}
		proc[i].burstTime = 0;
		while(proc[i].burstTime > -1){	
			printf("Enter Burst Time=");
			scanf("%d",&proc[i].burstTime);
			if(proc[i].burstTime > -1)
				break;
		}
		printf("\n");
	}
	sortOnArrival(pros);
	startProcessing(pros);
	printProcess(pros);
	return 0;
}

void sortOnArrival(struct process proc[]){
	for(int i=0; i<nProcess-1; ++i){
		for(int j=i+1; j<nProcess; ++j){
			if(proc[i].arvTime > proc[j].arvTime){
				process a = proc[j];
				proc[j] = proc[i];
				proc[i] = a;
			}
		}
	}
}

void startProcessing(struct process proc[]){
	int currentProcess = 0;
	while(currentProcess < no_process){
		process topProcess = proc[currentProcess++];
		processTime =+ topProcess.burstTime;
		updateProcesses(pros,processTime,currentProcess);
	}
}

