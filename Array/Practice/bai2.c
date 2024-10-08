/*
Viết hàm tìm giá trị lớn nhất trong mảng 1 chiều các số thực
*/

#include <stdio.h>
#include <math.h>
#define MAX 100

void nhap(float a[], int *n)
{
    do
    {
        printf("\nNhap so phan tu: ");
        scanf("%d", n);
        if (*n <= 0 || *n > MAX)
        {
            printf("\nSo phan tu khong hop le. Xin kiem tra lai !");
        }
    } while (*n <= 0 || *n > MAX);
    
    for (int i = 0; i < *n; i++)
    {
        printf("\nNhap a[%d]: ",i);
        scanf("%f", &a[i]);
    }
}

float lonNhat(float a[], int n)
{
    float ln = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > ln)
        {
            ln = a[i];
        }
    }
    return ln;
}

void xuat(float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%8.3f", a[i]);
    }
}

int main()
{
    int n;
    float a[MAX];
    nhap(a, &n);
    xuat(a, n);

    float ln = lonNhat(a, n);

    printf("\nPhan tu lon nhat trong mang là %.3f\n", ln);

    //getch();
    return 0;
}