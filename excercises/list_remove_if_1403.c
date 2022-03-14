/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_if_1403.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:14:12 by chilee            #+#    #+#             */
/*   Updated: 2022/03/14 16:28:49 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include "ft_list.h"

typedef	struct s_list
{
	struct s_list *next;
	void		*data;
}	t_list;

int	cmp(void *data, void *data_ref)
{
	if (data == data_ref)
		return (0);
	else
		return (1);

}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*list;

	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
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

