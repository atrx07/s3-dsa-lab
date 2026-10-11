#include <stdio.h>

struct Node
{
    char data;
    struct Node *left, *right;
};

int main()
{
    char expr[4];
    struct Node root, left, right;

    printf("Enter a simple arithmetic expression (e.g., a+b):\n");
    scanf("%3s", expr);

    left.data = expr[0];
    left.left = left.right = NULL;

    right.data = expr[2];
    right.left = right.right = NULL;

    root.data = expr[1];
    root.left = &left;
    root.right = &right;

    printf("Prefix expression:\n");
    printf("%c%c%c\n", root.data, root.left->data, root.right->data);

    printf("Postfix expression:\n");
    printf("%c%c%c\n", root.left->data, root.right->data, root.data);

    return 0;
}