#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 100

void initStack(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
bool isEmpty(const Stack *s);
bool isFull(const Stack *s);

typedef struct Stack
{
    int data[MAX_SIZE];
    int top;
};

//khoi tao Stack
void initStack(Stack *s)
{
    s->top = -1;
}

//Đẩy một phần tử vào Stack
void push(Stack *s, int value)
{
    /*
        Nếu Stack đầy sẽ thông báo 
    */
    if (isFull(s))
    {
        printf("Stack overflow\n");
    }
    /*
        - Tăng giá trị top lên 1 đơn vị để nó trỏ tới vị trí mới trong stack
        - Sau khi top tăng lên giá trị value được lưu ở vị trí s->top trong stack
    */
    s->top = s->top + 1;
    s->data[s->top] = value;
}

//lấy phần tử trên cùng của stack ra ngoài
int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack empty");
    }
    /*
        - lấy phần tử trên cùng của stack
        - giảm top xuống 1 đơn vị để top trỏ tới phần tử tiếp theo
    */
    int t = s->data[s->top];
    s->top - 1;
    return t;
}
//Xem phần tử trên cùng của stack
int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack empty");
    }
    /*
        - lấy phần tử trên cùng của stack mà không loại top khỏi stack
    */
    return s->data[s->top];;
}
//kiểm tra xem stack có rỗng không
bool isEmpty(const Stack *s)
{
    return s->top == -1;
}
//kiểm tra xem stack có đầy không
bool isFull(const Stack *s)
{
    return s-> MAX_SIZE - 1;
}

