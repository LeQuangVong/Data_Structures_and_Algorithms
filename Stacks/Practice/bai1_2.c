/*
    Cho một string,in chuỗi đảo ngược của string đó ra màn hình bằng cách dùng stack.
    Input	
    codelearn
    Output
    nraeledoc
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct Stack
{
    int *data;//trỏ đến mảng giá trị của stack
    int top;
    int capacity;//Dung lượng hiện tại của Stack
} Stack;

void initStack(Stack *s, int initialCapacity);
bool isEmpty(const Stack *s);
bool isFull(const Stack *s);
void resizeStack(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
void reverseStack(char *Str);

void initStack(Stack *s, int initialCapacity)
{
    s->data = (int *)malloc(initialCapacity * sizeof(int));
    if (s->data == NULL)
    {
        printf("Memory allocation failed\n");
    }
    s->capacity = initialCapacity;
    s->top = -1;
}

bool isEmpty(const Stack *s)
{
    return s->top == -1;
}
bool isFull(const Stack *s)
{
    return s->top == s->top - 1;
}
void resizeStack(Stack *s)
{
    s->capacity *= 2;
    s->data = (int *)realloc(s->data, s->capacity * sizeof(int));
    if (s->data == NULL)
    {
        printf("Memory allocation failed during resize\n");
    }
}
void push(Stack *s, int value)
{
    if (isFull(s))
    {
        resizeStack(s);
    }
    s->top = s->top + 1;
    s->data[s->top] = value;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow!\n");
    }
    int temp = s->data[s->top];
    s->top = s->top - 1;
    return temp;
}

int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow!\n");
    }
    return s->data[s->top];
}

void freeStack(Stack *s)
{
    free(s->data);
    s->capacity = 0;
    s->top = -1;
}

void reverseStack(char *Str)
{
    Stack s;
    int n = strlen(Str);
    initStack(&s,n);
    for (int i = 0; i < n; i++)
    {
        push(&s,Str[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        Str[i] = pop(&s);
    }
    
    printf("Reverse Stack: %s\n",Str);
}
int main()
{   
    char str[] = {"Hello World"};
    printf("Original String: %s\n",str);
    reverseStack(str);
}