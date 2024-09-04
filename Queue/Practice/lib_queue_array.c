#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef struct Queue
{
    int array[MAX];
    int front;
    int back;
    int size;
} Queue;

void initQueue(Queue *q);
bool isFull(const Queue *q);
bool isEmpty(const Queue *q);
void enQueue(Queue *q, int value);
int deQueue(Queue *q);
int front(Queue *q);
int back(Queue *q);
void displayQueue(Queue *q);
//Khởi tạo Queue
void initQueue(Queue *q)
{
    q->front = 0;
    q->back = MAX - 1;
    q->size = 0;
}

//kiểm tra Queue có đầy hay không
bool isFull(const Queue *q)
{
    return q->size == MAX;
}
//kiểm tra Queue có trống hay không
bool isEmpty(const Queue *q)
{
    return q->size == 0;
}
//thêm phần tử vào Queue
void enQueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is Full\n");
    }
    q->back = (q->back + 1) % MAX;
    q->array[q->back] = value;
    q->size++;
    /*
        enQueue(&q,10);
        array[0] = 10
        back = 0
        front = 0
        size = 1

        enQueue(&q,20);
        Queue: 10 20
        array[1] = 20
        back = 1
        front = 0
        size = 2

        enQueue(&q,30);
        Queue: 10 20 30
        array[2] = 30
        back = 2
        front = 0
        size = 3
    */
}

int deQueue(Queue *q)
{
    if (isEmpty(s))
    {
        printf("Queue is Empty\n");
    }
    int temp = q->array[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return temp;

    /*
        Queue: 10 20 30
        back = 2
        front = 0
        size = 3
        deQueue(&q);
        Queue: 20 30
        back = 2
        front = 1
        size = 2

        deQueue(&q);
        Queue: 30
        back = 2
        front = 2
        size = 1

        deQueue(&q);
        Queue: 
        back = 2
        front = 3
        size = 0

        enQueue(&q,10);
        Queue: 10
        array[3] = 10
        back = 3
        front = 3
        size = 1
        
        enQueue(&q,20);
        Queue: 10 20
        array[4] = 20
        back = 4
        front = 3
        size = 2

        enQueue(&q,30);
        Queue: 30       10 20 
        array[0] = 30
        back = 0 (MAX = 5, q->back = (q->back + 1) % MAX) => 5%5 = 0
        front = 3
        size = 3

        deQueue(&q);
        Queue: 30           20
        back = 0
        front = 4
        size = 2

        deQueue(&q);
        Queue: 30           
        back = 0
        front = 0 (MAX = 5, q->front = (q->front + 1) % MAX) => 5%5 = 0
        size = 1

    */
}

int front(Queue *q)
{
    if (isEmpty(s))
    {
        printf("Queue is Empty\n");
    }
    return q->array[q->front];
}

int back(Queue *q)
{
    if (isEmpty(s))
    {
        printf("Queue is Empty\n");
    }
    return q->array[q->back];
}

void displayQueue(Queue *q)
{
    if (isEmpty(s))
    {
        printf("Queue is Empty\n");
    }
    
    printf("Queue: ");
    int i = q->front;
    for (int count = 0; count < q->size; count++)
    {
        printf("%d ",q->array[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}