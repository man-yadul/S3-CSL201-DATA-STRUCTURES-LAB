#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*start = NULL, *newnode, *ptr, *temp;

int n;

void insert_start()
{
    newnode = (struct node *)malloc(sizeof(struct node *));
    if(newnode == NULL)
    {
        printf("Out of memory.");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &n);
    newnode -> data = n;
    newnode -> next = start;
    start = newnode;
}

void insert_end()
{
    newnode = (struct node *)malloc(sizeof(struct node *));
    if(newnode == NULL)
    {
        printf("Out of memory.");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &n);
    newnode -> data = n;
    if(start == NULL)  
    {  
        newnode -> next = NULL;  
        start = ptr;  
    }  
    else  
    {  
        ptr = start;  
        while(ptr -> next != NULL)  
        ptr = ptr -> next;  
        ptr -> next = newnode;  
        newnode -> next = NULL;  
    }  
}

void insert_after_node()
{
    int val, count = 0;
    if(start == NULL)  
    {  
        printf("List is empty.\n"); 
        return;
    }  
    newnode = (struct node *)malloc(sizeof(struct node *));
    if(newnode == NULL)
    {
        printf("Out of memory.");
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d", &n);
    newnode -> data = n;
    newnode -> next = NULL;
    printf("Enter value of node to insert after: ");
    scanf("%d", &val);
    ptr = start;
    while(ptr != NULL)  
    {  
        if(ptr -> data == val)
        {
            count = 1;
            break;
        }    
        ptr = ptr -> next;  
    }  
    if(count == 1)
    {
        newnode -> next = ptr -> next;
        ptr -> next = newnode;
    }
    else
    {
        printf("Node not found.\n");
        return;
    }
}

void delete_start()
{
    if(start == NULL)  
    {  
        printf("List is empty.\n"); 
        return;
    }  
    printf("Deleted data: %d", start -> data);
    ptr = start;  
    start = start -> next;  
    free(ptr);  
}

void delete_end()
{
    if(start == NULL)  
    {  
        printf("List is empty.\n");  
    }  
    else if(start -> next == NULL)  
    {  
        printf("Deleted data: %d", start -> data);
        free(start);
        start = NULL;  
    }  
    else  
    {  
        ptr = start;   
        while(ptr -> next -> next != NULL)  
        {  
            ptr = ptr ->next;  
        }  
        printf("Deleted data: %d", ptr -> next -> data);
        free(ptr -> next);
        ptr -> next = NULL;
    }     
}

void delete_from_node()
{
    if(start == NULL)  
    {  
        printf("List is empty.\n");  
        return;
    }  
    int val, count = 0;
    printf("Enter value of node to delete: ");
    scanf("%d", &val);
    ptr = start;
    while (ptr != NULL)  
    {  
        if(ptr -> data == val)
        {
            count = 1;
            break;
        }
        ptr = ptr -> next;  
    }
    if(count == 1)
    {
        if(start -> data == val)  
        {  
            printf("Deleted data: %d", start -> data);
            temp = start;
            start = start -> next; 
            free(temp); 
            return;
        }  
        ptr = start;
        while (ptr -> next -> next != NULL)  
        {  
            if(ptr -> next -> data == val)
            {
                break;
            }
            ptr = ptr -> next;  
        }
        printf("Deleted data: %d", ptr -> next -> data);
        temp = ptr -> next;
        ptr -> next = ptr -> next -> next;
        free(temp);
        return;
    }    
    else
    {
        printf("No node found.\n");
        return;
    }
}

void display()  
{  
    ptr = start;   
    if(ptr == NULL)  
    {  
        printf("List is empty.\n");  
    }  
    else  
    {  
        printf("Linked List:\t");   
        while (ptr != NULL)  
        {  
            printf("%d\t", ptr->data);  
            ptr = ptr -> next;  
        }  
    }  
}     


void main()
{
    int ch;
    do
    {
        printf("\n\t\t\t\t\tMENU\n");
        printf("1. Insert at beginning\t\t2. Insert at end\t3. Insert after specified node\n");
        printf("4. Delete from beginning\t5. Delete from end\t6. Delete from specified node\n");
        printf("\t\t\t\t7. Display\t8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1: insert_start();
                break;
        case 2: insert_end();
                break;
        case 3: insert_after_node();
                break;
        case 4: delete_start();
                break;
        case 5: delete_end();
                break;
        case 6: delete_from_node();
                break;
        case 7: display();
                break;
        }
    }while(ch >= 1 && ch <= 7);
}
