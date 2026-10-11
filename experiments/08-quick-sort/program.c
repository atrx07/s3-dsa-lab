#include <stdio.h>

void quickSort(int A[], int low, int high)
{
    int i, j, pivot, temp;

    if (low >= high)
        return;

    i = low;
    j = high;
    pivot = A[(low + high) / 2];

    while (i <= j)
    {
        while (A[i] < pivot)
            i++;
        while (A[j] > pivot)
            j--;

        if (i <= j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
    }

    if (low < j)
        quickSort(A, low, j);
    if (i < high)
        quickSort(A, i, high);
}

int main()
{
    int A[100], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    quickSort(A, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}
