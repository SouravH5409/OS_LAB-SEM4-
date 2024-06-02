#include<stdio.h>
#include<stdlib.h>

struct Process {
    int name;
    int at;
    int bt;
    int priority;
};

void Sortprocess(struct Process processes[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if((processes[j].at < processes[i].at) || 
               (processes[j].at == processes[i].at && processes[j].priority < processes[i].priority)) {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

void findWaitingTime(struct Process processes[], int n, int wt[]) {
    wt[0] = 0;
    int w_t[n];
    w_t[0] = 0;
    for(int i = 1; i < n; i++) {
        w_t[i] = w_t[i-1] + processes[i-1].bt;
        wt[i] = w_t[i] - processes[i].at;
    }
}

void findTurnAroundTime(struct Process processes[], int n, int wt[], int tat[]) {
    for(int i = 0; i < n; i++) {
        tat[i] = wt[i] + processes[i].bt;
    }
}

void AverageTime(struct Process processes[], int n) {
    float avg_wt = 0.0;
    float avg_tat = 0.0;
    int tat[n], wt[n];
    findWaitingTime(processes, n, wt);
    findTurnAroundTime(processes, n, wt, tat);
    for(int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    printf("Average Waiting time: %.2f\n", ((float)avg_wt/n));
    printf("Average TurnAround Time: %.2f\n", ((float)avg_tat/n));
}

int main() {
    int n;
    printf("Enter the no of processes:\n");
    scanf("%d", &n);
    struct Process processes[n];
    int tat[n], wt[n];
    printf("Enter Arrival Time, Burst Time, and Priority:\n");
    for(int i = 0; i < n; i++) {
        processes[i].name = i + 1;
        printf("Process P%d: ", (i + 1));
        scanf("%d%d%d", &processes[i].at, &processes[i].bt, &processes[i].priority);
    }
    Sortprocess(processes, n);
    findWaitingTime(processes, n, wt);
    findTurnAroundTime(processes, n, wt, tat);

    printf("ProcessID\t ArrivalTime\t Priority\t Burst Time\t Waiting Time\t TurnAroundTime\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].name, processes[i].at, processes[i].priority, processes[i].bt, wt[i], tat[i]);
    }
    AverageTime(processes, n);
    return 0;
}
