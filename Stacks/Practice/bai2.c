/*
    Nhập vào một số nguyên dương n.
    Hãy chuyển n thành mã nhị phân và in chuỗi đó ra màn hình.
    Input	
    13
    OutPut
    1101
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct Node
{
    int data;//dữ liệu của node
    struct Node *next;//trỏ đến node tiếp theo
} Node;
typedef struct Stack
{
    struct Node *top;
} Stack;

void initStack(Stack *s);
bool isEmpty(const Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
void freeStack(Stack *s);
void convertToBinary(int number);

void initStack(Stack *s)
{
    s->top = NULL;
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
    newNode->data = value;//gán giá trị vào node
    newNode->next = s->top;//nút mới trỏ đến nút hiện tại trên cùng của Stack
    s->top = newNode;//đặt nút mới là nút trên cùng của Stack
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

int peek(Stack *s)
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

void convertToBinary(int number)
{
    Stack s;
    initStack(&s);
    while (number > 0)
    {
        int du = number % 2;
        push(&s,du);
        number /= 2;
    }

    while (!isEmpty(&s))
    {
        printf("%d",pop(&s));
    }
}

int main()
{
    int number = 7;
    convertToBinary(number);
}
