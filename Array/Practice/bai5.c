/*
    Nhập vào một số nguyên dương n, và n số nguyên lần lượt là các phần tử trong dãy a. Tiếp theo nhập vào hai số nguyên là k và x (0 ≤ k ≤ n).
    Hãy chèn phần tử có giá trị x vào dãy a, ở trước phần tử có chỉ số k và sau phần tử có chỉ số k-1. In mảng kết quả ra màn hình, mỗi số cách nhau bởi một khoảng trắng.
    Input	
    4
    1 2 3 4
    1 10
    Output
    1 10 2 3 4 
*/
#include <stdio.h>
#include<math.h>
#define MAX 100

void nhap(int a[], int *n);
void xuat(int a[], int n);
void chen(int a[], int n, int k, int x);

void nhap(int a[], int *n)
{
    do
    {
        printf("Nhap so luong phan tu trong mang = ");
        scanf("%d",n);
        if (*n < 0 || *n > MAX)
        {
            printf("So luong phan tu khong hop le. Vui long nhap lai");
        }
    } while (*n < 0 || *n > MAX);

    for (int i = 0; i < *n; i++)
    {
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
    }
}

void chen(int a[], int n, int k, int x)
{
    for (int i = n; i > k; i--)
    {
        a[i] = a[i-1];
    }
    a[k] = x;

    for (int i = 0; i <= n; i++)
    {
        printf("%d ",a[i]);
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
    int n,x,k;
    nhap(a,&n);
    xuat(a,n);
    printf("\nNhap gia tri can chen = ");
    scanf("%d",&x);
    printf("Nhap vi tri can chen = ");
    scanf("%d",&k);
    chen(a,n,k,x);
    return 0;
}