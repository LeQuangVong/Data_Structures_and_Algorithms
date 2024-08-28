#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct Stack
{
    int *data; // con trỏ tới mảng động chứa các stack
    int top; //chỉ số của phần tử trên cùng 
    int capacity; //Dung lượng hiện tại của stack (số phần tử tối đa có thể chứa)
};
//Khởi tạo Stack
void initStack(Stack *s, int initialCapacity)
{
    s->data = (int *)malloc(initialCapacity * sizeof(int));
    if (s->data == NULL)
    {
        printf("Memory allocation failed\n");
    }
    s->top = -1;
    s->capacity = initialCapacity;
}

bool isEmpty(const Stack *s)
{
    return s->top == -1;
}

bool isFull(const Stack *s)
{
    return s->top == s->capacity - 1;
}

//Mở rộng dung lượng Stack
void resizeStack(Stack *s)
{
    s->capacity *= 2;
    s->data = (int *)realloc(s->data, s->capacity * sizeof(int));
    if (s->data == NULL)
    {
        printf("Memory allocation failed during resizing\n");
    }
}

//Thêm một phần tử vào stack
void push(Stack *s, int value)
{
    if (isFull(s))
    {
        resizeStack(s);
    }
    s->top = s->top + 1;
    s->data[s->top] = value;
}

//lấy phân tử top ra khỏi Stack
int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
    }
    int t = s->data[s->top];
    s->top = s->top -1;
    return t;
}

//Xem phần tử top 
int peek(Stack *s)
{
        if (isEmpty(s))
    {
        printf("Stack underflow\n");
    }
    return s->data[s->top];
}
//giải phóng Stack
void freeStack(Stack *s)
{
    free(s->data);
    s->top = -1;
    s->data = NULL;
    s->capacity = 0;
}
