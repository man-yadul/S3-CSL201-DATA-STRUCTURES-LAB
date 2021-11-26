#include<stdio.h>
#define max 100

int top = -1, a[max], i;

void push()
{
    int n;
    if(top == max - 1)
    {
        printf("\nStack overflow.");
        return;
    }
    top++;
    printf("\nEnter element to push: ");
    scanf("%d", &n);
    a[top] = n;
}

void pop()
{
    if(top == -1)
    {
        printf("\nStack underflow.");
        return;
    }
    printf("\nDeleted element: %d\n", a[top]);
    top--;
}

void peek()
{
    if(top == -1)
    {
        printf("\nStack underflow.");
        return;
    }
    printf("\nTopmost element: %d\n", a[top]);
}

void isempty()
{
    if(top == -1)
        printf("\nStack is empty.\n");
    else
        printf("\nStack is not empty.\n");
}

void isfull()
{
    if(top == max - 1)
        printf("\nStack is full.\n");
    else
        printf("\nStack is not full.\n");
}

void display()
{
    if(top == -1)
    {
        printf("\nStack underflow.\n");
        return;
    }
    for(i = top; i >= 0; i--)
        printf("\n%d", a[i]);
}

void main()
{
    int n;
    do
    {
        printf("\n\t\tMENU\n");
        printf("\n1. Push\t\t2. Pop\t\t3. Peek\n4. Is Empty\t5. Is Full\t6. Display\n\t\t7.Exit");
        printf("\n\nEnter choice: ");
        scanf("%d", &n);
        switch(n)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: peek();
                    break;
            case 4: isempty();
                    break;
            case 5: isfull();
                    break;
            case 6: display();
                    break;
        }
    }while(n >= 1 && n <= 6);
}
