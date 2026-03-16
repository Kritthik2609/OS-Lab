#include <stdio.h>

struct Process {
    int pid;
    int burst;
    int waiting;
    int turnaround;
};

int main() {
    int n, i, j;
    struct Process p[20], temp;
    float avg_wait = 0, avg_turn = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Burst Time for P%d: ", p[i].pid);
        scanf("%d", &p[i].burst);
    }

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(p[i].burst > p[j].burst) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int current_time = 0;

    for(i = 0; i < n; i++) {
        p[i].waiting = current_time;
    	avg_wait += p[i].waiting;
    	current_time += p[i].burst;
    }

    for(i = 0; i < n; i++) {
        p[i].turnaround = p[i].waiting + p[i].burst;
        avg_turn += p[i].turnaround;
    }

    avg_wait /= n; 	
    avg_turn /= n;

    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", 
               p[i].pid, 
               p[i].burst, 
               p[i].waiting, 
               p[i].turnaround);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wait);
    printf("\nAverage Turnaround Time = %.2f\n", avg_turn);

    return 0;
}
