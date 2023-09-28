#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node *next;
} NODEPTR;

typedef struct queue {
    NODEPTR *front, *rear;
} QUEUE;
//this function creates a node
NODEPTR* createNode(int elm) {
    NODEPTR* temp;
    temp = (NODEPTR*) malloc(sizeof(NODEPTR));
    temp->info = elm;
    temp->next = NULL;
    return temp;
}
//inserts a new node at the rear of the queue
void insert(QUEUE *q, int elm) {
    NODEPTR* temp = createNode(elm);
    if (q->front == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}
// deletes the node at the front of the queue and returns its value
int delete(QUEUE *q) {
    NODEPTR* temp;
    int val;
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    } else {
        temp = q->front;
        q->front = q->front->next;
        val = temp->info;
        free(temp);
        if (q->front == NULL)
            q->rear = NULL;
        return val;
    }
}
// prints the elements of the queue from front to rear
void printQueue(QUEUE q) {
    NODEPTR* temp;
    if (q.front == NULL){
        printf("Queue is empty\n");
        return;
    }
    printf("<- F ");
    for (temp = q.front; temp != NULL; temp = temp->next)
        printf("%d ", temp->info);
    printf("<- R\n");
}

int main() {
    QUEUE q = {NULL, NULL};
    int elm, menu;
    while(1) {
        printf("0. exit, 1. insert, 2. delete, 3. print. Input Choice: ");
        scanf("%d", &menu);
        switch(menu) {
            case 0: exit(0);
            case 1: printf("Give element: ");
                    scanf("%d", &elm);
                    insert(&q, elm);
                    break;
            case 2: printf("Popped Value %d\n", delete(&q));
                    break;
            case 3: printQueue(q);
                    break;
            default: printf("Wrong choice\n");
        }
    }
    return 0;
}
// Sample Output 1:
/*
0. exit, 1. insert, 2. delete, 3. print. Input Choice: 1
Give element: 10
0. exit, 1. insert, 2. delete, 3. print. Input Choice: 1
Give element: 20
0. exit, 1. insert, 2. delete, 3. print. Input Choice: 3
<- F 10 20 <- R
0. exit, 1. insert, 2. delete, 3. print. Input Choice: 2
Popped Value: 10
0. exit, 1. insert, 2. delete, 3. print. Input Choice: 3
<- F 20 <- R
0. exit, 1. insert, 2. delete, 3. print. Input Choice: 0
*/

// Sample Output 2:
/*
0. exit, 1. insert, 2. delete, 3. print. Input Choice: 1
Give element: 5
0. exit, 1. insert, 2. delete, 3. print. Input Choice: 1
Give element: 15
0. exit, 1. insert, 2. delete, 3. print. Input Choice: 1
Give element: 25
0. exit, 1. insert, 2. delete, 3. print. Input Choice: 3
<- F 5 15 25 <- R
0. exit, 1. insert, 2. delete, 3. print. Input Choice: 2
Popped Value: 5
0. exit, 1. insert, 2. delete, 3. print. Input Choice: 3
<- F 15 25 <- R
0. exit, 1. insert, 2. delete, 3. print. Input Choice: 0
*/
