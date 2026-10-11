#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char url[100];
    struct node *prev, *next;
};

struct node *current = NULL;

void visit(char url[])
{
    struct node *temp, *nextnode, *newnode;

    temp = current ? current->next : NULL;
    while (temp != NULL)
    {
        nextnode = temp->next;
        free(temp);
        temp = nextnode;
    }

    if (current != NULL)
        current->next = NULL;

    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(newnode->url, url);
    newnode->prev = current;
    newnode->next = NULL;

    if (current != NULL)
        current->next = newnode;

    current = newnode;
    printf("Visited: %s\n", current->url);
}

void back()
{
    if (current != NULL && current->prev != NULL)
    {
        current = current->prev;
        printf("Back to: %s\n", current->url);
    }
    else
        printf("No previous page\n");
}

void forward()
{
    if (current != NULL && current->next != NULL)
    {
        current = current->next;
        printf("Forward to: %s\n", current->url);
    }
    else
        printf("No next page\n");
}

void display()
{
    if (current != NULL)
        printf("Current page: %s\n", current->url);
    else
        printf("No page visited.\n");
}

int main()
{
    int choice;
    char url[100];

    while (1)
    {
        printf("\nWeb Browser\n1. Visit new page\n2. Back\n3. Forward\n4. Display current page\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter URL: ");
                scanf("%s", url);
                visit(url);
                break;
            case 2: back(); break;
            case 3: forward(); break;
            case 4: display(); break;
            case 5: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice!\n");
        }
    }
}