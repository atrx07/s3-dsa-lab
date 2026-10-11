#include <stdio.h>
#define max 5

int stack[max];
int top = -1;

void push()
{
    int a;
    if (top == max - 1)
    {
        printf("Overflow\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &a);
    top++;
    stack[top] = a;
    printf("%d pushed to stack\n", a);
}

void pop()
{
    if (top == -1)
    {
        printf("Underflow\n");
        return;
    }
    printf("%d popped\n", stack[top]);
    top--;
}

void disp()
{
    int i;
    if (top == -1)
    {
        printf("Empty stack\n");
        return;
    }
    printf("stack elements:\n");
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    int c;
    while (1)
    {
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("\nChoose operation: ");
        scanf("%d", &c);

        switch (c)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                disp();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
