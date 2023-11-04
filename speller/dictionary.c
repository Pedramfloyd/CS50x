#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

#define HASHTABLE_SIZE 150000

// Represents a node in a hash table2
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

node *hashtable[HASHTABLE_SIZE];

// Hashes word to a number //
// https://gist.github.com/srushtikanade/b0612f537a15e1265f624dd2d946a917?permalink_comment_id=3837604(sourcd of hash func)
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *word++))
    {
        if (isupper(c))
        {
            c = c + 32;
        }
        hash = ((hash << 5) + hash) + c;
    }

    return hash % HASHTABLE_SIZE;
}

int word_count = 0;

bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            unload();
            fclose(file);
            return false;
        }

        strcpy(new_node->word, word);

        int h = hash(word);
        new_node->next = hashtable[h];
        hashtable[h] = new_node;

        word_count++;
    }
    fclose(file);
    return true;
}

bool check(const char *word)
{
    int h = hash(word);

    node *cursor = hashtable[h];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {

            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

unsigned int size(void)
{

    return word_count;
}

bool unload(void)
{
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        node *cursor = hashtable[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
