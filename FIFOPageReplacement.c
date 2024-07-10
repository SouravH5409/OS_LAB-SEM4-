#include<Stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX_FRAMES 3
#define MAX_PAGES 20

int frames[MAX_FRAMES];
int rear=-1;
void initialize(){
    for(int i=0;i<MAX_FRAMES;i++){
        frames[i]=-1;
    }
}
void display(){
    for(int i=0;i<MAX_FRAMES;i++){
        if(frames[i]!=-1){
            printf("%d",frames[i]);
        }
        else{
            printf("-");
        }
    }
    printf("\n");
}
void FIFOPage(int pages[],int n){
    int page_fault=0;
    int front=0;

    for(int i=0;i<n;i++){
        int page=pages[i];
        int found=0;
        for(int j=0;j<MAX_FRAMES;j++){
            if(frames[j]==page){
                    printf("Page %d already exist in frame\n",page);
                    found=1;
                    break;
            }
        }
        if(!found){
            page_fault++;
            if(rear<MAX_FRAMES-1){
                    rear++;
            }else{
                rear=0;
            }
            frames[rear]=page;
            printf("Page %d is located in frame %d\n",page,rear);
        }
        display();
    }
    printf("Total Page Faults : %d",page_fault);
}
int main(){
    int pages[MAX_PAGES];
    int n;
    printf("Enter no of pages\n");
    scanf("%d",&n);
    printf("Enter the page sequence\n");
    for(int i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }
    initialize();
    FIFOPage(pages,n);
    return 0;
}



/* OUTPUT
Enter no of pages
7
Enter the page sequence
1 3 0 3 5 7 3
Page 1 is located in frame 0
1--
Page 3 is located in frame 1
13-
Page 0 is located in frame 2
130
Page 3 already exist in frame
130
Page 5 is located in frame 0
530
Page 7 is located in frame 1
570
Page 3 is located in frame 2
573
Total Page Faults : 6 */
