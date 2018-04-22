#include <stdio.h>
#include <stdlib.h>

typedef struct process {
    int pid;
    int bt;
} process_t;

typedef struct queue {
    struct queue *next;
    process_t  process;
} queue_t;

process_t create_process(int pid, int bt) {
    process_t new_proc;// = (process
    new_proc.pid = pid;
    new_proc.bt = bt;
    return new_proc;
}

queue_t *create_node(process_t proc) {
    queue_t *new_node = (queue_t *)malloc(sizeof(queue_t));
    new_node->next = NULL;
    new_node->process = proc;
    return new_node;
}

queue_t *enqueue(queue_t *rear, process_t proc) {
    queue_t *new_node = create_node(proc);
    if (rear != NULL) 
       rear->next = new_node;

    return new_node; 
} 

process_t dequeue(queue_t **front) {
    queue_t *temp = *front;
    process_t proc = (*front)->process;
    *front = (*front)->next;
    free(temp);
    temp = NULL;
    return proc;
}

void execute_schedular(queue_t **head) {
    while(*head != NULL) {
        process_t process = dequeue(head);
        printf("\nDispatching job with pid: %d and burst: %d", process.pid, process.bt);
    }
}

void print_queue(queue_t *head){
    printf("\n** Printing Job Queue **\n");
    if(head == NULL)
        printf("\t No job in Queue \n");

    while(head != NULL) {
        printf("pid: %d, burst: %d\n", head->process.pid, head->process.bt);
        head = head->next;
    }
}

int main() {

    queue_t *fcfs_queue_front = create_node(create_process(1, 10));
    queue_t *fcfs_queue_rear = fcfs_queue_front;
    fcfs_queue_rear = enqueue(fcfs_queue_rear, create_process(2, 20));
    fcfs_queue_rear = enqueue(fcfs_queue_rear, create_process(3, 20));
    print_queue(fcfs_queue_front);
    execute_schedular(&fcfs_queue_front);
    print_queue(fcfs_queue_front);
}
