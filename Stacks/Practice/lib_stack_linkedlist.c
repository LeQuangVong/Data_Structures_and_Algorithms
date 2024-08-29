#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//cấu trúc của Node
typedef struct Node
{
    int data;//Dữ liệu của nút
    struct Node *next;//Con trỏ trỏ tới nút tiếp theo
} Node;
//Cấu trúc của stack
typedef struct Stack
{
    Node *top;//con trỏ trỏ tới nút trên cùng của Stack
} Stack;

void initStack(Stack *s)
{
    s->top = NULL;// Ban đầu Stack rỗng, top trỏ tới NULL
}

bool isEmpty(const Stack *s)
{
    return s->top == NULL;
}

void push(Stack *s, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
    }
    newNode->data = value; //gán giá trị vào nút mới
    newNode->next = s->top; //Nút mới trỏ tới nút hiện tại trên cùng của Stack
    s->top = newNode; //Đặt nút mới là nút trên cùng của Stack
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
    }
    Node *temp = s->top;
    int popValue = temp->data;
    s->top = s->top->next;
    free(temp);
    return popValue;
}

int peek(const Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
    }
    return s->top->data;
}

void freeStack(Stack *s)
{
    while (!isEmpty(s))
    {
        pop(s);
    }
}
