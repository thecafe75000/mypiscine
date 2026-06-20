/*
Assignment name  : ft_list_foreach
Expected files   : ft_list_foreach.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------
Write a function that takes a list and a function pointer, and applies this
function to each element of the list.

It must be declared as follows:
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));

The function pointed to by f will be used as follows:
(*f)(list_ptr->data);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;
*/

/*
	实现一个链表遍历函数：
	给你一个链表头节点和一个函数指针，你要从头到尾访问链表的每个节点，
	并把每个节点里的 data 传给这个函数执行一次
	注意：这题不要求创建链表、不要求释放链表、不要求修改链表结构，
			只要求遍历链表并对每个节点的 data 调用函数 f
	可以把这题当成：
		你已经有一串链表节点，现在要写一个“遍历器”，它不关心数据具体是什么，
		只负责把每个节点的数据交给别人处理

	按“从 0 开始写出完整程序”的方式解释这题怎么想、怎么拆、为什么这样构思
*/

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

#include <stdio.h>

void	print_str(void *data)
{
	printf("%s\n", (char *)data);
}

int	main(void)
{
	t_list node3 = {NULL, "third"};
	t_list node2 = {&node3, "second"};
	t_list node1 = {&node2, "first"};

	ft_list_foreach(&node1, print_str);
	return (0);
}
