#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* head = NULL;

Node* createNode(int data);
void insertFirst(int data);
void insertLast(int data);
bool deleteFirst();
bool deleteNode(int data);
bool deleteLast();
void printList();
void freeList();

int main()
{
    insertFirst(10);
    insertFirst(20);
    insertFirst(30);
    insertLast(40);
    printList();
    if (deleteFirst())      
    {
        printf("Da xoa node dau tien!\n");
    }
    else
    {
        printf("danh sach trong!\n");
    }
    printList();

    if (deleteNode(10))      
    {
        printf("Da xoa node 10!\n");
    }
    else
    {
        printf("danh sach trong!\n");
    }
    printList();

    if (deleteLast())      
    {
        printf("Da xoa node cuoi cung!\n");
    }
    else
    {
        printf("danh sach trong!\n");
    }
    printList();

    freeList();
    printList();
    return 0;
}
bool deleteLast()
{
    Node* current = head;
    Node* prev = NULL;

    if (head == NULL)
    {
        return false;
    }
    
    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    
    prev->next = NULL;
    free(current);
    return true;
}

bool deleteNode(int data)
{
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;

    if (head == NULL)
    {
        return false;
    }
    
    while (current->data != data)
    {
        prev = current;
        current = current->next;
        next = current->next;
    }
    prev->next = current->next;
    next->prev = prev;
    free(current);
    return true;
}

bool deleteFirst()
{
    Node* current = head;
    if (head == NULL)
    {
        return false;
    }
    
    head = head->next;
    free(current);
    return true;
}
void freeList()
{
    Node* current = head;
    Node* next = NULL;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

void insertLast(int data)
{
    Node* link = createNode(data);
    Node* current = head;

    if (head == NULL)
    {
        head = link;
    }
    
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = link;
    link->prev = current;
}

void printList()
{
    Node* current = head;
    while (current != NULL)
    {
        printf("%d <-> ",current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void insertFirst(int data)
{
    Node* link = createNode(data);
    if (head == NULL)   
    {
        head = link;
    }
    else
    {
        link->next = head;
        head->prev = link;
        head = link;
    }
}

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
