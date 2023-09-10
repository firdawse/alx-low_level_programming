#include "hash_tables.h"

/**
 * hash_table_set - adds new element to the hash table
 * @ht: tha main hash table
 * @key: key to add
 * @value: value to add 
 *
 * Return: 1 if succes 0 otherwise 
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node, *temp;

	/*failure*/
	if ((!key) || (key[0] == '\0') || (!ht))
		return (0);

	/* where this key-value pair should be stored */
	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];
	while (temp != NULL)
	{
		if (strcmp(key, temp->key) == 0)
		{
			free(temp->value);
			/*assigns the new value*/
			temp->value = strdup(value);
			return (1);
		}
		temp = temp->next;
	}

	/* create new node for key and value*/
	node = malloc(sizeof(hash_node_t));
	if (!node)
		return (0);
	node->key = strdup(key);
	if (value == NULL)
		node->value = NULL;
	else
		node->value = strdup(value);
	node->next = NULL;

	/* check place of index if empty*/
	if (ht->array[index] == NULL)
		ht->array[index] = node;
	else
	{
		node->next = ht->array[index];
		ht->array[index] = node;
	}

	return (1);
}
