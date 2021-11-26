#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100

char item, infix[MAX], postfix[MAX], stack[MAX];
int i, j, top = -1, eval_stack[MAX];

void push(char item)
{
    if(top == MAX - 1)
    {
        printf("Stack overflow.");
        exit(0);
    }
    top++;
    stack[top] = item;
}

char pop()
{
    char item;
    if(top == -1)
    {
        printf("Stack underflow.");
        exit(0);
    }
    item = stack[top];
    top--;
    return item;
}

void eval_push(int item)
{
    if(top == MAX - 1)
    {
        printf("Stack overflow.");
        exit(0);
    }
    top++;
    eval_stack[top] = item;
}

int eval_pop()
{
    int item;
    if(top == -1)
    {
        printf("Stack underflow.");
        exit(0);
    }
    item = eval_stack[top];
    top--;
    return item;
}

int is_operator(char symbol)
{
    switch(symbol)
    {
        case '+':   
        case '-':   
        case '/':   
        case '*':   
        case '^':   return 1;
        default:    return 0;            
    }
}

int precedence(char symbol)
{
    switch(symbol)
    {
        case '+':   return 1;
        case '-':   return 1;
        case '/':   return 2;
        case '*':   return 2;
        case '^':   return 3;
        default:    return 0;            
    }
}

void infixtopostfix()
{
    char x;
    push('(');
    strcat(infix, ")");
    i = j = 0;
    item = infix[i];
    while(item != '\0')
    {
        if(item == '(')
        {
            push(item);
        }
        else if(isdigit(item) || isalpha(item))
        {
            postfix[j] = item;
            j++;
        }
        else if(is_operator(item) == 1)
        {
            x = pop();
            while(is_operator(x) == 1 && precedence(x) >= precedence(item))
            {
                postfix[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        }
        else if(item == ')')
        {
            x = pop();
            while(x != '(')
            {
                postfix[j] = x;
                j++;
                x = pop();
            }
        }
        else
        {
            printf("\nInvalid expression.");
            exit(0);
        }
        i++;
        item = infix[i];
    }
    printf("\nPostfix expression: ");
    puts(postfix);
}

void evaluate()
{
    int a, b, k;
    i = 0;
    int value;
    char item;
    while(postfix[i] != '\0')
    {
        item = postfix[i];
        if(isalpha(item))
        {
            printf("Enter value for %c: ", postfix[i]);
            scanf("%d", &value);
            eval_push(value);
        }
        else if(isdigit(item))
            eval_push(item - '0');
        else
        {
            b = eval_pop();
            a = eval_pop();
            switch(item)
            {
                case '+':   eval_push(a + b);
                            break;
                case '-':   eval_push(a - b);
                            break;
                case '/':   eval_push(a / b);
                            break;
                case '*':   eval_push(a * b);
                            break;
                case '^':   eval_push(pow(a, b));
            }
        }
        i++;
    }
    printf("\nPostfix evaluation: %d\n", eval_pop());
}

void main()
{
    int ch;
    do
    {
        printf("\n\tMENU\n");
        printf("1. Infix expression entry\n");
        printf("2. Postfix conversion\n");
        printf("3. Postfix evaluation\n");
        printf("4. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("\nEnter infix expression: ");
                    scanf("%s", infix);
                    break;
            case 2: infixtopostfix();
                    break;
            case 3: printf("\n");
                    evaluate();
                    break;
        }
    }while(ch >= 1 && ch <= 3);    
}
