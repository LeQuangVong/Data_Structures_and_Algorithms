#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node *head = NULL;

//Create Node

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

//Insert First
void insertFirst(int data)
{
    Node* link = createNode(data);
    link->next = head;
    head = link;
}

//Check empty
bool isEmpty()
{
    return head == NULL;
}

//number of node
int length()
{
    int length = 0;
    Node* current = head;

    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    
    return length;
}
//printlist
void printList()
{
    Node* current = head;

    while (current != NULL)
    {
        printf("%d -> ",current->data);
        current = current->next;
    }
    printf("NULL\n");
}
//find Node with data
Node* find(int data)
{
    Node* current = head;

    if (head == NULL)
    {
        return NULL;
    }
    
    while (current->data != data)
    {
        if (current->next == NULL)
        {
            return NULL;
        }
        else
        {
            current = current->next;        
        }
    }
    return current;
}
//delete the first node and return node.
Node* deleteFirst()
{
    Node* temp = head;
    head = head->next;
    return temp;
}
//delete the node with data
Node* deleteNode(int data)
{
    Node* current = head;
    Node* previous = NULL;

    if (current->next == NULL)
    {
        return NULL;
    }
    
    while (current->data != data)
    {
        if (current->next == NULL)
        {
            return NULL;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
    
    if (current == head)
    {
        head = head->next;
    }
    else
    {
        previous->next = current->next;
    }
    return current;
}

int main()
{
    insertFirst(10);
    insertFirst(40);
    insertFirst(30);
    insertFirst(70);
    insertFirst(5);

    printf("list: ");
    printList();
    return 0;
}