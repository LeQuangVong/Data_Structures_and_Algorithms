/*
    Nhập vào một số nguyên dương n, tiếp theo là n số nguyên lần lượt là các phần tử trong dãy a.
    Hãy hoán đổi phần tử nhỏ nhất đầu tiên và phần tử lớn nhất cuối cùng trong dãy đó. 
    In dãy sau khi hoán đổi ra màn hình, phía sau mỗi phần tử có đúng một khoảng trắng.

    Input	
    5
    1 2 3 4 5
    Output
    5 2 3 4 1
    Với a = [1, 2, 3, 4, 5] thì kết quả mong muốn là:
    "5 2 3 4 1 ".
*/

#include<stdio.h>
int searchMin(int a[],int n)
{
    int k = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[k] > a[i])
        {
            k = i;
        }
    }
    return k;
}

int searchMax(int a[],int n)
{
    int k = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[k] < a[i])
        {
            k = i;
        }
    }
    return k;
}

void swap(int a[], int m, int max)
{
    int temp = a[m];
    a[m] = a[max];
    a[max] = temp;
}

int main()
{
    int a[] = {1,2,3,4,5};
    int n = sizeof(a)/sizeof(int);
    int m  = searchMin(a,n);
    int max = searchMax(a,n);
    swap(a,m,max);
    for (int i = 0; i < n; i++)
    {
        printf("%i ",a[i]);
    }
    return 0;
}