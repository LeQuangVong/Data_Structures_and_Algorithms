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
        if (a_left[i1] < a_right[i2])
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
        int middle = (left + right)/2;
        mergeSort(a,left,middle);
        mergeSort(a,middle+1,right);
        merge(a,left,middle,right);
    }
    
}
int main()
{
    int a[] = {2,5,2,6,1,1};
    int n = sizeof(a)/sizeof(int);
    mergeSort(a,0,n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%i ",a[i]);
    }
}