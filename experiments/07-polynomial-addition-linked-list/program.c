#include <stdio.h>
#include <stdlib.h>

struct node{
    int coeff, exp;
    struct node *next;
};

struct node *newNode(int c, int e){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->coeff = c;
    p->exp = e;
    p->next = NULL;
    return p;
}

struct node *createPolynomial(){
    struct node *head = NULL, *tail = NULL, *p;
    int n, i, c, e;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++){
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &c, &e);

        p = newNode(c, e);
        if (head == NULL)
            head = p;
        else
            tail->next = p;
        tail = p;
    }
    return head;
}

struct node *addPolynomial(struct node *p1, struct node *p2){
    struct node *head = NULL, *tail = NULL, *p;
    int c, e;

    while (p1 != NULL || p2 != NULL){
        if (p2 == NULL || (p1 != NULL && p1->exp > p2->exp)){
            c = p1->coeff; e = p1->exp;
            p1 = p1->next;
        }
        else if (p1 == NULL || p2->exp > p1->exp){
            c = p2->coeff; e = p2->exp;
            p2 = p2->next;
        }
        else{
            c = p1->coeff + p2->coeff;
            e = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
        }

        if (c == 0)
            continue;

        p = newNode(c, e);
        if (head == NULL)
            head = p;
        else
            tail->next = p;
        tail = p;
    }
    return head;
}

void display(struct node *p){
    while (p != NULL){
        printf("%dx^%d", p->coeff, p->exp);
        if (p->next != NULL)
            printf(" + ");
        p = p->next;
    }
    printf("\n");
}

int main(){
    struct node *p1, *p2, *result;

    printf("Enter first polynomial (descending exponents)\n");
    p1 = createPolynomial();

    printf("\nEnter second polynomial (descending exponents)\n");
    p2 = createPolynomial();

    result = addPolynomial(p1, p2);

    printf("\nFirst Polynomial: "); display(p1);
    printf("Second Polynomial: "); display(p2);
    printf("Result: "); display(result);

    return 0;
}