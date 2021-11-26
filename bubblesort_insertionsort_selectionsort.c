#include <stdio.h>
#define SIZE 10

int i, j, n, temp, a[SIZE];

void entry()
{
    printf("\nEnter no. of elements in the array: ");
    scanf("%d", &n);
    printf("\nEnter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void display()
{
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
}

void bubble_sort()
{
    int temp;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("Sorted array after bubble sort: ");
    display();
}

void insertion_sort()
{
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while ((temp < a[j]) && (j >= 0))
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    printf("Sorted array after insertion sort: ");
    display(a);
}

int smallest(int k)
{
    int pos = k, small = a[k], i;
    for (i = k + 1; i < n; i++)
    {
        if (a[i] < small)
        {
            small = a[i];
            pos = i;
        }
    }
    return pos;
}

void selection_sort()
{
    int k, pos;
    for (k = 0; k < n; k++)
    {
        pos = smallest(k);
        temp = a[k];
        a[k] = a[pos];
        a[pos] = temp;
    }
    printf("Sorted array after selection sort: ");
    display();
}

void main()
{
    int ch;

    do
    {
        printf("\n\t\t\tMENU\n");
        printf("1. Entry\t\t2. Display\t\t3. Bubble Sort\n4. Insertion Sort\t5. Selection Sort\t6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            entry();
            break;
        case 2:
            printf("Array:\t");
            display();
            break;
        case 3:
            bubble_sort();
            break;
        case 4:
            insertion_sort();
            break;
        case 5:
            selection_sort();
            break;
        }
    } while (ch >= 1 && ch <= 5);
}
