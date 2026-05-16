// 链表结构体的定义和函数声明
#ifndef FT_LIST_H
#define FT_LIST_H

typedef struct    s_list
{
	struct s_list	*next;
	void	*data;
}	t_list;

int ft_list_size(t_list *begin_list);

#endif
