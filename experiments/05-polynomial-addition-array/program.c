#include <stdio.h>
int main()
{
    int n1, n2, i=0, j=0, k=0, coeff1[20], coeff2[20], exp1[20], exp2[20], coeffsum[40], expsum[40];
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    printf("Enter coefficient and exponent:\n");
    for(i = 0; i < n1; i++)
        scanf("%d %d", &coeff1[i], &exp1[i]);
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);
    printf("Enter coefficient and exponent:\n");
    for(i = 0; i < n2; i++)
        scanf("%d %d", &coeff2[i], &exp2[i]);
    i = j = k = 0;
    while(i < n1 && j < n2)
    {
        if(exp1[i] > exp2[j])
        {
            coeffsum[k] = coeff1[i];
            expsum[k] = exp1[i];
            i++;
            k++;
        }
        else if(exp1[i] < exp2[j])
        {
            coeffsum[k] = coeff2[j];
            expsum[k] = exp2[j];
            j++;
            k++;
        }
        else
        {
            coeffsum[k] = coeff1[i] + coeff2[j];
            expsum[k] = exp1[i];
            i++;
            j++;
            k++;
        }
    }
    while(i < n1)
    {
        coeffsum[k] = coeff1[i];
        expsum[k] = exp1[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        coeffsum[k] = coeff2[j];
        expsum[k] = exp2[j];
        j++;
        k++;
    }
    printf("\nSum of polynomials:\n");
    for(i = 0; i < k; i++)
    {
        printf("%dx^%d", coeffsum[i], expsum[i]);
        if(i < k - 1)
            printf(" + ");
    }
    printf("\n");
    return 0;
}
