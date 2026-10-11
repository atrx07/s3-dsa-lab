#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert()
{
    int x;
    if (front == (rear + 1) % MAX)
    {
        printf("Queue Overflow\n");
        return;
    }

    printf("Enter number to insert: ");
    scanf("%d", &x);

    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    queue[rear] = x;
    printf("%d Inserted\n", x);
}

void delete()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("%d deleted\n", queue[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue: ");
    for (i = front; ; i = (i + 1) % MAX)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
    }
    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid Choice\n\n");
        }
    }
}