/*
Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------
Write a function that returns the number of elements in the linked list that's
passed to it.
It must be declared as follows:
int	ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:
typedef struct    s_list
{
	struct s_list	*next;
	void	*data;
}	t_list;


	写一个函数，用来计算一个单向链表里有多少个节点
	从 begin_list 开始，一个节点一个节点沿着 next 往后走，
	每走到一个节点就计数加 1，直到 next 是 NULL，说明链表结束
	例如：
	node1 -> node2 -> node3 -> NULL
	函数应该返回3

	一个节点本质上需要保存两部分：
		1 当前节点的数据
		2 指向下一个节点的指针

	最经典的写法：
		typedef struct s_node
		{
			int				data;
			struct s_node	*next;
		}	t_node;
	其中：
		data：保存当前节点的数据（这里是 int，也可以换成别的类型）
		next：是一个指针，指向“下一个节点”
	为什么 next 要写成 struct s_node *？
		因为 struct s_node 代表“节点类型本身”
		struct s_node	*next; 意思是 next 是一个指针，指向另一个同类型节点
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
#include <stdlib.h>

int	main(void)
{
	t_list	*one;
	t_list	*two;
	t_list	*three;
	int		size;

	// 创建节点
	one = malloc(sizeof(t_list));
	two = malloc(sizeof(t_list));
	three = malloc(sizeof(t_list));

	// 给节点赋值
	int a = 10;
	int b = 20;
	int c = 30;
	one->data = &a;
	two->data = &b;
	three->data = &c;
	// 连接节点
	one->next = two;
	two->next = three;
	three->next = NULL;
	size = ft_list_size(one);
	printf("size = %d\n", size);
	// 释放内存
	free(one);
	free(two);
	free(three);
	return (0);
}
