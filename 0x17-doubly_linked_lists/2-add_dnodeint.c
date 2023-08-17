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
    dlistint_t *new_node;
    new_node = malloc(sizeof(dlistint_t)); 
    if (!head) 
        return (NULL);

    
    if (!new_node)
        return (NULL);

    new_node->n = n; 
    new_node->prev = NULL; 
    new_node->next = *head; 

    if (*head) 
        (*head)->prev = new_node;

    *head = new_node; 
    return (new_node);
}
