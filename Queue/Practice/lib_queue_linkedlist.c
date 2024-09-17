#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    int data;
    Node *next; 
} Node;

typedef struct Queue
{
    Node *front;
    Node *back;
} Queue;

Queue* initQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->back = NULL;
    return q;
}

bool isEmpty(Queue *q)
{
    return (q->front == NULL);
}

void enQueue(Queue *q, int value)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;

    if (q->back == NULL)
    {
        q->front = q->back = temp;
    }

    q->back->next = temp;
    q->back = temp;       
}

int deQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->back = NULL;
    }
    
    free(temp);
    return value;
}

int peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    return q->front->data;
}

void destroyQueue(Queue *q)
{
    while (isEmpty(q))      
    {
        deQueue(q);
    }
    free(q);
}