#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    int data;
    struct Node* left;//node bên trái của cây <=> cây con trái
    struct Node* right;//ndoe bên phải của cây <=> cây con phải
}Node;

void insertNode(Node** root, int data);
void printNodeLeftRight(Node* root);
bool searchNode(Node* root, int data);
void deleteNode(Node** root, int data);
void freeTree(Node* root);

int main()
{
    Node* root = NULL;
    insertNode(&root,10);
    insertNode(&root,5);
    insertNode(&root,30);
    insertNode(&root,20);
    insertNode(&root,15);
    insertNode(&root,25);
    insertNode(&root,40);
    insertNode(&root,35);
    insertNode(&root,45);
    printNodeLeftRight(root);
    printf("\n");
    deleteNode(&root,20);
    printNodeLeftRight(root);
    printf("\n");
    if (searchNode(root,40) == true)
    {
        printf("Da tim thay !\n");
    }
    else
    {
        printf("khong tim thay Node\n!");
    }

    freeTree(root);
    return 0;
}
void freeTree(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    
    freeTree(root->left);
    freeTree(root->right);

    printf("Dang giai phong Node co gia tri: %d \n", root->data);
    free(root);
}

void deleteNode(Node** root, int data)
{
    if (*root == NULL)
    {
        return;
    }

    if ((*root)->data > data)
    {
        deleteNode(&((*root)->left),data);
    }
    else if ((*root)->data < data)    
    {
        deleteNode(&((*root)->right),data);
    }
    else
    {
        Node* Temp = *root;
        if ((*root)->right == NULL)
        {
            *root = (*root)->left;
        }
        else if ((*root)->left == NULL)
        {
            *root = (*root)->right;
        }
        else
        {
            Node* min = (*root)->right;
            while (min->left != NULL)
            {
                min = min->left;
            }
            (*root)->data = min->data;
            deleteNode(&((*root)->right),min->data);
            Temp = NULL;
        }
        
        if (Temp != NULL)
        {
            free(Temp); // Giải phóng bộ nhớ của node đã xóa
        }
    }
}

bool searchNode(Node* root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    
    if (root->data == data)
    {
        return true;
    }
    
    if (root->data > data)
    {
        searchNode(root->left,data);
    }
    else if (root->data < data)
    {
        searchNode(root->right,data);
    } 
}

void printNodeLeftRight(Node* root)
{
    if (root != NULL)
    {
        printNodeLeftRight(root->left);
        printf("%d ",root->data);
        printNodeLeftRight(root->right);
    }
}

void insertNode(Node** root, int data)
{
    if (*root == NULL)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        *root = newNode;
    }
    else
    {
        if((*root)->data > data)
        {
            insertNode(&((*root)->left),data);
        }
        else if ((*root)->data < data)
        {
            insertNode(&((*root)->right),data);
        }
    }
}