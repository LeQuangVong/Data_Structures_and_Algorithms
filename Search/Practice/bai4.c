/*
    Nhập vào một số nguyên dương n, tiếp theo nhập n số nguyên lần lượt là các phần tử của dãy a.
    Hãy in ra những phần tử lẻ ở chỉ số chẵn, sau mỗi phần tử có đúng một dấu cách,
    nếu không có phần tử nào thõa mãn thì in ra "NULL".
    Input	
    5
    1 3 4 5 7
    Output
    1 7
    Với a = [1, 3, 4, 5, 7] thì kết quả mong muốn là "1 7 ".
*/

#include<stdio.h>
#include<stdbool.h>

void leOChan(int a[], int n)
{
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] % 2 != 0) && (i % 2 == 0))
        {
            printf("%i ",a[i]);
            flag = false;
        }
    }
    if (flag == true)
    {
        printf("NULL\n");
    }
}

int main()
{
    int a[] = {1,3,5,7,9};
    int n = sizeof(a)/sizeof(int);
    leOChan(a,n);
    return 0;
}