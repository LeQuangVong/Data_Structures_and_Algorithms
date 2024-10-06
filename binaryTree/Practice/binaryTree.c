#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;//node bên trái của cây <=> cây con trái
    struct Node* right;//ndoe bên phải của cây <=> cây con phải
}Node;

Node* createNode(int data);
Node* insertNode(Node* root, int data);
void printNodeLeftRight(Node* root);
Node* searchNode(Node* root, int data);

int main()
{
    Node* root = NULL;
    root = insertNode(root,10);
    insertNode(root,20);
    insertNode(root,30);
    insertNode(root,40);
    printNodeLeftRight(root);
    Node* value = searchNode(root,50);
    if (value != NULL)
    {
        printf("\nDa tim thay Node co gia tri %d !\n",value->data);
    }
    else
    {
        printf("\nNode khong ton tai !");
    }
    return 0;
}

Node* searchNode(Node* root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    
    if (root->data > data)
    {
        return searchNode(root->left,data);
    }
    
    return searchNode(root->right,data);
}

void printNodeLeftRight(Node* root)
{
    if (root != NULL)
    {
        printf("%d ",root->data);
        printNodeLeftRight(root->left);
        printNodeLeftRight(root->right);
    }
}

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory error!");
        return NULL;
    }
    
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        return root;//trả nút vừa tạo
    }

    if (root->data > data)
    {
        root->left = insertNode(root->left,data);
        //nút mới được tạo được trả về từ hàm insertNode được gán cho root->left
    }
    else if (root->data < data)
    {
        root->right = insertNode(root->right,data);
    }
    return root;//trả về con trỏ gốc của cây sau khi chèn xong.
                //để duy trì liên kết trong cây
                //nếu không có thì sau khi 1 nút mới được chèn vào thì sẽ không có liên kết
                //từ nút cha đến nút con mà nút cha vẫn bằng NULL
}