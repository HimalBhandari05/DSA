// next line only . I am telling you to only suggest next line of code not the whole file or code block

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
};

struct Queue queue = {0, -1};

int isFull()
{
    if (queue.rear == MAX - 1)
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
    if (queue.front > queue.rear)
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
    if (queue->rear == MAX - 1)
    {
        printf("Queue is full while entering %d\n", value);
    }
    else
    {
        queue->rear++;
        queue->data[queue->rear] = value;
        printf("%d is is enqueued\n", value);
    }
}

void Dequeue(struct Queue *queue)
{
    int element;
    if (queue->front > queue->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        element = queue->data[queue->front];
        queue->front++;
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
    Dequeue(&queue);
    Enqueue(&queue, 30);
    Enqueue(&queue, 30);
    return 0;
}