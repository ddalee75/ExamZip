/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:26:32 by chilee            #+#    #+#             */
/*   Updated: 2022/03/04 15:18:33 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*#include "list.h"*/
typedef	struct	s_list
{
	struct s_list *next;
	int			data;
}			t_list;

int 	cmp(int a, int b)
{
	return (a<=b);
}


t_list *sort_list(t_list* lst, int (*cmp)(int, int))
{
	int	swap;
	t_list *start;
	
	start = lst;
	while (lst->next)
	{
		if ((cmp(lst->data, lst->next->data)== 0))
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

#include <stdio.h>
int main (void)
{
	int a= 5;
	int b=3;
	int c = 6;
	int d = 2;
	t_list *list;

	list = malloc(sizeof(t_list *));
	list->data = a;
	list->next = malloc(sizeof(t_list *));
	list->next->data = b;
	list->next->next = malloc(sizeof(t_list *));
	list->next->next->data = c;
	list->next->next->next = malloc(sizeof(t_list *));
	list->next->next->next->data = d;
	list->next->next->next->next = NULL;
	sort_list(list, cmp); 
	while (list)
	{
		printf("%d\n", list->data);
		list = list->next;
	}
	return (0);
	
}
