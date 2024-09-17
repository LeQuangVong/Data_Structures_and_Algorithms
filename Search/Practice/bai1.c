/*
    Nhập vào một số nguyên dương n, tiếp theo là n số nguyên lần lượt là các phần tử trong dãy a,
    cuối cùng nhập số nguyên x.
    Hãy đưa ra chỉ số đầu tiên của phần tử đầu tiên có giá trị bằng x,
    nếu không tồn tại số đó thì trả về -1.
*/

#include<stdio.h>

int search(int array[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (x == array[i])
        {
           return i; 
        }
    }
    return -1;
}
int main()
{
    int array[5] = {1,2,4,5,2};
    int n = sizeof(array)/sizeof(int);
    int x;
    printf("x = ");
    scanf("%i",&x);
    printf("%i\n",search(array, n, x));
}