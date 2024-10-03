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
bool deleteFirst();
bool deleteNode(int key);
bool deleteLast();
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
    insertLast(5,40);
    printList();
    if (find(7))
    {
        printf("Node ton tai!\n");
    }
    else
    {
        printf("Node khong ton tai!\n");
    }

    if (deleteFirst())//==true
    {
        printf("Da xoa Node dau tien!\n");
    }
    else
    {
        printf("Danh sach trong!\n");
    }
    printList();

    if (deleteNode(6))//==true
    {
        printf("Da xoa Node co key = 6!\n");
    }
    else
    {
        printf("Danh sach trong!\n");
    }
    printList();

    if (deleteLast())//==true
    {
        printf("Da xoa Node cuoi cung!\n");
    }
    else
    {
        printf("Danh sach trong!\n");
    }
    printList();

    freeList();
    printList();
    return 0;
}
bool deleteLast()
{
    Node* current = head;
    Node* nextNode = NULL;

    if (head == NULL)
    {
        return false;
    }
    
    while (current->next != NULL)
    {
        nextNode = current;
        current = current->next;
    }
    
    if (current == head)
    {
        return false;
    }
    
    nextNode->next = NULL;
    free(current);
    return true;
}

bool deleteNode(int key)
{
    Node* current = head;
    Node* nextNode = NULL;
    if (head == NULL)
    {
        return false;
    }
    
    while (current->key != key)
    {
        if (current->next == NULL)
        {
            return false;
        }
        nextNode = current;
        current = current->next;
    }

    if (current == head)
    {
        head = head->next;
    }
    
    nextNode->next = current->next;
    free(current);
    return true;
}

bool deleteFirst()
{
    Node* temp = head;
    if (head == NULL)       
    {
        return false;
    }
    head = head->next;
    free(temp);
    return true;
}
void freeList()
{
    Node* current = head;
    Node* next = NULL;
    if (head == NULL)
    {
        return;
    }
    
    while (current!= NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;// đặt con trỏ head bằng NULL vì sau khi giải phóng xong, không đặt head về NULL 
                //khi chúng ta thực hiện thao tác in danh sách thì sẽ truy cập vùng nhớ đã giải phóng
                //gây ra hiển thị các giá trị rác(rất nguy hiểm).
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
    printf("NULL\n");
}

void insertLast(int key, int data)
{
    Node* link = createNode(key,data);
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
}

bool find(int key)
{
    Node* current = head;
    
    if (head == NULL)
    {
        return false;
    }
    
    while (current->next != NULL)   
    {
        if (current->key == key)
        {
            return true;
        }
        else
        {
            current = current->next;
        }
    }
    return false;
}