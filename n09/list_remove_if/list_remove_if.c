/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_if.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:09:23 by chilee            #+#    #+#             */
/*   Updated: 2022/02/22 19:51:26 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int(*cmp)())
{
	t_list	*list;
	t_list	*tmp;

	while (*begin_list && (cmp((*begin_list)->data, data_ref) == 0))
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	list = *begin_list;
	while (list && list->next)
	{
		if (cmp(list->next->data, data_ref) == 0)
		{
			tmp = list->next;
			list->next = list->next->next;
			free(tmp);
		}
		else
			list = list->next;
	}
}
