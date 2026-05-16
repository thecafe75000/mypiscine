/*
Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------
Write a function that returns the number of elements in the linked list that's
passed to it.
It must be declared as follows:
int					ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:
typedef struct    s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;
*/
/*
	写一个函数，用来计算一个单向链表里有多少个节点
	从 begin_list 开始，一个节点一个节点沿着 next 往后走，
	每走到一个节点就计数加 1，直到 next 是 NULL，说明链表结束
	例如：
	node1 -> node2 -> node3 -> NULL
	函数应该返回3
*/

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}

#include <stdio.h>

int	main(void)
{
	t_list	one;
	t_list	two;
	t_list	three;
	t_list node4;
	int size;
	int x[] = {123, 222, 333};
	char y[] = "abcdef";
	int z[] = {888, 999};
	int k = 123;

	one.data = x;
	one.next = &two;
	two.data = y;
	two.next = &three;
	three.data = z;
	three.next = &node4;
	node4.data = &k;
	node4.next = NULL;

	size = ft_list_size(&one);
	printf("size = %d\n", size);
	return (0);
}
