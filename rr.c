#include<stdio.h>
typedef struct{
    int id;
    int bt;
}Process;

void roundRobin(Process processes[], int n,int time_quantum){
    int rem_time[n],wt[n],tat[n];
    for(int i=0;i<n;i++){
        rem_time[i]=processes[i].bt;
    }
    int completed=0;
    int curr_time=0;
    while(completed<n){
        int flag=0;
        for(int i=0;i<n;i++){
        if(rem_time[i]>0){
            flag=1;
            if(rem_time[i]<=time_quantum){
                curr_time+=rem_time[i];
                rem_time[i]=0;

                printf("Process P%d completed at %d\n",processes[i].id,curr_time);
                tat[i]=curr_time;
                wt[i]=tat[i]-processes[i].bt;

            printf("Process P%d  Wt=%d  TAT=%d\n",processes[i].id,wt[i],tat[i]);
            completed++;
            }else{
                curr_time+=time_quantum;
                rem_time[i]-=time_quantum;
            }
        }
    }
    if(!flag){
        break;
    }
    }
float awt=0,atat=0;
for(int i=0;i<n;i++){
    awt+=wt[i];
    atat=tat[i];
}
printf("Average WT=%.2f  Average TAT=%.2f\n",awt/n,atat/n);
}
int main(){
    int n=3;
    int time_q=2;
    Process processes[]={{1,3},{2,1},{3,5}};
    printf("RoundRobin\n\n");
    roundRobin(processes,n,time_q);
}