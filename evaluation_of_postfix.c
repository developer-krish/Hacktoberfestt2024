#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct stack
{
    int Top;
    int size;
    int *arr;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->Top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->Top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, int x)
{
    if (isFull(ptr))
    {
        printf("Stack is full\n");
    }
    else
    {
        ptr->Top++;
        ptr->arr[ptr->Top] = x;
    }
}
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is empty\n");
        return '\0';
    }
    else
    {
        char x = ptr->arr[ptr->Top];
        ptr->Top--;
        return x;
    }
}
int stack_top(struct stack *ptr)
{
    if (!isEmpty(ptr))
    {
        return ptr->arr[ptr->Top];
    }
    return '\0';
}
int isOperator(char ch)
{
    if ((ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isOperand(char ch)
{
    if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int evaluate_postfix(char *postfix)
{
    int A, B, result;
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 25;
    sp->Top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    int i = 0;
    while (postfix[i] != '\0')
    {
        if (isOperand(postfix[i]))
        {
            int value;
            printf("Enter value for %c: ", postfix[i]);
            scanf("%d", &value); // Store input in value
            push(sp, value);
        }
        else if (isOperator(postfix[i]))
        {
            A = pop(sp);
            B = pop(sp);
            switch (postfix[i])
            {
            case '+':
                result = B + A;
                break;
            case '-':
                result = B - A;
                break;
            case '*':
                result = B * A;
                break;
            case '/':
                result = B / A;
                break;
            case '^':
                result = pow(B, A);
                break;
            }
            push(sp, result);
        }
        i++;
    }
    result = pop(sp);
    return result;
}
int main()
{
    char *postfix = "ab*cd+ef^/-";
    int result = evaluate_postfix(postfix);
    printf("Answer of the postfix expression is : %d", result);
}
