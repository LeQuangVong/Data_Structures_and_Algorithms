/*
    Viết hàm tìm vị trí của giá trị lớn nhất trong mảng 1 chiều các số nguyên
*/
#include <stdio.h>
#include <math.h>
#define MAX 100
void nhap(int a[], int *n);
int vtln(int a[], int n);
void xuat(int a[], int n);

void nhap(int a[], int *n)
{
    do
    {
        printf("Nhap so phan tu cua mang: ");
        scanf("%d",n);
        if (*n <= 0 || *n > MAX)
        {
            printf("\nSo phan tu khong hop le. Xin kiem tra lai !");
        }
    } while (*n <= 0 || *n > MAX);

    for (int i = 0; i < *n; i++)
    {
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
    }
}

int vtln(int a[], int n)
{
    int vtln = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[vtln])
        {
            vtln = i;
        }
    }
    return vtln;
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
    int vt = vtln(a,n);
    printf("\nVi tri cua phan tu lon nhat la %d\n", vt);
    return 0;
}