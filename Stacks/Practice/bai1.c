/*
    Cho một string,in chuỗi đảo ngược của string đó ra màn hình bằng cách dùng stack.
    Input	
    codelearn
    Output
    nraeledoc
*/

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAX_SIZE 100

typedef struct Stack
{
    int data[MAX_SIZE];//mảng chứa giá trị của stack
    int top;//phần tử top của stack
}Stack;

void initStack(Stack *s);
bool isEmpty(const Stack *s);
bool isFull(const Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
void reverseString(char *Str);

//Khởi tạo Stack
void initStack(Stack *s)
{
    s->top = -1;
}
//kiểm tra Stack rỗng không
bool isEmpty(const Stack *s)
{
    return s->top == -1;
}
//Kiểm tra Stack có đầy không
bool isFull(const Stack *s)
{
    return s->top == s->top - 1;
}
//Đẩy 1 phần tử vào Stack
void push(Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack overflow!\n");
    }
    s->top = s->top + 1;
    s->data[s->top] = value;
}
//Lấy phần tử đầu ra khỏi Stack
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
//Xem phần tử đầu của Stack
int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow!\n");
    }
    return s->data[s->top];
}

void reverseString(char *Str)
{
    Stack s;
    initStack(&s);
    int n = strlen(Str);
    for (int i = 0; i < n; i++)
    {
        push(&s,Str[i]);
    }
    //Lấy các ký tự ra khỏi Stack và ghi đè lên chuỗi ban đầu
    for (int i = 0; i < n; i++)
    {
        Str[i] = pop(&s);
    }
    printf("Reverse String: %s\n",Str);
}
int main()
{
    char str[] = {"Hello World"};
    printf("Original String: %s\n",str);
    reverseString(str);
}
