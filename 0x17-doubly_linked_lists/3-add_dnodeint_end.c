#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - add node to end
 * @head: head of Double Linked List
 * @n: int value of the new node to add
 *
 * Return: head node of list
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *node = (dlistint_t *) malloc(sizeof(dlistint_t));
	dlistint_t *tail;

	if (node == NULL)
		return (NULL);

	node->n = n;
	node->next = NULL;
	tail = *head;

	if (tail != NULL)
	{
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = node;
	}

	if (tail == NULL)
		*head = node;

	node->prev = tail;

	return (node);
}
