#include<stdio.h>

int i, j, n, a[100];

void entry()
{
    printf("\nEnter no. of elements in the array: ");
    scanf("%d", &n);
    printf("\nEnter the elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void display()
{
    for(i = 0; i < n; i++)
        printf("%d\t", a[i]);
}

void lin_search()
{
    int item;

    printf("\nEnter element to search: ");
    scanf("%d", &item);

    for(i = 0; i < n; i++)
    {
        if(item == a[i])
        {
            printf("\nItem found at location %d.\n", i + 1);
            return;
        }
    }
    printf("\nItem not found.\n");    
}

void bin_search()
{
    int item, temp, beg, mid, end, flag = 0;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j+1] = temp;       
            }
        }
    }

    printf("Array after sorting:\t");
    display();

    printf("\n\nEnter element to search: ");
    scanf("%d", &item);

    beg = 0;
    end = n - 1;
    while(beg <= end)
    {
        mid = (beg + end) / 2;    
        if(a[mid] == item)
        {
            printf("Item found at location %d.\n", mid + 1);
            return;
        }      
        else if(a[mid] < item)
            beg = mid + 1; 
        else
            end = mid - 1;
    }
    printf("\nItem not found.\n");    
}

void main()
{
    int ch;
    do
    {
        printf("\n\t\t\tMENU\n");
        printf("1. Entry\t2. Display\t3. Linear search\n\t4. Binary Search\t5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: entry();
                    break;
            case 2: printf("Array:\t");
                    display();
                    break;               
            case 3: lin_search();
                    break;
            case 4: bin_search();
                    break;              
        }
    } while (ch >= 1 && ch <= 4);
}
