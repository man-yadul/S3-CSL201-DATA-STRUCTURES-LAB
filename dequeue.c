#include<stdio.h> 
#define MAX 5

int dequeue[MAX], front = -1, rear = -1, i;

void insert_rear()
{
    int n;
    if(front == rear + 1 || front == 0 && rear == MAX - 1) 
    {
        printf("\nQueue is full.\n"); 
        return;
    }
    printf("Enter element to insert: "); 
    scanf("%d", &n); 
    if(front == -1) 
        front = 0;
    rear = (rear + 1) % MAX; 
    dequeue[rear] = n;
}

void insert_front()
{
    int n;
    if(front == rear + 1 || front == 0 && rear == MAX - 1) 
    {
        printf("\nQueue is full.\n"); 
        return;
    }
    printf("Enter element to insert: "); 
    scanf("%d", &n);
    if(front == -1)
    {
        front = rear = 0;
        dequeue[front] = n;
    }
    else
    {
        if(front == 0)
            front = MAX - 1;
        else
            front--;
        dequeue[front] = n;
    }
}

void delete_front()
{
    if(front == -1) 
    {
        printf("\nQueue is empty.\n"); 
        return;
    }
    printf("Deleted element: %d\n", dequeue[front]);
    if(front == rear) 
        front = rear = -1; 
    else
        front = (front + 1) % MAX; 
}

void delete_rear()
{
    if(front == -1) 
    {
        printf("\nQueue is empty.\n"); 
        return;
    }
    printf("Deleted element: %d\n", dequeue[rear]);
    if(front == rear)
        front = rear = -1;
    else
    {
        if(rear == 0)
            rear = MAX - 1;
        else
            rear--;
    }
}

void display() 
{
    if(front == -1) 
    {
        printf("\nQueue is empty.\n"); 
        return;
    }
    printf("\nDequeue: "); 
    for(i = front; i != rear; i = (i + 1) % MAX) 
        printf("%d\t", dequeue[i]); 
    printf("%d\t", dequeue[i]);
}

int main()
{
    int ch;
    do
    {
        printf("\n\t\t\t\tMENU\n"); 
        printf("1. Insert from front\t2. Insert from rear\t3. Delete from front\n");
        printf("4. Delete from rear\t5. Display\t\t6. Exit");
        printf("\nEnter choice: "); 
        scanf("%d", &ch);
        switch(ch)
        {
        case 1: insert_front();
                break;
        case 2: insert_rear();
                break;
        case 3: delete_front();
                break;
        case 4: delete_rear();
                break;
        case 5: display();
                break;
        }
    }while(ch >= 1 && ch <= 5);
}
