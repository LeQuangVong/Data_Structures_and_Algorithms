#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node
{
    int data;//Dữ liệu của nút
    struct Node *next;//trỏ đến nút tiếp theo
} Node;

typedef struct Stack
{
    struct Node *top;//trỏ đến nút trên cùng của Stack
} Stack;

void initStack(Stack *s);
bool isEmpty(const Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
void freeStack(Stack *s);

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
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
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
        printf("Stack Underflow\n");
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

void reverseStack(char *Str)
{
    Stack s;
    initStack(&s);
    int n = strlen(Str);
    for (int i = 0; i < n; i++)
    {
        push(&s,Str[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        Str[i] = pop(&s);
    }
    
    printf("Reverse String: %s\n",Str);
}
int main()
{
    char str[] = {"Hello Word"};
    printf("Original string: %s\n",str);
    reverseStack(str);
}