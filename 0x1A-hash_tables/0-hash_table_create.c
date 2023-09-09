#include "hash_tables.h"


/**
 * hash_table_create - function to create a new hash table
 * @size: size of the array
 *
 * Return: pointer to th ehash table or NULL
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_table;
	unsigned long int i;

	/* Verify the size*/
	if (size < 1)
		return (NULL);

	/*allocate memory*/	
	new_table = malloc(sizeof(hash_table_t));
	if (new_table == NULL)
		return (NULL);

	new_table->size = size;
	new_table->array = malloc(sizeof(hash_node_t *) * size);
	if (new_table->array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		new_table->array[i] = NULL;

	return (new_table);
}
