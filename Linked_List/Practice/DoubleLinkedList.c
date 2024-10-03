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
    freeList();
    printList();
    return 0;
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
