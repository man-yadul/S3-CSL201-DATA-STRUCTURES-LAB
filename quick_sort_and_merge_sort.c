#include <stdio.h>
#include <stdlib.h>

int i, j;

void main()
{
    int n, ch, a[10];
    printf("\nEnter the size of the array : ");
    scanf("%d", &n);
    read(a, n);
    display(a, n);
    while (1)
    {
        printf("\nMENU\n1.QUICK SORT\n2.MERGE SORT\n3.INPUT NEW ARRAY AND PERFORM SORTING\n4.EXIT");
        printf("\nEnter the choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nSorted array : \n");
            quicksort(a, 0, n - 1);
            display(a, n);
            break;
        case 2:
            printf("\nSorted array : \n");
            mergesort(a, 0, n - 1);
            display(a, n);
            break;
        case 3:
            main();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice");
        }
    }
}

void read(int x[], int n)
{

    printf("Enter elements into the array : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }
}

void display(int x[], int n)
{

    printf("The array is : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", x[i]);
    }
}

void quicksort(int a[], int first, int last)
{
    int pivot, temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (a[i] <= a[pivot] && i < last)
                i++;
            while (a[j] > a[pivot])
                j--;
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;
        quicksort(a, first, j - 1);
        quicksort(a, j + 1, last);
    }
}

void mergesort(int a[], int beg, int end)
{
    int mid;
    if (beg < end)
    {
        mid = (beg + end) / 2;
        mergesort(a, beg, mid);
        mergesort(a, mid + 1, end);
        merge(a, beg, mid, end);
    }
}

merge(int a[], int beg, int mid, int end)
{
    i = beg;
    j = mid + 1;
    int index = beg, k = beg;
    int temp[10];
    while (i <= mid && j <= end)
    {
        if (a[i] < a[j])
            temp[index++] = a[i++];
        else
            temp[index++] = a[j++];
    }
    if (i > mid)
    {
        while (j <= end)
            temp[index++] = a[j++];
    }
    else
    {
        while (i <= mid)
            temp[index++] = a[i++];
    }
    while (k < index)
    {
        a[k] = temp[k];
        k = k + 1;
    }
}