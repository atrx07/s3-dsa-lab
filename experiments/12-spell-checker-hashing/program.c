#include <stdio.h>
#include <string.h>

#define SIZE 100

int hash(char word[])
{
    int i, sum = 0;

    for (i = 0; word[i] != '\0'; i++)
        sum += word[i];

    return sum % SIZE;
}

int main()
{
    char *hashTable[SIZE] = {NULL};
    char *dictionary[] = {"apple", "banana", "grape", "orange", "melon"};
    char input[50];
    int i, index;

    for (i = 0; i < 5; i++)
        hashTable[hash(dictionary[i])] = dictionary[i];

    printf("Enter a word to check: ");
    scanf("%s", input);

    index = hash(input);

    if (hashTable[index] != NULL && strcmp(hashTable[index], input) == 0)
        printf("The word is spelled correctly.\n");
    else
    {
        printf("The word is not found in the dictionary.\n");
        printf("Suggestions:\n");

        for (i = 0; i < SIZE; i++)
        {
            if (hashTable[i] != NULL && hashTable[i][0] == input[0])
                printf("%s\n", hashTable[i]);
        }
    }

    return 0;
}