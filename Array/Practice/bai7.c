/*
    Nhập vào một số nguyên dương n, và n số nguyên lần lượt là các phần tử trong dãy a. Hãy in lần lượt các số nguyên tố có trong dãy a ra màn hình, sau mỗi phần tử có đúng một khoảng trắng.
    (Số nguyên tố là số nguyên dương có đúng 2 ước là 1 và chính nó. Số a được gọi là ước của b nếu b chia hết cho a). Biết rằng dãy sẽ có ít nhất một số nguyên tố.
    Input	
    4
    1 2 3 4
    Output
    2 3 
*/
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define MAX 100

void nhap(int a[], int *n);
bool kiemTraSoNguyenTo(int k);
void xuatSoNguyenTo(int a[], int n);
void xuat(int a[], int n);

void nhap(int a[], int *n)
{
    do
    {
        printf("Nhap so phan tu = ");
        scanf("%d",n);
        if (*n < 0 || *n > MAX)
        {
            printf("So luong phan tu khong hop le");
        }
    } while (*n < 0 || *n > MAX);
    
    for (int i = 0; i < *n; i++)
    {
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
    }
}

bool kiemTraSoNguyenTo(int k)
{
    if (k < 2)
    {
        return false;
    }
    
    if (k == 2)
    {
        return true;
    }
    
    if (k % 2 == 0)
    {
        return false;
    }
    
    for (int i = 3; i <= sqrt(k); i += 2)
    {
        if (k % i == 0)
        {
            return false;
        }
    }
    return true;
}

void xuatSoNguyenTo(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (kiemTraSoNguyenTo(a[i]))
        {
            printf("%d ",a[i]);
        }
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
    xuatSoNguyenTo(a,n);
    return 0;
}