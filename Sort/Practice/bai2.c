/*
    Nhập và một số nguyên dương n, tiếp theo là n số nguyên lần lượt là các phần tử của một dãy số,
    hãy đếm tần số (số lần xuất hiện) của các số trong dãy và 
    in nó ra màn hình dưới dạng sau: "a1 t1; a2 t2; ... an tn; ", 
    trong đó t1 là số lần xuất hiện của số a1, 
    t2 là số lần xuất hiện của a2, ... a1, a2, .. an không trùng nhau và 
    được sắp xếp tăng dần.
    Input	
    7
    -3 -3 2 4 2 2 6
    Output
    -3 2; 2 3; 4 1; 6 1;

    Với a = [-3, -3, 2, 4, 2, 2, 6] thì kết quả mong muốn là: "-3 2; 2 3; 4 1; 6 1; ".
*/

#include<stdio.h>

void merge(int a[], int left, int middle, int right)
{
    int len_left = middle - left + 1;
    int len_right = right - middle;

    int a_left[len_left];
    int a_right[len_right];
    for (int i = 0; i < len_left; i++)
    {
        a_left[i] = a[left+i];
    }
    
    for (int i = 0; i < len_right; i++)
    {
        a_right[i] = a[(middle+1)+i];
    }
    
    int i1 = 0;
    int i2 = 0;
    int k = left;

    while (i1 < len_left && i2 < len_right)
    {
        if (a_left[i1] <= a_right[i2])
        {
            a[k] = a_left[i1];
            i1++;
        }
        else
        {
            a[k] = a_right[i2];
            i2++;
        }
        k++;
    }
    while (i1 < len_left)
    {
        a[k] = a_left[i1];
        i1++;
        k++;
    }
    
    while (i2 < len_right)
    {
        a[k] = a_right[i2];
        i2++;
        k++;
    }
}

void mergeSort(int a[], int left, int right)
{
    if (right > left)
    {
        int middle = (right + left)/2;

        mergeSort(a,left,middle);
        mergeSort(a,middle+1,right);
        merge(a,left,middle,right);
    }
    
}
int main()
{
    int a[] = {-3,-3,2,4,2,2,6};
    int n = sizeof(a)/sizeof(int);
    int count = 1;
    mergeSort(a,0,n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%i ",a[i]);
    }
    
    for (int i = 1; i < n ; i++)
    {
        if (a[i] == a[i-1])
        {   
            count++;
        }
        else
        {
            printf("%i %i;",a[i-1],count);
            count = 1;
        }
    }
    printf("%i %i;\n",a[n-1],count);
    return 0;
}
