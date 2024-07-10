#include<stdio.h>
typedef struct{
    int id;
    int at;
    int bt;
    int wt;
    int tat;
    int ct;
}Process;
void main(){
    Process processes[]={{1,0,5},{2,1,4},{3,2,1},{4,3,2},{5,4,1}};
    int n=sizeof(processes)/sizeof(Process);

    int currTime=0;
    printf("Process\t Total Time\n");
    for(int i=0;i<n;i++){
        int executionTime=processes[i].bt;
        currTime+=executionTime;
        printf("%d\t\t%d\n",processes[i].id,currTime);
        processes[i].ct=currTime;
        processes[i].tat=processes[i].ct-processes[i].at;
        processes[i].wt=processes[i].tat-processes[i].bt;
        }
        float avg_tat=0.0,avg_wt=0.0;
        printf("Processes\tArrivalTime\tBurstTime\tWaitingTime\tTurnAroundTime\n");
        for(int i=0;i<n;i++){
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",processes[i].id,processes[i].at,processes[i].bt,processes[i].wt,processes[i].tat);
            avg_tat+=processes[i].tat;
            avg_wt+=processes[i].wt;
        }
        printf("Average WaitingTime =%.2f",avg_wt/n);
        printf("Average WaitingTime =%.2f",avg_tat/n);
    }
