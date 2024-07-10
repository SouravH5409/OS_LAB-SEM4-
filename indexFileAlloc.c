#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_BLOCK 10

struct indexBlock{
    int data_block[MAX_BLOCK];
};
void initializedIndexBlock(struct indexBlock* indexBlock){
    for(int i=0;i<MAX_BLOCK;i++){
        indexBlock->data_block[i]=-1;
    }
}
int allocateBlock(struct indexBlock* indexBlock,int blockNo){
    for(int i=0;i<MAX_BLOCK;i++){
        if(indexBlock->data_block[i]==-1){
            indexBlock->data_block[i]=blockNo;
            return 1;
        }
    }
    return 0;
}
void readData(struct indexBlock* indexBlock,int fileBlockNo){
    int flag=0;
    for(int i=0;i<MAX_BLOCK;i++){
        if(indexBlock->data_block!=-1 && fileBlockNo==indexBlock->data_block[i]){
            printf("Reading from Block : %d\n",indexBlock->data_block[i]);
            flag=1;
        }
}
if(flag==0){
    printf("Block %d is not Allocated\n",fileBlockNo);
}
}

int main(){
    struct indexBlock indexBlock;
    initializedIndexBlock(&indexBlock);
    allocateBlock(&indexBlock,5);
    allocateBlock(&indexBlock,10);
    allocateBlock(&indexBlock,20);

    readData(&indexBlock,5);
    readData(&indexBlock,10);
    readData(&indexBlock,20);
    readData(&indexBlock,12);
    return 0;
}