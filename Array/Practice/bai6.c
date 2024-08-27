/*
    Nhập vào một số nguyên dương n, và n số nguyên lần lượt là các phần tử trong dãy a. Tiếp theo nhập vào số nguyên là k (0 ≤ k < n).
    Hãy xóa phần tử có chỉ số k ở trong dãy đó. In mảng kết quả ra màn hình, sau mỗi phần tử có đúng một khoảng trắng.
    Input	
    4
    1 2 3 4
    1
    Output
    1 3 4
*/
#include<stdio.h>
#include<math.h>
#define MAX 100

void nhap(int a[], int *n);
void xuat(int a[], int n);
void xoa(int a[], int n, int k);

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

void xoa(int a[], int n, int k)
{
    for (int i = k; i < n; i++)
    {
        a[i] = a[i+1];
    }
    for (int i = 0; i < (n - 1); i++)
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
    int n,k;
    nhap(a,&n);
    xuat(a,n);
    printf("\nNhap vi tri muon xoa = ");
    scanf("%d",&k);
    xoa(a,n,k);
    return 0;
}
