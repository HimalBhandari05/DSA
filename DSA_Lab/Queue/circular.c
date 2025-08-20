
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define true 1
#define false 0

struct Queue
{
    int front;
    int rear;
    int data[MAX];
    int size;
};

struct Queue queue = {0, -1 , {0}, 0};

int isFull()
{
    if (queue.size == MAX)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int isEmpty()
{
    if (queue.size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Enqueue(struct Queue *queue, int value)
{
    if (queue->size == MAX)
    {
        printf("Queue is full while entering %d\n", value);
    }
    else
    {
        queue->rear = (queue->rear + 1) % MAX; // Circular increment
        queue->data[queue->rear] = value;
        queue->size++;
        printf("%d is enqueued\n", value);
    }
}

void Dequeue(struct Queue *queue)
{
    int element;
    if (queue->size == 0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        element = queue->data[queue->front];
        queue->front = (queue->front + 1) % MAX;
        queue->size--;
        printf("%d is dequeued\n", element);
    }
}
int main()
{
    Enqueue(&queue, 10);
    Enqueue(&queue, 20);
    Enqueue(&queue, 20);
    Enqueue(&queue, 30);
    Enqueue(&queue, 40);
    Enqueue(&queue, 50);
    Dequeue(&queue);
    Enqueue(&queue, 30);
    Enqueue(&queue, 30);
    Enqueue(&queue, 30);
    return 0;
}