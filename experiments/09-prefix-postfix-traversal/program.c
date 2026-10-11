#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

int main()
{
    char expr[4];
    struct Node *root, *leftNode, *rightNode;

    printf("Enter a simple arithmetic expression (e.g., a+b):\n");
    scanf("%3s", expr);

    leftNode = (struct Node *)malloc(sizeof(struct Node));
    rightNode = (struct Node *)malloc(sizeof(struct Node));
    root = (struct Node *)malloc(sizeof(struct Node));

    leftNode->data = expr[0];
    leftNode->left = NULL;
    leftNode->right = NULL;

    root->data = expr[1];
    root->left = leftNode;

    rightNode->data = expr[2];
    rightNode->left = NULL;
    rightNode->right = NULL;
    root->right = rightNode;

    printf("Prefix expression:\n");
    printf("%c%c%c\n", root->data, root->left->data, root->right->data);

    printf("Postfix expression:\n");
    printf("%c%c%c\n", root->left->data, root->right->data, root->data);

    free(leftNode);
    free(rightNode);
    free(root);

    return 0;
}
