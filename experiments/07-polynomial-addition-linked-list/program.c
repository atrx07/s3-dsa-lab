#include <stdio.h>
#include <stdlib.h>
struct node{
    int coeff;
    int exp;
    struct node *next;
};
struct node *insert(struct node *head, int coeff, int exp){
    struct node *newnode;
    struct node *temp;
    if (coeff == 0)
        return head;
    if (head != NULL && head->exp == exp){
        head->coeff += coeff;
        if (head->coeff == 0){
            temp = head;
            head = head->next;
            free(temp);
        }
        return head;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->exp = exp;
    if (head == NULL || exp > head->exp){
        newnode->next = head;
        return newnode;
    }
    temp = head;
    while (temp->next != NULL && temp->next->exp > exp)
        temp = temp->next;
    if (temp->next != NULL && temp->next->exp == exp){
        temp->next->coeff += coeff;
        free(newnode);
        if (temp->next->coeff == 0){
            newnode = temp->next;
            temp->next = newnode->next;
            free(newnode);
        }
    }
    else{
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}
struct node *createPolynomial(){
    struct node *head = NULL;
    int n, i, coeff, exp;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        head = insert(head, coeff, exp);
    }
    return head;
}
struct node *addPolynomial(struct node *p1, struct node *p2){
    struct node *result = NULL;
    while (p1 != NULL){
        result = insert(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL){
        result = insert(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return result;
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
    struct node *p1;
    struct node *p2;
    struct node *result;
    printf("Enter first polynomial\n");
    p1 = createPolynomial();
    printf("\nEnter second polynomial\n");
    p2 = createPolynomial();
    result = addPolynomial(p1, p2);
    printf("\nFirst Polynomial: ");
    display(p1);
    printf("Second Polynomial: ");
    display(p2);
    printf("Result: ");
    display(result);
    return 0;
}
