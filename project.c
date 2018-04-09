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
void updateProcesses(struct process proc[], int pTime, int currentProcess){
	for(int i = currentProcess; i<nProcess; i++){
		float waitTime = pTime - proc[i].arrivalTime;
		proc[i].priority = 1  + waitTime/(float)proc[i].burstTime;
	}
	for(int i=currentProcess; i<nProcess-1; i++){
		for(int j=i+1; j<nProcess; j++){
			if(proc[i].priority < proc[j].priority){
				struct process a = proc[j];
				proc[j] = proc[i];
				proc[i] = a;
			}
		}
	}
}

void sortOnArrival(struct process proc[]){
	for(int i=0; i<nProcess-1; ++i){
		for(int j=i+1; j<nProcess; ++j){
			if(proc[i].arrivalTime > proc[j].arrivalTime){
				struct process a = proc[j];
				proc[j] = proc[i];
				proc[i] = a;
			}
		}
	}
}

void startProcessing(struct process proc[]){
	int currentProcess = 0;
	while(currentProcess < nProcess){
		struct process topProcess = proc[currentProcess++];
		pTime =+ topProcess.burstTime;
		updateProcesses(proc,pTime,currentProcess);
	}
}


void printProcess(struct process proc[]){
	for(int i=0; i<nProcess; i++){
		printf("The Proccess :%d arrival time : %d  burst time is: %d\n\n", proc[i].id, proc[i].arrivalTime, proc[i].burstTime);
	}
}

int main()
{
	printf("Enter the number of Process\n");
	scanf("%d",&nProcess);
	while(nProcess < 1){
		printf("Enter Process count greater than one.\n");
		scanf("%d",&nProcess);
	}
	struct process proc[nProcess];

	for(int i=0; i<nProcess; ++i){
		printf("Enter the input for Process %d\n", i+1 );
		proc[i].id = i+1;
		proc[i].priority = 1;
		proc[i].waitTime = 0;
		proc[i].arrivalTime = 0;
		while(proc[i].arrivalTime > -1){
			printf("Enter Arrival Time=");
			scanf("%d",&proc[i].arrivalTime);
			if(proc[i].arrivalTime >= 0)
				break;
		}
		proc[i].burstTime = 0;
		while(proc[i].burstTime > -1){	
			printf("Enter Burst Time=");
			scanf("%d",&proc[i].burstTime);
			if(proc[i].burstTime >= 0)
				break;
		}
		printf("\n");
	}
	sortOnArrival(proc);
	startProcessing(proc);
	printProcess(proc);
	return 0;
}
