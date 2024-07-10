#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Block{
    int blockNo;
    struct Block *next;
};

struct Block*allocate(int blockNo){
    struct Block* newBlock=(struct Block*)malloc(sizeof(struct Block));
    newBlock->blockNo=blockNo;
    newBlock->next=NULL;
    return newBlock;
}
int main(){
    struct Block*head=NULL;
    struct Block*current=NULL;
    head=allocate(10);
    current=head;
    current->next=allocate(20);
    current->next->next=allocate(30);
    printf("Allocated Block\n");
    current=head;
    while(current!=NULL){
        printf("%d\t",current->blockNo);
        current=current->next;
    }
    printf("\n");

    //freeing memory

    current=head;
    while(current!=NULL){
        struct Block*temp=current;
        current=current->next;
        free(temp);
    }
    return 0;
}