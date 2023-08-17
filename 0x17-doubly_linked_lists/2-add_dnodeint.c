#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint - add a new node at the beginning
 * @head: head of Linked List
 * @n: int value of the new node 
 *
 * Return: pointer to head node ofthe list
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *node = malloc(sizeof(dlistint_t));
	dlistint_t *h;

	if (node == NULL)
		return (NULL);

	node->n = n;
	node->prev = NULL;
	h = *head;


	while (h->prev != NULL)
		h = h->prev;

	node->next = h;

	if (h != NULL)
		h->prev = node;

	*head = node;

	return (node);
}
