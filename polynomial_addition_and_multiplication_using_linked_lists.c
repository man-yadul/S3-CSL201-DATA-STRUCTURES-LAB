#include <stdio.h>
#include <stdlib.h>

struct element
{
    int coeff;
    int expo;
    struct element *next;
} * p1, *p2, *sum, *product;

struct element *readPoly()
{
    int val;
    struct element *start;
    start = NULL;
    struct element *current;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &val);
    printf("Enter the coefficient and exponent of each term in decreasing order of exponents:\n");
    for (int i = 0; i < val; i++)
    {
        struct element *newnode = (struct element *)malloc(sizeof(struct element));
        newnode->next = NULL;
        printf("Enter the coefficient of term %d: ", i + 1);
        scanf("%d", &newnode->coeff);
        printf("Enter the exponent of term %d: ", i + 1);
        scanf("%d", &newnode->expo);
        if (start == NULL)
        {
            start = newnode;
            current = newnode;
        }
        else
        {
            current->next = newnode;
            current = newnode;
        }
    }
    return start;
}

void display(struct element *start)
{
    struct element *ptr = (struct element *)malloc(sizeof(struct element));
    ptr = start;
    while (ptr->next != NULL)
    {
        printf("%dx^%d + ", ptr->coeff, ptr->expo);
        ptr = ptr->next;
    }
    printf("%dx^%d\n", ptr->coeff, ptr->expo);
}

struct element *addPoly(struct element *a, struct element *b)
{
    struct element *c;
    struct element *ptr = (struct element *)malloc(sizeof(struct element));
    c = ptr;
    while (a != NULL && b != NULL)
    {
        if (a->expo > b->expo)
        {
            ptr->coeff = a->coeff;
            ptr->expo = a->expo;
            a = a->next;
        }
        else if (b->expo > a->expo)
        {
            ptr->coeff = b->coeff;
            ptr->expo = b->expo;
            b = b->next;
        }
        else
        {
            ptr->coeff = a->coeff + b->coeff;
            ptr->expo = a->expo;
            a = a->next;
            b = b->next;
        }
        if (a || b)
        {
            ptr->next = (struct element *)malloc(sizeof(struct element));
            ptr = ptr->next;
            ptr->next = NULL;
        }
        else
        {
            ptr->next = NULL;
        }
    }
    while (a != NULL || b != NULL)
    {
        if (a != NULL)
        {
            ptr->coeff = a->coeff;
            ptr->expo = a->expo;
            a = a->next;
        }
        else if (b != NULL)
        {
            ptr->coeff = b->coeff;
            ptr->expo = b->expo;
            b = b->next;
        }
        if (a || b)
        {
            ptr->next = (struct element *)malloc(sizeof(struct element));
            ptr = ptr->next;
            ptr->next = NULL;
        }
        else
        {
            ptr->next = NULL;
        }
    }
    return c;
}

struct element *multiPoly()
{
    struct element *a, *b, *current, *c = NULL;
    int tempc, tempe;
    a = p1;
    while (a != NULL)
    {
        b = p2;
        while (b != NULL)
        {
            struct element *newnode = (struct element *)malloc(sizeof(struct element));
            newnode->coeff = a->coeff * b->coeff;
            newnode->expo = a->expo + b->expo;
            newnode->next = NULL;
            if (c == NULL)
            {
                c = newnode;
                current = newnode;
            }
            else
            {
                current->next = newnode;
                current = newnode;
            }
            b = b->next;
        }
        a = a->next;
    }
    display(c);
    a = c;
    while (a != NULL)
    {
        b = a->next;
        while (b != NULL)
        {
            if (a->expo < b->expo)
            {
                tempe = a->expo;
                tempc = a->coeff;
                a->coeff = b->coeff;
                a->expo = b->expo;
                b->coeff = tempc;
                b->expo = tempe;
            }
            b = b->next;
        }
        a = a->next;
    }
    display(c);
    a = c;
    while (a != NULL)
    {
        b = a->next;
        while (b != NULL)
        {
            if (a->expo == b->expo)
            {
                a->coeff = a->coeff + b->coeff;
                a->next = b->next;
                current = b;
                b = b->next;
                free(current);
                continue;
            }
            b = b->next;
            //free(current);
        }
        a = a->next;
    }
    display(c);
    return c;
}

void main()
{
    int choice;
    struct element *ptr;
    while (1)
    {
        printf("\nMENU:\n");
        printf("1.Add two polynomials\n");
        printf("2.Multiply two polynomials\n");
        printf("3.Exit\n");
        printf("\nEnter a choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the first polynomial:\n");
            p1 = readPoly();
            printf("\nThe first polynomial is: ");
            display(p1);
            printf("\nEnter the second polynomial:\n");
            p2 = readPoly();
            printf("\nThe second polynomial is: ");
            display(p2);
            sum = addPoly(p1, p2);
            printf("\nThe sum of the given polynomials is: ");
            display(sum);
            break;
        case 2:
            printf("\nEnter the first polynomial:\n");
            p1 = readPoly();
            printf("\nThe first polynomial is: ");
            display(p1);
            printf("\nEnter the second polynomial:\n");
            p2 = readPoly();
            printf("\nThe second polynomial is: ");
            display(p2);
            product = multiPoly();
            printf("\nThe product of the given polynomials is: ");
            display(product);
            break;
        case 3:
            exit(0);
        default:
            printf("\nPlease enter a valid choice\n");
            break;
        }
        while (sum != NULL)
        {
            ptr = sum;
            sum = sum->next;
            free(ptr);
        }
        while (product != NULL)
        {
            ptr = product;
            product = product->next;
            free(ptr);
        }
        while (p1 != NULL)
        {
            ptr = p1;
            p1 = p1->next;
            free(ptr);
        }
        while (p2 != NULL)
        {
            ptr = p2;
            p2 = p2->next;
            free(ptr);
        }
    }
}