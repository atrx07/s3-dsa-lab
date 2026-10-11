#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push()
{
    int x;
    if (top == MAX - 1)
    {
        printf("Overflow\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &x);
    stack[++top] = x;
    printf("%d pushed to stack\n", x);
}

void pop()
{
    if (top == -1)
    {
        printf("Underflow\n");
        return;
    }

    printf("%d popped\n", stack[top--]);
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("Empty stack\n");
        return;
    }

    printf("stack elements:\n");
    for (i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n\nChoose operation: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice\n");
        }
    }
}