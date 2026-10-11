#include <stdio.h>

int main()
{
    int arr[100], n, key, i;
    int low = 0, high, mid;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the item to search: ");
    scanf("%d", &key);

    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            printf("Item found at position: %d\n", mid + 1);
            printf("Index: %d\n", mid);
            return 0;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Item not found.\n");
    return 0;
}