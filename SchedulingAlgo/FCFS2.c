#include<stdio.h>
void findWaitingTime(int process[],int n,int bt[],int at[],int wt[]){
    wt[0]=0;
    for(int i=1; i<n ; i++){
        wt[i]=wt[i-1]+at[i-1]+bt[i-1]-(at[i]);
    }
}
void findTurnAroundtime(int process[],int n,int bt[],int at[],int wt[],int tat[]){
    tat[0]=0;
    for(int i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
    }
}
void findAverage(int process[],int n,int at[],int bt[]){
    int wt[n],tat[n],total_wt=0,total_tat=0;
    findWaitingTime(process,n,bt,at,wt);
    findTurnAroundtime(process,n,bt,at,wt,tat);
    printf("Process\t ArrivalTime\t BurstTime\t WaitingTime\t TurnAroundTime\n");
    for(int i=0;i<n;i++){
        total_wt+=wt[i];
        total_tat+=tat[i];
    
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,at[i],bt[i],tat[i],wt[i]);
}
printf("Average Waiting time=%.2f\n",(float)total_wt);
printf("Average Turn Around Time=%.2f\n",(float)total_tat);
}

int main(){
    int p;
    printf("Enter the no of process\n");
    scanf("%d",&p);
    int process[p],b_t[p],a_t[p];
    for(int i=0;i<p;i++){
    printf("Enter the id,at,bt of process %d :",(i+1));
    scanf("%d %d %d",&process[i],&a_t[i],&b_t[i]); 
    }
    
    int n=sizeof(process)/sizeof(process[0]);
    findAverage(process,n,a_t,b_t);

    return 0;
}
