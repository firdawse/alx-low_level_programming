#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: Pointer to a pointer to the head node.
 * @idx: Index where the new node should be added. Index starts at 0.
 * @n: Value to be stored in the new node.
 *
 * Return: Address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    unsigned int count = 0;
    dlistint_t *new_node = NULL, *current;

    if (h == NULL)
        return (NULL);

    current = *h;

    while (current)
    {
        if (idx == count)
        {
            if (current->prev == NULL)
                new_node = add_dnodeint(h, n);
            else if (current->next == NULL)
                new_node = add_dnodeint_end(h, n);
            else
            {
                new_node = malloc(sizeof(dlistint_t));
                if (new_node != NULL)
                {
                    new_node->n = n;
                    new_node->prev = current->prev;
                    new_node->next = current;
                    current->prev->next = new_node;
                    current->prev = new_node;
                }
            }
            break;
        }
        count++;
        current = current->next;
    }
    return (new_node);
}

