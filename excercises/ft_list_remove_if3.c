/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:05:59 by chilee            #+#    #+#             */
/*   Updated: 2022/03/07 14:08:14 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include "ft_list.h"
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

int	cmp(void *data, void *data_ref)
{
	if(data == data_ref)
		return(0);
	return (1);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*start;

	while(*begin_list && cmp((*begin_list)->data, data_ref)==0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	start = *begin_list;
	while (start && start->next)
	{
		if (cmp(start->next->data, data_ref)==0)
		{
			tmp = start->next;
			start->next = start->next->next;
			free(tmp);
		}
		else
			start=start->next;
	}
}
