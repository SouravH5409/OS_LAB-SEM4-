#include<stdio.h>
#include<string.h>

void worstFit(int blockSize[],int m,int ProcessSize[],int n){
    int allocation[n];
    memset(allocation,-1,sizeof(allocation));
    for(int i=0;i<n;i++){
        int wrst_idx=-1;
        for(int j=0;j<m;j++){
            if(blockSize[j]>=ProcessSize[i]){
                if(wrst_idx=-1|| blockSize[wrst_idx]<blockSize[j]){
                    wrst_idx=j;
                }
            }
        }
        if(wrst_idx!=-1){
            allocation[i]=wrst_idx;
            blockSize[wrst_idx]-=ProcessSize[i];
        }
    }
    printf("Process\tProcessSize\tBlockNo\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t",i+1,ProcessSize[i]);
        if(allocation[i]!=-1){
            printf("%d",allocation[i]+1);
        }else{
            printf("Not allocated");
        }
        printf("\n");
    }
    printf("Free Blocks\n");
    for(int i=0;i<m;i++){
        printf("%d->",blockSize[i]);
    }

}

int main(){
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m=sizeof(blockSize)/sizeof(blockSize[0]);
    int n=sizeof(processSize)/sizeof(processSize[0]);
    worstFit(blockSize,m,processSize,n);
    return 0;
}