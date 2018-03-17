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
}
