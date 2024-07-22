#include<stdio.h>
#include<string.h>

void bestFit(int blockSize[],int m,int processSize[],int n){
    int allocation[n];
    memset(allocation,-1,sizeof(allocation));
    for(int i=0;i<n;i++){
        int bstIdx=-1;
        for(int j=0;j<m;j++){
            if(blockSize[j]>processSize[i]){
                if(bstIdx==-1 || blockSize[bstIdx]>blockSize[j]){
                    bstIdx=j;
                }
            }
        }
        if(bstIdx!=-1){
            allocation[i]=bstIdx;
            blockSize[bstIdx]-=processSize[i];
        }
    }
    printf("Process\tProcessSize\nBlockNo\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t",i+1,processSize[i]);
        if(allocation[i]!=-1){
            printf("%d",allocation[i]+1);
        }else{
            printf("Not Allocated");
        }
        printf("\n");
    }
    printf("Free Blocks\n");
    for(int i=0;i<m;i++){
        printf("%d->",blockSize[i]);
    }
}

int main(){
    int blockSize[]={100,500,200,300,600};
    int processSize[]={212,417,112,426};
    int m=sizeof(blockSize)/sizeof(blockSize[0]);
    int n=sizeof(processSize)/sizeof(processSize[0]);
    bestFit(blockSize,m,processSize,n);
    return 0;
}
