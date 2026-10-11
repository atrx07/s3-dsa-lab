#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100

int main()
{
    char *hashTable[SIZE];
    char *dictionary[] = {"apple", "banana", "grape", "orange", "melon"};
    char input[50];
    int i, j, sum, index;

    for (i = 0; i < SIZE; i++)
    {
        hashTable[i] = NULL;
    }

    for (i = 0; i < 5; i++)
    {
        sum = 0;
        for (j = 0; dictionary[i][j] != '\0'; j++)
        {
            sum = sum + dictionary[i][j];
        }

        index = sum % SIZE;
        hashTable[index] = (char *)malloc(strlen(dictionary[i]) + 1);
        strcpy(hashTable[index], dictionary[i]);
    }

    printf("Enter a word to check: ");
    scanf("%s", input);

    sum = 0;
    for (i = 0; input[i] != '\0'; i++)
    {
        sum = sum + input[i];
    }

    index = sum % SIZE;

    if (hashTable[index] != NULL && strcmp(hashTable[index], input) == 0)
    {
        printf("The word is spelled correctly.\n");
    }
    else
    {
        printf("The word is not found in the dictionary.\n");
        printf("Suggestions:\n");

        for (i = 0; i < SIZE; i++)
        {
            if (hashTable[i] != NULL && hashTable[i][0] == input[0])
            {
                printf("%s\n", hashTable[i]);
            }
        }
    }

    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i] != NULL)
            free(hashTable[i]);
    }

    return 0;
}
