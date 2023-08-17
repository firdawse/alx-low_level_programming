#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a  index.
 * @h: Pointer to a pointer to the head node.
 * @idx: Index of the node to be deleted.
 *
 * Return: 1 if successful, -1 otherwise.
 */
int delete_dnodeint_at_index(dlistint_t **h, unsigned int idx)
{
    unsigned int count = 0;
    dlistint_t *head;

    if (*h == NULL)
        return (-1);

    head = *h;

    if (idx == 0)
    {
        *h = head->next;
        free(head);
        if (*h != NULL)
        {
            (*h)->prev = NULL;
            return (1);
        }
    }
    else
    {
        while (head->prev != NULL)
            head = head->prev;
        
        while (head)
        {
            if (idx == count)
            {
                if (head->next == NULL)
                {
                    free(head);
                    head = NULL;
                }
                else
                {
                    head->prev->next = head->next;
                    head->next->prev = head->prev;
                    free(head);
                    head = NULL;
                }
                return (1);
                break;
            }
            count++;
            head = head->next;
        }
    }
    return (-1);
}

