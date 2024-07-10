#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
pid_t pid =fork();
if(pid<0){
    perror("Child not created");
}
else if(pid==0){
    printf("Hello from Child (PID %d)\n",getpid());
}
else{
    printf("Hello from parent (Child PID %d)",pid);
}
    return 0;
}