#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Stack
{
    int *data;
    int top;
    int capacity;
} Stack;

void initStack(Stack *s, int initialCapacity);
bool isEmpty(const Stack *s);
bool isFull(const Stack *s);
void resizeStack(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);

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

void resizeStack(Stack *s)
{
    s->capacity *= 2;
    s->data = (int *)realloc(s->data, s->capacity * sizeof(int));
    if (s->data == NULL)
    {
        printf("Memory Alocation failed during resize\n");
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
        printf("Stack underflow\n");
    }
    int temp = s->data[s->top];
    s->top = s->top - 1;
    return temp;
}

int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
    }
    return s->data[s->top];
}

void freeStack(Stack *s)
{
    free(s->data);
    s->capacity = 0;
    s->top = -1;
}

char* mhc(char *str)
{
    Stack s;
    int n = strlen(str);
    initStack(&s,n);
    char *mh = (char *)malloc((2*n + 1) * sizeof(char));
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        if (isEmpty(&s) || str[i] == peek(&s))
        {
            push(&s,str[i]);
        }else
        {
            char currentChar = pop(&s);
            int count = 1;
            while (!isEmpty(&s) && peek(&s) == currentChar)
            {
                pop(&s);
                count++;
            }
            mh[index] = currentChar;
            index++;
            mh[index] = count + '0';
            index++;
            push(&s,str[i]);
        } 
    }

    while (!isEmpty(&s)) {
        char currentChar = pop(&s);
        int count = 1;
        while (!isEmpty(&s) && peek(&s) == currentChar) {
            pop(&s);
            count++;
        }
        mh[index++] = currentChar;
        mh[index++] = count + '0';
    }
    
    mh[index] = '\0';
    free(s.data);
    return mh;
}

int main()
{
    char str[] = {"aaabbbcccd"};
    printf("Original String: %s\n",str);
    char* mh1 = mhc(str);
    printf("Final String: %s\n",mh1);
    return 0;
}