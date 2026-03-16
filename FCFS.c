#include<stdio.h>

struct process {
	int pid;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
}; 

int main() {
	int n, i, j; 	
	struct process P[10], temp;
	int current_time = 0;
	
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	
	for(i = 0; i < n; i++) {
		P[i].pid = i + 1;
		
		printf("Enter the arrival time of P%d: ", P[i].pid);
		scanf("%d", &P[i].at);
		
		printf("Enter the burst time of P%d: ", P[i].pid);
		scanf("%d", &P[i].bt);
	}
	
	for(i = 0; i < n - 1; i++) {
    		for(j = 0; j < n - i - 1; j++) {
        		if(P[j].at > P[j+1].at) { // Move the larger AT to the end
			    temp = P[j];
			    P[j] = P[j+1];
			    P[j+1] = temp;
		}
	    }
	}
	for(i = 0; i < n; i++) {
		if(current_time < P[i].at) {
			current_time = P[i].at;
		}
		P[i].ct = current_time + P[i].bt;
		P[i].tat = P[i].ct - P[i].at;
		P[i].wt = P[i].tat - P[i].bt;
		current_time = P[i].ct;
	}
	
	printf("\nPID\tA.T.\tB.T.\tC.T.\tT.A.T\tW.T.\n");
	
	for(i = 0; i < n; i++) {
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", P[i].pid, P[i].at, P[i].bt, P[i].ct, P[i].tat, P[i].wt);
	}
	
	return 0;
}
