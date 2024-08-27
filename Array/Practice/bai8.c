/*
    Nhập và một số nguyên dương n, tiếp theo là n số nguyên dương lần lượt là các phần tử của một dãy số, 
    hãy đếm tần số (số lần xuất hiện) của các số trong dãy và in nó ra màn hình dưới dạng sau:
    "a1 - t1; a2 - t2; ... an - tn; ", 
    trong đó t1 là số lần xuất hiện của số a1, t2 là số lần xuất hiện của a2, ... a1, a2, .. an 
    không trùng nhau và được sắp xếp tăng dần (xem ví dụ để rõ hơn).
    Input	
    6
    4 2 2 5 6 5
    Output
    2 - 2; 4 - 1; 5 - 2; 6 - 1;
*/
#include<stdio.h>
#include<math.h>
#define MAX 100

int main()
{
    int a[MAX];
    int dem[MAX];
    int n;
    //Nhap mang
    printf("Nhap so luong phan tu trong mang = ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
    }
    /*
        khoi tao mang dem cac phan tu bang -1
        dem = [-1,-1,-1,-1,...]
    */
    for (int i = 0; i < n; i++)
    {
        dem[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i+1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
                dem[j] = 0;// đánh dấu phần tử đã được đếm
            }
        }
        if (dem[i] != 0)//nếu phần tử chưa được đếm
        {
            dem[i] = count;//gán bằng số lần xuất hiện của a[i]
        }
    }
    /*
        Sắp xếp các phần tử của 2 mảng theo thứ tự tăng dần
    */
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;

                temp = dem[i];
                dem[i] = dem[j];
                dem[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        int flag = 1;
        if (dem[i] != 0)
        {
            printf("%d - %d", a[i], dem[i]);
            if (flag != 0)
            {
                printf("; ");
                flag = 0;
            }
        }
    }
    
    return 0;
}



