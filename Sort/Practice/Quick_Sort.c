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

    for (int i = left + 1; i <= right; i++)
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
int main()
{
    int a[] = {4,1,3,5,2};
    int n = sizeof(a)/sizeof(int);
    quickSort(a,0,n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%i ",a[i]);
    }
}