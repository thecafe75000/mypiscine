/*
Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions:
--------------------------------------------------------------------------------
Write the following functions:
t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.
Duplications must remain.
Inputs will always be consistent.
You must use the type t_list described in the file list.h
that is provided to you. You must include that file(#include "list.h"),
but you must not turn it in. We will use our own to compile your assignment.

Functions passed as cmp will always return a value different from
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list
in ascending order:
int	ascending(int a, int b)
{
	return (a <= b);
}
*/
/*
	实现题目要求的函数，这个函数的作用：
		把一个链表按指定规则排序，然后返回排序后链表的第一个节点
		lst 是链表头指针
		cmp 是一个函数指针，用来判断两个整数的顺序是否正确 cmp(a, b)
			如果 a 和 b 的顺序是对的，返回非 0；如果顺序不对，返回 0

*/

#include "sort_list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*head;
	t_list	*current;
	int		temp;

	head = lst;
	while (lst)
	{
		current = head;
		while (current && current->next)
		{
			if (cmp(current->data, current->next->data) == 0)
			{
				temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;
			}
			current = current->next;
		}
		lst = lst->next;
	}
	return (head);
}

#include <stdio.h>
#include <stdlib.h>

t_list	*sort_list(t_list *lst, int (*cmp)(int, int));

int	ascending(int a, int b)
{
	return (a <= b);
}

int	descending(int a, int b)
{
	return (a >= b);
}

t_list	*new_node(int data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	push_back(t_list **lst, int data)
{
	t_list	*node;
	t_list	*cur;

	node = new_node(data);
	if (!node)
		return ;
	if (!*lst)
	{
		*lst = node;
		return ;
	}
	cur = *lst;
	while (cur->next)
		cur = cur->next;
	cur->next = node;
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d", lst->data);
		if (lst->next)
			printf(" -> ");
		lst = lst->next;
	}
	printf("\n");
}

void	free_list(t_list *lst)
{
	t_list	*next;

	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
}

int	main(void)
{
	t_list	*lst;

	lst = NULL;
	push_back(&lst, 4);
	push_back(&lst, 2);
	push_back(&lst, 7);
	push_back(&lst, 1);
	push_back(&lst, 2);
	printf("Original:   ");
	print_list(lst);
	lst = sort_list(lst, ascending);
	printf("Ascending:  ");
	print_list(lst);
	lst = sort_list(lst, descending);
	printf("Descending: ");
	print_list(lst);
	free_list(lst);
	return (0);
}
