#include<stdio.h>
#include<stdlib.h>

struct poly
{
    int coeff, exp;
}p1[10], p2[10], p3[10], p4[100];

void read(struct poly a[10], int m)
{
    int i;
    for(i = 0; i < m; i++)
    {
        printf("\nTerm %d:", i + 1);
        printf("\nEnter the coefficient and exponent: ");
        scanf("%d%d", &a[i].coeff, &a[i].exp);
    }
}

void display(struct poly b[10], int l)
{
    int i;
    for(i = 0; i < l - 1; i++)
        printf("%dx^%d + ", b[i].coeff, b[i].exp);
    printf("%dx^%d", b[i].coeff, b[i].exp);
}

void add(struct poly x1[10], int e1, struct poly x2[10], int e2, struct poly x3[10], int e3)
{
    int i = 0, j = 0, k = 0;
    while((i < e1) && (j < e2))
    {
        if(x1[i].exp == x2[j].exp)
        {
            x3[k].coeff = x1[i].coeff + x2[j].coeff;
            x3[k].exp = x1[i].exp;
            i++;
            j++;
            k++;
        }
        else if(x1[i].exp > x2[j].exp)
        {
            x3[k].coeff = x1[i].coeff;
            x3[k].exp = x1[i].exp;
            i++;
            k++;
        }
        else
        {
            x3[k].coeff = x2[j].coeff;
            x3[k].exp = x2[j].exp;
            j++;
            k++;
        }
    }
    while(i < e1)
    {
        x3[k].coeff = x1[i].coeff;
        x3[k].exp = x1[i].exp;
        i++;
        k++;
    }
    while(j < e2)
    {
        x3[k].coeff = x2[j].coeff;
        x3[k].exp = x2[j].exp;
        j++;
        k++;
    }
    printf("\nThe sum of the two polynomials:\t");
    display(x3,k);
}

void multiply(struct poly r1[10], int f1, struct poly r2[10], int f2, struct poly r3[100], int f3 )
{
    int i = 0, j = 0, k = 0, l;
    for(i = 0; i < f1; i++)
    {
        for(j = 0; j < f2; j++)
        {
            r3[k].coeff = r1[i].coeff * r2[j].coeff;
            r3[k].exp = r1[i].exp + r2[j].exp;
            k++;
        }
    }
    for(i = 0; i < k; i++)
    {
        for(j = i + 1; j < k; j++)
        {
            if(r3[i].exp == r3[j].exp)
            {
                r3[i].coeff += r3[j].coeff;
                l = j;
                while(j < k)
                {
                    r3[j] = r3[j+1];
                    j++;
                }
                k--;
                j = l;
            }
        }
    }
    for(i = 0; i < k - i; i++)
    {
        for(j = i + 1; j < k; j++)
        {
            if(r3[i].exp < r3[j].exp)
            {
                int tc = r3[j].exp;
                int te = r3[j].coeff;
                while(j > i)
                {
                    r3[j].exp = r3[j - 1].exp;
                    r3[j].coeff = r3[j - 1].coeff;
                    j--;
                }
                r3[i].exp = tc;
                r3[i].coeff = te;
            }
        }
    }
    printf("\nThe product of the two polynomials: ");
    display(r3,k);
}

void main()
{
    int i, n1, n2, n3, ch, j = 0, k = 0;
    printf("Enter the no. of terms of the first and second polynomial: ");
    scanf("%d %d", &n1, &n2);
    printf("\nEnter the coefficients and exponents of the first polynomial (descending order of exponents): ");
    read(p1, n1);
    printf("\nEnter the coefficients and exponents of the second polynomial in (descending order of exponents): ");
    read(p2, n2);
    printf("\nThe first polynomial:\t");
    display(p1, n1);
    printf("\nThe second polynomial:\t");
    display(p2, n2);
    while(1)
    {
        printf("\n\nMENU\n1.Addition\n2.Multiplication\n3.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: add(p1, n1, p2, n2, p3, n3);
                    break;
            case 2: multiply(p1, n1, p2, n2, p3, n3);
                    break;
            case 3: exit(0);
                    break;
            default:printf("Invalid choice");
            break;
        }
    }
}
