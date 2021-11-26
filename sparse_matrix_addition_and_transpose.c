#include<stdio.h>
#include<stdlib.h>

int a[20][3], b[20][3], add[20][3], transpose[20][3];
int r1, c1, r2, c2, e1, e2, i, j, k;

void read(int a[20][3], int r)
{
    for(i = 1; i <= r; i++)
        for(j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);
}

void print(int a[20][3], int r)
{
    for(i = 0; i <= r; i++)
    {    
        for(j = 0; j < 3; j++)
            printf("%d\t", a[i][j]);
        printf("\n"); 
    }    
}

void sparse_add(int sparse1[20][3], int sparse2[20][3], int add[20][3])
{
    int t1, t2;
    if(sparse1[0][0] != sparse2[0][0] || sparse1[0][1] != sparse2[0][1])
    {
        printf("\nInvalid matrix");
        exit(0);
    }
    t1 = sparse1[0][2];
    t2 = sparse2[0][2];
    add[0][0] = sparse1[0][0];
    add[0][1] = sparse1[0][1];
    i = j = k = 1;
    while(i <= t1 && j <= t2)
    {
        if(sparse1[i][0] < sparse2[j][0])
        {
            add[k][0] = sparse1[i][0];
            add[k][1] = sparse1[i][1];
            add[k][2] = sparse1[i][2];
            i++;
            k++;
        }
        else if(sparse1[i][0] > sparse2[j][0])
        {
            add[k][0] = sparse2[j][0];
            add[k][1] = sparse2[j][1];
            add[k][2] = sparse2[j][2];
            j++;
            k++;
        }
        else if(sparse1[i][0] == sparse2[j][0])
        {
            if(sparse1[i][1] < sparse2[j][1])
            {
                add[k][0] = sparse1[i][0];
                add[k][1] = sparse1[i][1];
                add[k][2] = sparse1[i][2];
                i++;
                k++;
            }
            else if(sparse1[i][1] > sparse2[j][1])
            {
                add[k][0] = sparse2[j][0];
                add[k][1] = sparse2[j][1];
                add[k][2] = sparse2[j][2];
                j++;
                k++;
            }
            else if(sparse1[i][1] == sparse2[j][1])
            {
                add[k][0] = sparse1[i][0];
                add[k][1] = sparse1[i][1];
                add[k][2] = sparse1[i][2] + sparse2[j][2];
                i++;
                j++;
                k++;
            }
        }
    }
    while(i <= t1)
    {
        add[k][0] = sparse1[i][0];
        add[k][1] = sparse1[i][1];
        add[k][2] = sparse1[i][2];
        i++;
        k++;
    }
    while(j <= t2)
    {
        add[k][0] = sparse2[j][0];
        add[k][1] = sparse2[j][1];
        add[k][2] = sparse2[j][2];
        j++;
        k++;
    }
    add[0][2] = k - 1;
}

 void sparse_transpose(int sparse[20][3], int transpose[20][3], int r, int c)
{
    k = 1;
    transpose[0][0] = sparse[0][1];
    transpose[0][1] = sparse[0][0];
    transpose[0][2] = sparse[0][2];
    for(i = 0; i < c; i++)
    {    for(j = 1; j <= sparse[0][2]; j++)
        {
            if(sparse[j][1] == i)
            {
                transpose[k][0] = sparse[j][1];
                transpose[k][1] = sparse[j][0];
                transpose[k][2] = sparse[j][2];
                k++;
            }
        }
    }   
} 

void main()
{
    int ch;
    printf("Enter the rows, columns and non zero elements of first matrix: ");
    scanf("%d%d%d", &r1, &c1, &e1);
    a[0][0] = r1;
    a[0][1] = c1;
    a[0][2] = e1;
    printf("Enter the rows, columns and non zero elements of second matrix: ");
    scanf("%d%d%d", &r2, &c2, &e2);
    b[0][0] = r2;
    b[0][1] = c2;
    b[0][2] = e2;
    printf("\nEnter the elements of first sparse matrix:\n\n");
    read(a, e1);
    printf("\nEnter the elements of second sparse matrix:\n\n");
    read(b, e2);
    printf("\nFirst sparse matrix in triplet form:\n\n");
    print(a, e1);
    printf("\nSecond sparse matrix in triplet form:\n");
    print(b, e2);
    do
    {
        printf("\n\t\tMENU\n");
        printf("\n1. Add sparse matrices");
        printf("\n2. Find the transpose of sparse matrices");
        printf("\n3. Exit");
        printf("\n\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: sparse_add(a, b, add);
                    printf("\nSum of sparse matrices:\n\n");
                    print(add, k - 1);
                    break;
            case 2: sparse_transpose(a, transpose, a[0][0], a[0][1]);
                    printf("\nTranspose of first sparse matrix:\n\n");
                    print(transpose, k - 1);
                    sparse_transpose(b, transpose, b[0][0], b[0][1]);
                    printf("\nTranspose of second sparse matrix:\n\n");
                    print(transpose, k - 1);
                    break;
            case 3: exit(0);        
        }
    }while(ch >= 1 && ch <= 3);
}
