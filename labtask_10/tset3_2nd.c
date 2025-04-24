#include <stdio.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->data[++(q->rear)] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    int val = q->data[q->front++];
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return val;
}

void findFirstNonRepeating(Queue* q) {
    int arr[MAX], freq[1000] = {0};
    int n = 0;

    while (!isEmpty(q)) {
        arr[n] = dequeue(q);
        freq[arr[n]]++;
        n++;
    }

    for (int i = 0; i < n; i++) {
        if (freq[arr[i]] == 1) {
            printf("First non-repeating element is: %d\n", arr[i]);
            return;
        }
    }
    printf("No non-repeating element found.\n");
}

int main() {
    Queue q;
    initQueue(&q);

  
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 3);
    enqueue(&q, 2);

    findFirstNonRepeating(&q);

    return 0;
}
