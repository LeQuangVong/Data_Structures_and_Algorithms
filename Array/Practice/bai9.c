/*
    Nhập và một số nguyên dương n, tiếp theo là n số nguyên dương lần lượt là các phần tử của một dãy số a. 
    Hãy kiểm tra xem dãy a có phải là dãy đơn điệu hay không, trả về "YES" nếu có, "NO" nếu không.
    Một dãy đơn điệu khi nó là dãy số tăng (a[i] > a[i-1]), hoặc dãy số giảm (a[i] < a[i-1]).
    Input	
    5
    1 2 3 4 5
    Output
    YES
*/
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define MAX 100

int main()
{
    int a[MAX];
    int n;
    bool kt1, kt2 = true;
    printf("Nhap vao so phan tu cua mang = ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
    }
    
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= a[i-1])
        {
            kt1 = false;
        }
        if (a[i] <= a[i-1])
        {
            kt2 = false;
        }
    }
    
    if (kt1 || kt2)
    {
        printf("YES!");
    }
    else printf("NO!");

    return 0;
}