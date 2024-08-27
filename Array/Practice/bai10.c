/*
    Cho dãy a gồm n số nguyên, và dãy b gồm m số nguyên, cả hai dãy đều được sắp xếp không giảm.
    Hãy gộp hai dãy thành một dãy c, sao cho dãy c cũng là dãy không giảm. 
    In dãy c ra màn hình, sau mỗi phần tử có đúng một dấu cách.
    Input	
    3
    1 3 4
    4
    1 2 3 5
    Output
    1 1 2 3 3 4 5 
*/
#include<stdio.h>
#include<math.h>
int main()
{
    int a[4]= {1,2,4,5};
    int b[5]={1,3,5,6,7};
    int i, j, k = 0;
    int c[9];//khoi tao mang chua
    while (i < 4 && j < 5)
    {
        if (a[i] < b[j])
        {
            c[k++] = a[i++];
            /*
                c[k] = a[i];
                k++;
                i++;
            */
        }
        else
        {
            c[k++] = b[j++];
            /*
                c[k] = b[j];
                k++;
                j++;
            */
        }
    }
    //them cac phan tu con lai cua mang a vao mang c
    while (i < 4)
    {
        c[k++] = a[i++];
    }
    //them cac phan tu con lai cua mang b vao mang c
    while (j < 5)
    {
        c[k++] = b[j++];
    }
    
    for (int i = 0; i < k; i++)
    {
        printf("%d ",c[i]);
    }
    
}
