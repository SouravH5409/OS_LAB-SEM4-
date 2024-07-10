#include<stdio.h>
#include<stdlib.h>
#define MAX_REQUESTS 100

 void sort(int arr[], int n){
    for(int i=0;i<n-i;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
 }
void CSCAN(int requests[],int n, int head,int disk_Size){
    int totalseekTime=0;
    int currentTrack=head;
    int seekSequence[MAX_REQUESTS];
    int index=0;

    sort(requests,n);

    printf("Seek Sequence :\n");
    for(int i=0;i<n;i++){
        if(requests[i]>=head){
            seekSequence[index++]=requests[i];
            printf("%d->",requests[i]);
            totalseekTime+=abs(currentTrack-requests[i]);
            currentTrack=requests[i];
        }
    }
    if(currentTrack!=disk_Size-1){
        totalseekTime+=abs(currentTrack-(disk_Size-1));
        currentTrack=disk_Size-1;
        printf("%d->",currentTrack);
    }
    totalseekTime+=abs(currentTrack-0);
    currentTrack=0;
    printf("%d->",currentTrack);
    for(int i=0;i<n;i++){
        if(requests[i]<head){
            seekSequence[index++]=requests[i];
            printf("%d->,",requests[i]);
            totalseekTime+=abs(currentTrack-requests[i]);
        }
    }
    printf("End\n");
    printf("TotalSeekTime %d\n",totalseekTime);
    printf("Average SeekTime %d",(float)totalseekTime/n);
}
int main() {
    int numRequests;
    int requests[MAX_REQUESTS];
    int head, disk_size;

    printf("Enter the number of disk requests: ");
    scanf("%d", &numRequests);
    if (numRequests <= 0 || numRequests > MAX_REQUESTS) {
        printf("Invalid number of requests\n");
        return 1;
    }

    printf("Enter disk requests (track numbers):\n");
    for (int i = 0; i < numRequests; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the disk size: ");
    scanf("%d", &disk_size);

    CSCAN(requests, numRequests, head, disk_size);

    return 0;
}