#include "day1.h"

List	*ft_lstnew(int num)
{
	List	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->num = num;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(List **list, List *new)
{
	new->next = *list;
	*list = new;
}

List	*ft_lstlast(List *head)
{
	List	*tmp;

	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_back(List **list, List *new)
{
	List	*n;

	if (*list)
	{
		n = ft_lstlast(*list);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*list = new;
		(*list)->next = NULL;
	}
}

int	ft_lstsize(List *head)
{
	size_t	i;
	List	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_lstfree(List **list) {
	List	*tmp;
	List	*head;

	head = *list;
	while (head) {
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	ft_printlst(List *list) {
	List *tmp;

	tmp = list;
	while (tmp) {
		printf("%d\n", tmp->num);
		tmp = tmp->next;
	}
}

void	ft_sortlst(List	*list) {
	List *head;
	List *tmp;
	int size;
	int swap;

	head = list;
	tmp = head;
	size = ft_lstsize(head);
	while (tmp && tmp->next) {
		if (tmp->num > tmp->next->num) {
			swap = tmp->num;
			tmp->num = tmp->next->num;
			tmp->next->num = swap;
			tmp = head;
		}
		else {
			tmp = tmp->next;
		}
	}
}