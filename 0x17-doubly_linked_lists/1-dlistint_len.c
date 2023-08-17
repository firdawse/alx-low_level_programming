#include <stdio.h>
#include "lists.h"

/**
 * dlistint_len - print length of a DoublyLinkedList
 * strting with head to tail nodes
 * @h: head of Linked List
 *
 * Return: size of list
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	if (h == NULL)
		return (count);

	while (h->prev != NULL)
		h = h->prev;

	while (h)
	{
		count++;
		h = h->next;
	}

	return (count);
}
