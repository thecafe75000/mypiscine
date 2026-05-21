#ifndef FT_LIST_H
#define FT_LIST_H

// 这是一个链表结构
// 链表里每个节点有两个成员：data是节点保存的数据，next指向下一个节点
typedef struct s_list
{
    struct s_list   *next;
    void            *data;
} t_list;

#endif
