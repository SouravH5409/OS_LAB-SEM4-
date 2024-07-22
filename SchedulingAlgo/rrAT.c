#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int at;
    int bt;
    int remaining;
    int wt;
    int tat;
    int completion;
    int status;
} Process;

typedef struct Node {
    Process processes;
    struct Node *next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(Process processes) {
    Node *newNode = malloc(sizeof(Node));
    newNode->processes = processes;
    newNode->next = NULL;
    if (front == NULL) {  // Fix: Use comparison '==' instead of assignment '='
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

Process dequeue() {
    Node *temp = front;
    Process processes = temp->processes;
    front = front->next;
    free(temp);
    return processes;
}

void printQueue() {
    Node *temp = front;
    while (temp != NULL) {  // Fix: Iterate until 'temp' is NULL, not 'temp->next'
        printf("%d ", temp->processes.id);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Process processes[] = {
        {1, 0, 5, 5, -1, -1, -1, 0},
        {3, 2, 3, 3, -1, -1, -1, 0},
        {4, 3, 1, 1, -1, -1, -1, 0},
        {5, 4, 5, 5, -1, -1, -1, 0},
        {6, 6, 4, 4, -1, -1, -1, 0}
    };
    int n = sizeof(processes) / sizeof(Process);
    int quantum = 4;
    int curr_time = 0;
    int completed = 0;
    
    printf("Time | Process\n");
    printf("------+------\n");
    enqueue(processes[0]);
    processes[0].status = 1;

    while (completed < n) {
        if (front != NULL) {
            Process currentProcess = dequeue();
            int execution_time = (currentProcess.remaining < quantum) ? currentProcess.remaining : quantum;
            currentProcess.remaining -= execution_time;
            curr_time += execution_time;

            for (int i = 0; i < n; i++) {
                if (processes[i].at <= curr_time && processes[i].status == 0) {
                    enqueue(processes[i]);
                    processes[i].status = 1;
                }
            }

            printf("%-5d| P%d\n", curr_time, currentProcess.id);

            if (currentProcess.remaining <= 0) {
                completed++;
                for (int i = 0; i < n; i++) {
                    if (processes[i].id == currentProcess.id) {
                        processes[i].completion = curr_time;
                        break;
                    }
                }
            } else {
                enqueue(currentProcess);
            }
        } else {
            curr_time++;
        }
    }

    float avwt = 0.0;
    float avtat = 0.0;
    printf("Process ArrivalTime BurstTime CompletionTime TurnAroundTime WaitingTime\n");
    for (int i = 0; i < n; i++) {
        processes[i].tat = processes[i].completion - processes[i].at;
        processes[i].wt = processes[i].tat - processes[i].bt;
        printf("P%d%10d%10d%15d%15d%15d\n", processes[i].id, processes[i].at, processes[i].bt, processes[i].completion, processes[i].tat, processes[i].wt);
        avwt += processes[i].wt;
        avtat += processes[i].tat;
    }

    printf("Average Waiting Time = %.2f\n", avwt / n);
    printf("Average Turn Around Time = %.2f\n", avtat / n);

    return 0;
}
