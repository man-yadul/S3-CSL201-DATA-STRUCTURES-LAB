#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int lin_prob_array[MAX] = {[0 ... MAX - 1] = -1};
int quad_prob_array[MAX] = {[0 ... MAX - 1] = -1};
int size, c1, c2;

struct node
{
    int key;
    struct node *next;
}*chaining_array[MAX] = {NULL};

void display_lin_quad(int a[MAX])
{
    int i;

    printf("Hash table: ");
    for(i = 0; i < size; i++)
    {
        if(a[i] != -1)
            printf("%d ", a[i]);
        else 
            printf("- ");
    }
}

void display_chaining()
{
    int i;
    struct node *ptr;

    printf("Hash table:\n");
    for(i = 0; i < size; i++)
    {
        printf("%d - ", i);

        ptr = chaining_array[i];

        if(chaining_array[i] == NULL)
            printf("NULL");
        else 
        {
            while(ptr != NULL)
            {
                printf("%d -> ", ptr -> key);
                ptr = ptr -> next;
            }
            printf("NULL");
        }

        printf("\n");
    }
}

void insert_lin_prob(int key)
{
    int i, hash, finalhash, flag = 1;

    for(i = 0; i < size; i++)
    {
        if(lin_prob_array[i] == -1)
            flag = 0;
    }

    if(flag == 1)
    {
        printf("\nHash table is full.");
        return;
    }

    finalhash = hash = key % size;

    if(lin_prob_array[hash] != -1)
    {
        for(i = 0; i < size; i++)
        {
            finalhash = (hash + i) % size;

            if(lin_prob_array[finalhash] == -1)
                break;
        }
    }

    lin_prob_array[finalhash] = key;

    if(key!= -1)
        display_lin_quad(lin_prob_array);
}

void insert_quad_prob(int key)
{
    int i, hash, finalhash, flag = 1;

    for(i = 0; i < size; i++)
    {
        if(lin_prob_array[i] == -1)
            flag = 0;
    }

    if(flag == 1)
    {
        printf("\nHash table is full.");
        return;
    }

    finalhash = hash = key % size;

    if(quad_prob_array[hash] != -1)
    {
        for(i = 0; i < size; i++)
        {
            finalhash = (hash + c1 * i + c2 * i * i) % size;

            if(quad_prob_array[finalhash] == -1)
                break;
        }
    }

    quad_prob_array[finalhash] = key;

    if(key != -1)
        display_lin_quad(quad_prob_array);
}

void insert_chaining(int key)
{
    int i, hash;
    struct node *newnode, *ptr;

    hash = key % size;

    newnode = (struct node *)malloc(sizeof(struct node *)); 
    newnode -> key = key;
    newnode -> next = NULL;  

    if(chaining_array[hash] == NULL)
        chaining_array[hash] = newnode;
    else 
    {
        ptr = chaining_array[hash];

        while(ptr -> next != NULL)
            ptr = ptr -> next;

        ptr -> next = newnode;
    }

    if(key != -1)
        display_chaining();
}

void main()
{
    int ch, key;

    printf("Enter hash table size: ");
    scanf("%d", &size);

    printf("Choose collision resolution method -\n");
    printf("1. Linear Probing, 2. Quadratic Probing, 3. Chaining: ");
    scanf("%d", &ch);

    if(ch == 2)
    {
        printf("Enter values of c1 and c2: ");
        scanf("%d%d", &c1, &c2);
    }

    do 
    {
        printf("\nEnter key to insert (-1 to exit): ");
        scanf("%d", &key);

        switch(ch)
        {
            case 1: insert_lin_prob(key);
                    break;

            case 2: insert_quad_prob(key);
                    break;

            case 3: insert_chaining(key);
                    break;
        } 
    }while(key != -1);
}
