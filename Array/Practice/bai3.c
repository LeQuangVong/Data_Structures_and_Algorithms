/*
    Viết hàm đếm số lượng số nguyên tố nhỏ hơn 100 trong mảng
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX 100

void nhap(int a[], int *n);
bool kiemTraSoNguyenTo(int n);
int demSoNguyenTo(int a[], int n);
void xuat(int a[], int n);

void nhap(int a[], int *n)
{
    do
    {
        printf("Nhap so luong phan tu trong mang: ");
        scanf("%d",n);

        if (*n <= 0 || *n > MAX)
        {
            printf("So luong phan tu khong hop le. Vui long nhap lai");
        }
        
    } while (*n <= 0 || *n > MAX);
    
    for (int i = 0; i < *n; i++)
    {
        printf("\na[%d]= ",i);
        scanf("%d",&a[i]);
    }
}

bool kiemTraSoNguyenTo(int n)
{
    if (n < 2)
    {
        return false;
    }
    else if (n > 2)
    {
        if (n % 2 == 0)
        {
            return false;
        }
        
        for (int i = 3; i <= sqrt((float)n); i += 2)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int demSoNguyenTo(int a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if ((kiemTraSoNguyenTo(a[i]) == true) && a[i] < 100)
        {
            dem++;
        }
    }
    return dem;
}

void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%8.3d", a[i]);
    }
}

int main()
{
    int n;
    int a[MAX];

    nhap(a,&n);
    xuat(a,n);
    int snt = demSoNguyenTo(a,n);
    printf("\nSo luong so nguyen to la %d", snt);
    return 0;
}