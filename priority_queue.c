#include<stdio.h> 
#define MAX 5

int front = -1, rear = -1, i, j;

struct priority_queue 
{
    int value, priority; 
}item[MAX];

void insert() 
{
    struct priority_queue temp;
    if(front == rear + 1 || front == 0 && rear == MAX - 1) 
    {
        printf("\nQueue is full.\n"); 
        return;
    }
    printf("Enter the value and priority of element: "); 
    if(front == -1) 
        front = 0;
    rear = (rear + 1) % MAX; 
    scanf("%d%d", &item[rear].value, &item[rear].priority);
    for(i = front; i != rear; i = (i + 1) % MAX)
    {
        for(j = front; j != rear; j = (j + 1) % MAX)
        {
            if(item[j].priority > item[(j + 1) % MAX].priority)
            {
                temp = item[j];
                item[j] = item[(j + 1) % MAX];
                item[(j + 1) % MAX] = temp;
            }
        }
    }
}

void delete() 
{
    if(front == -1) 
    {
        printf("\nQueue is empty.\n"); 
        return;
    }
    printf("Deleted element => Value: %d\tPriority: %d\n", item[front].value, item[front].priority); 
    if(front == rear) 
    {
        front = rear = -1; 
    } 
    else 
        front = (front + 1) % MAX; 
}

void display() 
{
    if(front == -1) 
    {
        printf("\nQueue is empty.\n"); 
        return;
    }
    printf("\nPriority queue:\n"); 
    for(i = front; i != rear; i = (i + 1) % MAX) 
        printf("Value: %d\tPriority: %d\n", item[i].value, item[i].priority);
    printf("Value: %d\tPriority: %d\n", item[i].value, item[i].priority);
}

void main() 
{
    int n; 
    do 
    {
        printf("\n\t\t\tMENU\n"); 
        printf("\n1. Insert\t2. Delete\t3. Display\t4.Exit"); 
        printf("\nEnter choice: "); 
        scanf("%d", &n); 
        switch(n) 
        {
        case 1: insert(); 
                break;
        case 2: delete(); 
                break;
        case 3: display(); 
                break;
        } 
    }while(n >= 1 && n <= 3); 
}
