#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    int data;
    int key;
    struct Node* next;
}Node;

Node* head = NULL;

Node* createNode(int key, int data);
void insertfirst(int key, int data);
void insertPrevNode(int keyPrev, int key, int data);
void insertNextNode(int keyPrev, int key, int data);
void insertLast(int key, int data);
void printList();
bool find(int key);
bool find(int data);
int deleteFirst();
int deleteNode(int key);
int deleteLast();
void freeList();

int main()
{
    insertfirst(1,10);
    insertfirst(2,20);
    insertfirst(3,20);
    insertfirst(4,20);
    printList();
    insertNextNode(3,5,30);
    printList();
    insertPrevNode(3,6,50);
    printList();
    return 0;
}

Node* createNode(int key, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->key = key;
    newNode->next = NULL;

    return newNode;
}

void insertfirst(int key, int data)
{
    Node* link = createNode(key,data);
    link->next = head;
    head = link;
}

void insertPrevNode(int keyPrev, int key, int data)
{
    Node* link = createNode(key,data);
    Node* current = head;
    Node* next = NULL;

    if (head == NULL)
    {
        return;
    }
    
    while (current->key != keyPrev)
    {
        current = current->next;
    }
    next = current->next;
    current->next = link;
    link->next = next;
}

void insertNextNode(int keyNext, int key, int data)
{
    Node* link = createNode(key,data);
    Node* current = head;
    Node* previous = NULL;

    if (head == NULL)
    {
        return;
    }
    
    while (current->key != keyNext)
    {
        previous = current;
        current = current->next;
    }
    previous->next = link;
    link->next = current;
}

void printList()
{
    Node* current = head;

    while (current != NULL)
    {
        printf("[%d, %d] -> ",current->key,current->data);
        current = current->next;
    }
    printf("NULL;\n");
}

