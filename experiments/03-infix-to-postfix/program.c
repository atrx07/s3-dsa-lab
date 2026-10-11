#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = ch;
}

char pop(void) {
    if (top == -1) return '\0';
    return stack[top--];
}

char peek(void) {
    if (top == -1) return '\0';
    return stack[top];
}

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int main(void) {
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum((unsigned char)ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();
            if (top == -1) {
                printf("Invalid Expression!\n");
                return 0;
            }
            pop();
        } else if (ch == '+' || ch == '-' || ch == '*' ||
                   ch == '/' || ch == '^') {
            while (top != -1 && peek() != '(' &&
                  (precedence(peek()) > precedence(ch) ||
                  (precedence(peek()) == precedence(ch) && ch != '^')))
                postfix[j++] = pop();
            push(ch);
        } else {
            printf("Invalid character: %c\n", ch);
            return 0;
        }
    }

    while (top != -1) {
        if (peek() == '(') {
            printf("Invalid Expression!\n");
            return 0;
        }
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}
