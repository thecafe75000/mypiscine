/*
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------
Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:
$>cat ft_list.h
typedef struct      s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;
$>
*/
/*
	按“从 0 开始写出完整程序”的方式解释这题怎么想、怎么拆、为什么这样构思

	写一个函数用来从链表中删除所有符合条件的节点
	函数要做的事是：遍历整个链表，如果某个节点的 data 和 data_ref 被认为“相等”，
	就把这个节点从链表中删除，并用 free 释放这个节点本身
	判断是否相等不是用 ==，而是用传进来的比较函数 cmp

	需要注意的要求：
		只能提交文件 ft_list_remove_if.c
		只能使用函数 free
		需要包含或使用 ft_list.h 里的 t_list 结构
		要删除所有匹配的节点，不是只删第一个
		如果链表开头的节点也匹配，也要正确删除
		删除节点时只 free 节点本身，不要 free(data)，因为题目没有要求释放数据内容

*/

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *))
{
	t_list	*temp;

	if (!begin_list || !*begin_list)
		return ;
	if (cmp((*begin_list)->data, data_ref) == 0)
	{
		temp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(temp);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
		ft_list_remove_if(&(*begin_list)->next, data_ref, cmp);
}

#include <stdio.h>
#include <string.h>

// 创建新节点
t_list	*new_node(void *data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

// 比较字符串
// strcmp是来自string.h的C库函数
int	cmp_str(void *a, void *b)
{
	return (strcmp((char *)a, (char *)b));
}

// 打印链表
void	print_list(t_list *head)
{
	while (head)
	{
		printf("%s\n", (char *)head->data);
		head = head->next;
	}
}
int	main(void)
{
	t_list *head; // head 不是节点本身，它是指向第一个节点的指针

	head = new_node("apple");
	head->next = new_node("banana");
	head->next->next = new_node("cherry");
	head->next->next->next = new_node("orange");
	printf("Before:\n");
	print_list(head);
	ft_list_remove_if(&head, "cherry", cmp_str);
	printf("\n");
	printf("After:\n");
	print_list(head);
	return (0);
}
