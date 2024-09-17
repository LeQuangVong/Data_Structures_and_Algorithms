/*
    Cho số nguyên dương n, tiếp theo là n số nguyên cũng một dãy a, cuối cùng là một số x, biết dãy là dãy không giảm.
    Hãy đưa ra chỉ số của phần tử đầu tiên có giá trị bằng x, nếu không tồn tại giá trị đó đưa ra -1.
    Input	
    4
    1 2 3 4
    3
    Output
    2
    Với a = [1, 2, 3, 4] và x = 3 thì kết quả mong muốn là 2.
*/
#include<stdio.h>
int binSearch(int a[], int n, int x)
{
    int l = 0,r = n-1;
    while (l<r)
    {
        int mid = (l+r)/2;
        if (a[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    if (a[l] == x)
        {
            return l;
        }
    return -1;
}
int main()
{
    int a[] = {1,2,3,4,5,6};
    int n = sizeof(a)/sizeof(int);
    int x;
    printf("x = ");
    scanf("%i",&x);
    printf("%i",binSearch(a,n,x));
    return 0;
}
