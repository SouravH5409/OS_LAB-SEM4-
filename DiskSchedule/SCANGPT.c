#include<stdio.h>
#include<stdlib.h>

#define MAX_REQUESTS 200
void sort(int arr[],int n){
    int temp;
    for(int i=0;i<n-i;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void SCAN(int requests[],int n,int head,int diskSize,int direction ){
    int totalSeekTime=0;
    int currentTrack=head;
    int seekSequence[MAX_REQUESTS];
    int index=0;

    sort(requests,n);
    printf("seek sequence :\n");
    if(direction==1){
        for(int i=0;i<n;i++){
            if(requests[i]>=head){
                seekSequence[index++]=requests[i];
                printf("%d->",requests[i]);
                totalSeekTime+=abs(currentTrack-requests[i]);
                currentTrack=requests[i];
            }
        }
        if(currentTrack!=diskSize-1){
            totalSeekTime+=abs(currentTrack-(diskSize-1));
            currentTrack=diskSize-1;
            printf("%d->",currentTrack);
        }
        for(int i=n-1;i>=0;i--){
            if(requests[i]<head){
                seekSequence[index++]=requests[i];
                printf("%d->",requests[i]);
                totalSeekTime+=abs(currentTrack-requests[i]);
                currentTrack=requests[i];
            }
        }
    }else{
        for(int i=n-1;i>=0;i--){
            if(requests[i]<=head){
                seekSequence[index++]=requests[i];
                printf("%d->",requests[i]);
                totalSeekTime+=abs(currentTrack-requests[i]);
                currentTrack=requests[i];
            }
        }
        if(currentTrack!=0){
            totalSeekTime+=abs(currentTrack-0);
            currentTrack=0;
            printf("%d->",currentTrack);
        }
        for(int i=0;i<n;i++){
            if(requests[i]>head){
                seekSequence[index++]=requests[i];
                printf("%d->",requests[i]);
                totalSeekTime+=abs(currentTrack-requests[i]);
                currentTrack=requests[i];
            }
        }
    }
    printf("End\n");

    printf("Total seek time: %d\n", totalSeekTime);
    printf("Average seek time: %.2f\n", (float)totalSeekTime / n);

}
int main() {
    int numRequests;
    int requests[MAX_REQUESTS];
    int head, disk_size, direction;

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

    printf("Enter the direction (1 for high, 0 for low): ");
    scanf("%d", &direction);

    SCAN(requests, numRequests, head, disk_size, direction);

    return 0;
}
