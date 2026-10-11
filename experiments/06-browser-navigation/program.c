#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    char url[100];
    struct node *prev;
    struct node *next;
};
struct node *current = NULL;
void visit(char url[])
{
    struct node *newnode;
    struct node *temp;
    if (current != NULL && current->next != NULL){
        temp = current->next;
        while (temp != NULL){
            struct node *nextnode = temp->next;
            free(temp);
            temp = nextnode;
        }
        current->next = NULL;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL){
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
void back(){
    if (current != NULL && current->prev != NULL){
        current = current->prev;
        printf("Back to: %s\n", current->url);
    }
    else
        printf("No previous page\n");
}
void forward(){
    if (current != NULL && current->next != NULL){
        current = current->next;
        printf("Forward to: %s\n", current->url);
    }
    else
        printf("No next page\n");
}
void display(){
    if (current != NULL)
        printf("Current page: %s\n", current->url);
    else
        printf("No page visited.\n");
}
int main(){
    int choice;
    char url[100];
    while (1){
        printf("\nWeb Browser\n");
        printf("1. Visit new page\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Display current page\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1: printf("Enter URL: ");
                    scanf("%s", url);
                    visit(url);
                    break;
            case 2: back();
                    break;
            case 3: forward();
                    break;
            case 4: display();
                    break;
            case 5: printf("Exiting...\n");
                    return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
