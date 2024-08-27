/*
    Nhập vào một số nguyên dương n, và n số nguyên lần lượt là các phần tử trong dãy a.
    Hãy thay đổi giá trị của mỗi phần tử thành bình phương của chính nó, sau đó in mảng đó ra màn hình (mỗi phần tử cách nhau bởi một khoảng trắng).
    Input	
    4
    1 3 5 -3
    Output
    1 9 25 9 
*/

#include <stdio.h>
#include <math.h>
#define MAX 100

void nhap(int a[], int *n);
void xuat(int a[], int n);
void binhphuong(int a[], int n);

void nhap(int a[], int *n)
{
    do
    {
        printf("Nhap so luong phan tu = ");
        scanf("%d",n);
        if (*n < 0 || *n >= MAX)
        {
            printf("So phan tu khong hop le. Vui long nhap lai!");
        }
        
    } while (*n < 0 || *n >= MAX);
    
    for (int i = 0; i < *n; i++)
    {
        printf("\na[%d] = ",i);
        scanf("%d",&a[i]);
    }
}

void binhphuong(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i]*a[i];
    }
}

void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
}

int main()
{
    int a[MAX];
    int n;
    nhap(a,&n);
    xuat(a,n);
    binhphuong(a,n);
    xuat(a,n);
}