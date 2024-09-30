/*
    Cho một dãy a gồm n số tự nhiên. In số tự nhiên nhỏ nhất chưa xuất hiện trong dãy.
    Input	
    4
    0 1 2 5
    Output
    3

    Với a = [0, 1, 2, 5] thì kết quả mong muốn là 3.
*/
#include<stdio.h>
void swap(int a[], int x, int y)
{
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

int partition(int a[], int left, int right)
{
    int pivot = a[left];
    int count = 0;

    for (int i = left+1; i <= right; i++)
    {
        if (a[i] <= pivot)
        {
            count++;
        }
    }
    
    int pivotIndex = left + count;
    swap(a,left,pivotIndex);

    int i = left;
    int j = right;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        
        while (a[j] > pivot)
        {
            j--;
        }
        
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(a,i,j);
        }
    }
    return pivotIndex;
}

void quickSort(int a[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    
    int pivot = partition(a,left,right);

    quickSort(a,left,pivot-1);
    quickSort(a,pivot+1,right);
}

int findMin(int a[], int n)
{
    quickSort(a,0,n-1);

    if (a[0] > 0)
    {
        return 0;
    }
    
    for (int i = 1; i < n; i++)    
    {
        if (a[i] - a[i-1] > 1)
        {
            return a[i - 1] + 1;
        }
    }
    
    return a[n-1] + 1;
}
int main()
{
    int a[] = {6,2,4,3,0,1};
    int n = sizeof(a)/sizeof(int);
    int min = findMin(a,n);
    for (int i = 0; i < n; i++)
    {
        printf("%i ",a[i]);
    }
    printf("ket qua = %i\n",min);
    return 0;
}