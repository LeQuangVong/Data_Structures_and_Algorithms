/*
    Nhập vào số nguyên dương n, tiếp theo là n số nguyên của dãy số a.
    Hãy sắp xếp dãy số a thành dãy không giảm (số sau không bé hơn số trước) 
    và in dãy đó ra màn hình, sau mỗi phần tử có đúng một khoảng trắng

    Input	
    6
    1 3 2 5 2 -2
    Output
    -2 1 2 2 3 5

    Với a = [1, 3, 2, 5, 2] thì kết quả mong muốn là:
    "1 2 2 3 5 ".
*/

#include<stdio.h>

void Insertion_Sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && a[j] < a[j - 1])
        {
            int temp = a[j - 1];
            a[j - 1] = a[j];
            a[j] = temp;
            j--;
        }
    }
}

int main()
{
    int a[] = {1,3,2,5,2,-2};
    int n = sizeof(a)/sizeof(int);
    Insertion_Sort(a,n);
    for (int i = 0; i < n; i++)
    {
        printf("%i ",a[i]);
    }
}