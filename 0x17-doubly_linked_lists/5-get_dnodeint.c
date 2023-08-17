#include <stdio.h>
#include "lists.h"

/**
 * get_dnodeint_at_index - get node at a specific index
 * @head: head of Linked List
 * @idx: index specified
 *
 * Return: node
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int idx)
{
	int count = 0;

	if (head == NULL)
		return (NULL);

	while (head)
	{
		if (idx == count)
			return (head);
		head = head->next;
		count++;
	}

	return (NULL);
}
