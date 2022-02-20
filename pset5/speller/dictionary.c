// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 5381;
//keep track of the number of words
unsigned long S = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int index = hash(word);
    node *temp = table[index];
    while (temp != NULL)
    {
        if (strcasecmp(word, temp->word) == 0)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Hashes word to a number
    // Source: djib2 by Dan Bernstein (http://www.cse.yorku.ca/~oz/hash.html)
    unsigned long hashcon = 5381;
    int c;
    while ((c = tolower(*word++)) != 0)
    {
        hashcon = ((hashcon << 5) + hashcon) + c;
    }
    return hashcon % N;
    
}


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        fprintf(stderr, "can't open dictionary");
        return 1;
    }
    // alocate memory for the word that will be taken from dictionary
    char *dword = malloc(sizeof(char) * (LENGTH + 1));
    if (dword == NULL)
    {
        fprintf(stderr, "can't allocat memory for word");
        return 2;
    }

    // take a word from dictionary and load it
    while (fscanf(dict, "%s", dword) != EOF)
    {

        //malloc a node for new word and copy word into it
        node *n = malloc(sizeof(node));
        if (n != NULL)
        {
            strcpy(n->word, dword);

            int index = hash(dword);
            //putting the new word in fornt of the linked list
            n->next = table[index];
            table[index] = n;
            //keep track of the number of word
            S += 1;
        }

    }
    fclose(dict);
    free(dword);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return S;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int index = 0; index < N; index++)
    {
        while (table[index] != NULL)
        {
            node *temp = table[index]->next;
            free(table[index]);
            table[index] = temp;
        }
    }
    return true;
}
