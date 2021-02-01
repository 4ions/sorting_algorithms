#include "sort.h"

/**
 *swap - swap nodes
 *@prev: prev node
 *@current: current node
 *
 *Return: no return
 */
void swap(listint_t *prev, listint_t *current)
{
	if (prev->prev)
		prev->prev->next = current;
	if (current->next)
		current->next->prev = prev;
	prev->next = current->next;
	current->prev = prev->prev;
	prev->prev = current;
	current->next = prev;

}

/**
 *insertion_sort_list - insert a node into list
 *@list: list to insert node
 *
 *Return: no return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *current, *prev;

	if (!list || !*list || !(*list)->next)/**0(1)*/
		return;
	head = (*list)->next;/**0(1)*/
	while (head)/**0(n)*/
	{
		prev = current = head;/**0(n)*/
		while (current && prev->prev)/**0(n^2)*/
		{
			if (prev->prev->n > current->n)/**0(n^2)*/
			{
				swap(prev->prev, current);/**0(n^2)*/
				if (!prev->prev)/**0(n^2)*/
					*list = current;/**0(n^2)*/
				print_list((const listint_t *)*list);/**0(n^2)*/

			}
			else/**0(n^2)*/
			{
				prev = prev->prev;/**0(n^2)*/
			}

		}
		head = head->next;/**0(n)*/
	}
}
