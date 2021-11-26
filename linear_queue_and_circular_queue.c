#include<stdio.h>
#define MAX 100

int lin_queue[MAX], circ_queue[MAX], lin_front = -1, lin_rear = -1, circ_front = -1, circ_rear = -1, i;

int lin_isempty()
{
    if(lin_front == -1 || lin_front > lin_rear)
    {
        printf("\nQueue is empty.\n");
        return 1;
    }
    else
        return 0;
}

int lin_isfull()
{
    if(lin_rear == MAX - 1)
    {
        printf("\nQueue is full.\n");
        return 1;
    }
    else 
        return 0;
}

void lin_insert()
{
    int n;
    if(lin_isfull())
    {
        return;
    }
    if(lin_front == -1)
        lin_front = 0;
    printf("Enter element to add to queue: ");
    scanf("%d", &n);
    lin_queue[++lin_rear] = n;
}

void lin_delete()
{
    if(lin_isempty())
    {
        return;
    }
    printf("Deleted element: %d\n", lin_queue[lin_front]);
    if(lin_front == lin_rear)
        lin_front = lin_rear = -1;
    else
        lin_front++;
}

void lin_display()
{
    if(lin_front == -1)
    {
        printf("\nQueue is empty.\n");
        return;
    }
    printf("\nQueue: ");
    for(i = lin_front; i <=  lin_rear; i++)
        printf("%d\t", lin_queue[i]);
}

int circ_isempty()
{
    if(circ_front == -1)
    {
        printf("\nQueue is empty.\n");
        return 1;
    }
    else
        return 0;
}

int circ_isfull()
{
    if(circ_front == circ_rear + 1 || circ_front == 0 && circ_rear == MAX - 1)
    {
        printf("\nQueue is full.\n");
        return 1;
    }
    else 
        return 0;
}

void circ_insert()
{
    int n;
    if(circ_isfull())
    {
        return;
    }
    printf("Enter element to insert: ");
    scanf("%d", &n);
    if(circ_front == -1)
        circ_front = 0;
    circ_rear = (circ_rear + 1) % MAX;    
    circ_queue[circ_rear] = n;    
}

void circ_delete()
{
    int n;
    if(circ_isempty())
    {
        return;
    }
    n = circ_queue[circ_front];
    if(circ_front == circ_rear)
    {
        circ_front = circ_rear = -1;
    }
    else
        circ_front = (circ_front + 1) % MAX;
    printf("Deleted element: %d\n", n);
}

void circ_display()
{
    if(circ_isempty())
    {
        return;
    }
    printf("\nCircular queue: ");
    for(i = circ_front; i != circ_rear; i = (i + 1) % MAX)
        printf("%d\t", circ_queue[i]);
    printf("%d\t", circ_queue[i]);    
}

void main()
{
    int ch, ch1, ch2;
    do
    {
        printf("\n\t\tMAIN MENU\n");
        printf("1. Linear Queue\t2. Circular Queue 3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: do
                    {
                        printf("\n\t\tLINEAR QUEUE MENU\n");
                        printf("1. Insert\t2. Delete\t3. Display\n4.Is Empty\t5.Is Full\t6. Exit to main menu\n");
                        printf("Enter choice: ");
                        scanf("%d", &ch1);
                        switch(ch1)
                        {
                            case 1: lin_insert();
                                    break;
                            case 2: lin_delete();
                                    break;
                            case 3: lin_display();
                                    break;
                            case 4: if(lin_isempty() == 0)
                                        printf("\nQueue is not empty.\n");
                                    break;
                            case 5: if(lin_isfull() == 0)
                                        printf("\nQueue is not full.\n");
                                    break;
                        }
                    }while(ch1 >= 1 && ch1 <= 5);
                    break;
            case 2: do
                    {
                        printf("\n\t\tCIRCULAR QUEUE MENU\n");
                        printf("1. Insert\t2. Delete\t3. Display\n4.Is Empty\t5.Is Full\t6. Exit to main menu\n");
                        printf("Enter choice: ");
                        scanf("%d", &ch2);
                        switch(ch2)
                        {
                            case 1: circ_insert();
                                    break;
                            case 2: circ_delete();
                                    break;
                            case 3: circ_display();
                                    break;
                            case 4: if(circ_isempty() == 0)
                                        printf("\nQueue is not empty.\n");
                                    break;
                            case 5: if(circ_isfull() == 0)
                                        printf("\nQueue is not full.\n");
                                    break;
                        }
                    }while(ch2 >= 1 && ch2 <= 5);
                    break;
        }
    }while(ch >= 1 && ch <= 2);    
}
