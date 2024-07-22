#include <stdio.h>

typedef struct{
    int name;
    int arrival;
    int burst;
    int completion;
    int waiting;
    int turnaround;
}Process;
int main(){
Process processes[]={{1,0,8},{2,3,2},{3,4,1},{4,5,2}};
int n=sizeof(processes)/sizeof(Process);
int currentTime=0;

printf("Process \t TimeTaken\n");
printf("---------------------------\n");
for(int i=0;i<n;i++){
    int executionTime= processes[i].burst;
    currentTime+=executionTime;
    printf("%d |  %d\n",currentTime,processes[i].name);
    processes[i].completion=currentTime;
    processes[i].turnaround=processes[i].completion-processes[i].arrival;
    processes[i].waiting=processes[i].turnaround-processes[i].burst;
}
float avgwt=0.0;
float avgtat=0.0;
printf("Prrocess ArrivalTime BurstTime TurnAroundTime WaitingTime");
for(int i=0;i<n;i++){
printf("\nP%d%5d%10d%15d%20d\n",processes[i].name,processes[i].arrival,processes[i].burst,
processes[i].turnaround,processes[i].waiting);
avgwt+=processes[i].waiting;
avgtat+=processes[i].turnaround;
}
printf("Average turnaround Time : %.2f\n",(float)avgtat/n);
printf("Average Waiting Time :%.2f",(float)avgwt/n);
return 0;
}
