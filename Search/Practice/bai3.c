/*
    Nhập và số nguyên dương n, tiếp theo là n số nguyên lần lượt là các phần tử trong dãy a, cuối cùng là nhập số nguyên x,
    hãy đếm xem trong dãy a có bao nhiêu phần tử có giá trị bằng x. In ra số đó.
    Input
    6
    1 2 1 2 2 3
    2
    Output
    3
    Với a = [1, 2, 1, 2, 2, 3] và x = 2 thì kết quả là 3.
*/

#include<stdio.h>
int soLanXuatHien(int a[], int n, int x)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (x == a[i])
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int a[] = {1,2,2,3,3,5};
    int x;
    int n = sizeof(a)/sizeof(int);
    printf("x = ");
    scanf("%i",&x);
    printf("So lan xuat hien cua %i la %i\n",x,soLanXuatHien(a,n,x));
    return 0;
}