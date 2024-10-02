#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node *head = NULL;

Node* createNode(int data);
void insertFirst(int data);
void insertLast(int data);
bool isEmpty();
int length();
void printList();
Node* deleteFirst();
int deleteLast();
int deleteNode(int data);
int find(int data);
void freeList();

int main()
{
    insertFirst(10);
    insertFirst(40);
    insertFirst(30);
    insertFirst(70);
    insertFirst(5);

    printf("list: ");
    printList();

    printf("- Xoa node dau tien\n");
    Node* firstNode = deleteFirst();
    if (firstNode != NULL)
    {
        printf("Node vua xoa la %d\n",firstNode->data);
    }
    printf("Danh sach Node sau khi xoa Node dau tien la:\n");
    printList();

    printf("- Xoa Node voi data\n");
    int dataNode = deleteNode(30);
    if (dataNode != 0)
    {
        printf("Node da duoc xoa!\n");
    }else
    {
        printf("Danh sach rong!\n");
    }
    
    printf("Danh sach sau khi xoa Node la:\n");
    printList();

    printf("- Tim Node voi data\n");
    int findNode = find(40);
    if (findNode != 0)
    {
        printf("Da tim thay Node!\n");
    }
    else
    {
        printf("Khong tim thay Node!\n");
    }
    
    printf("- Them Node vao cuoi list\n:");
    insertLast(20);
    printf("Danh sach sau khi them Node:\n");
    printList();

    printf("- Xoa Node cuoi list:\n");
    int lastNode = deleteLast();
    if (lastNode != 0)
    {
        printf("Da xoa xong!\n");
    }
    else
    {
        printf("List trong!\n");
    }
    printf("Danh sach sau khi xoa Node cuoi:\n");
    printList();    

    freeList();
    printf("list: \n");
    printList();

    insertLast(20);
    insertLast(30);
    insertFirst(10);
    printf("list: \n");
    printList();
    return 0;
}

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

void insertLast(int data)
{
    Node* link = createNode(data);
    Node* current = head;
    if (head == NULL)
    {
        head = link;
        return;
    }
    
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = link;
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
int find(int data)
{
    Node* current = head;

    if (head == NULL)
    {
        return 0;
    }
    
    while (current->data != data)
    {
        if (current->next == NULL)
        {
            return 0;
        }
        else
        {
            current = current->next;        
        }
    }
    return 1;
}
//delete the first node and return node.
Node* deleteFirst()
{
    Node* temp = head;
    head = head->next;
    return temp;
}

int deleteLast()
{
    Node* current = head;
    Node* previous = NULL;
    if (head == NULL)
    {
        return 0;
    }
    
    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }

    previous->next = NULL;
    free(current);
    return 1;
}
//delete the node with data
int deleteNode(int data)
{
    Node* current = head;
    Node* previous = NULL;

    if (current == NULL)
    {
        return 0;
    }
    
    while (current->data != data)
    {
        if (current->next == NULL)
        {
            return 0;
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
    free(current);
    return 1;
}

void freeList()
{
    Node* current = head;
    Node* nextNode = NULL;

    if (head == NULL)
    {
        return;
    }
    
    while (current->next != NULL)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    head = NULL;
}
