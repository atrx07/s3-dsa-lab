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
    int found = 0;

    /* Step 3: Initialize hash table */
    for (i = 0; i < SIZE; i++)
    {
        hashTable[i] = NULL;
    }

    /* Step 4: Insert dictionary words */
    for (i = 0; i < 5; i++)
    {
        sum = 0;

        /* Calculate sum of ASCII values */
        for (j = 0; dictionary[i][j] != '\0'; j++)
        {
            sum = sum + dictionary[i][j];
        }

        /* Calculate hash index */
        index = sum % SIZE;

        /* Store a copy of the word */
        hashTable[index] = (char *)malloc(strlen(dictionary[i]) + 1);
        strcpy(hashTable[index], dictionary[i]);
    }

    /* Step 9: Accept word from user */
    printf("Enter a word to check: ");
    scanf("%s", input);

    /* Step 10: Set sum = 0 */
    sum = 0;

    /* Step 11: Calculate ASCII sum */
    for (i = 0; input[i] != '\0'; i++)
    {
        sum = sum + input[i];
    }

    /* Step 12: Calculate index */
    index = sum % SIZE;

    /* Step 13: Check the word */
    if (hashTable[index] != NULL &&
        strcmp(hashTable[index], input) == 0)
    {
        printf("The word is spelled correctly.\n");
        found = 1;
    }
    else
    {
        /* Step 14 */
        printf("The word is not found in the dictionary.\n");

        printf("Suggestions:\n");

        /* Check every entry in hash table */
        for (i = 0; i < SIZE; i++)
        {
            if (hashTable[i] != NULL &&
                hashTable[i][0] == input[0])
            {
                printf("%s\n", hashTable[i]);
            }
        }
    }

    /* Free allocated memory */
    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i] != NULL)
            free(hashTable[i]);
    }

    return 0;
}
