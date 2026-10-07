#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100003
#define MAX_LEN 21

typedef struct Node
{
    char word[MAX_LEN];
    int count;
    struct Node *next;
} Node;

Node *table[TABLE_SIZE];

unsigned long hashFunction(char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % TABLE_SIZE;
}

void insert(char *word)
{
    unsigned long index = hashFunction(word);

    Node *current = table[index];

    while (current != NULL)
    {
        if (strcmp(current->word, word) == 0)
        {
            current->count++;
            return;
        }

        current = current->next;
    }

    Node *newNode = malloc(sizeof(Node));

    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->next = table[index];

    table[index] = newNode;
}

int search(char *word)
{
    unsigned long index = hashFunction(word);

    Node *current = table[index];

    while (current != NULL)
    {
        if (strcmp(current->word, word) == 0)
        {
            return current->count;
        }

        current = current->next;
    }

    return 0;
}

void freeTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node *current = table[i];

        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        char word[MAX_LEN];

        scanf("%20s", word);
        insert(word);
    }

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++)
    {
        char query[MAX_LEN];

        scanf("%20s", query);
        printf("%d\n", search(query));
    }

    freeTable();

    return 0;
}
