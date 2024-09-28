/*
    Nhập vào số nguyên dương n, tiếp theo là n số nguyên của dãy số a.
    Hãy sắp xếp dãy số a thành dãy không giảm (số sau không bé hơn số trước)
    và in dãy đó ra màn hình, sau mỗi phần tử có đúng một khoảng trắng.

    Input	
    5
    1 3 2 5 2
    Output
    1 2 2 3 5

    Với a = [1, 3, 2, 5, 2] thì kết quả mong muốn là:
    "1 2 2 3 5 ".
*/

#include<stdio.h>
#include<stdbool.h>

void Bubble_Sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = true;
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j+1])      
            {
                int temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
                flag = false;
            }
        }
        if (flag == true)
        {
            break;
        }
    }
}

int main()
{
    int a[] = {1,3,2,5,2};
    int n = sizeof(a)/sizeof(int);
    Bubble_Sort(a,n);
    for (int i = 0; i < n; i++)
    {
        printf("%i ",a[i]);
    }
    return 0;
}