/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_if2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:57:27 by chilee            #+#    #+#             */
/*   Updated: 2022/03/03 15:26:00 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

/*
typedef struct s_list
{
	struct s_list *next;
	void		*data;
}		t_list;

int	cmp(void *data, void *data_ref)
{
	if (data == data_ref)
		return (0);
	return (1);
}
*/

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*list;

	while (*begin_list && (cmp((*begin_list)->data, data_ref)==0))
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	list = *begin_list;
	while (list && list->next)
	{
		if (cmp(list->next->data, data_ref)==0)
		{
			tmp = list->next;
			list->next = list->next->next;
			free(tmp);
		}
		else 
			list = list->next;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	int a = 1;
	int b = 6;
	int c = 5;
	t_list	*list;

	list = malloc(sizeof(t_list *));
	list->data = &a;
	list->next = malloc(sizeof(t_list *));
	list->next->data = &b;
	list->next->next = malloc(sizeof(t_list *));
	list->next->next->data = &c;
	list->next->next->next = NULL;
	ft_list_remove_if(&list, &b, cmp);
	while (list)
	{
		printf("%d\n", *(int *)list->data);
		list = list->next;
	}
}*/
