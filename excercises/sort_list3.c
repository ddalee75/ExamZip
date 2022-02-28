/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:30:25 by chilee            #+#    #+#             */
/*   Updated: 2022/02/28 14:49:13 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

//#include "list.h"


typedef struct 		s_list
{
	struct s_list			*next;
	int				data;
}			t_list;

int	cmp(int a, int b)
{
	return (a <= b);
}

t_list	*sort_list(t_list *lst, int(*cmp)(int, int))
{
	int	swap;
	t_list	*start;

	start =  lst;
	while (lst->next)
	{
		if (cmp(lst->data, lst->next->data) == 0)
		{
			swap = lst->data;
			lst->data =  lst->next->data;
			lst->next->data = swap;
			lst = start;
		}
		else
			lst = lst->next;
	}
	return (start);
}

/*
int	main(void)
{
	t_list *list;
	int	a=2;
	int b=10;
	int c=6;
	int d=4;

	list = malloc(sizeof(t_list));
	list->data = a;
	list->next =malloc(sizeof(t_list));
	list->next->data = b;
	list->next->next = malloc(sizeof(t_list));
	list->next->next->data = c;
	list->next->next->next = malloc(sizeof(t_list));
	list->next->next->next->data = d;
	list->next->next->next->next = NULL;
	sort_list(list,cmp);
	while (list)
	{
		printf("%d\n", list->data);
		list = list->next;
	}
	return (0);
}*/
