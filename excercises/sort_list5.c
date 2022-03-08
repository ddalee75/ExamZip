/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:53:56 by chilee            #+#    #+#             */
/*   Updated: 2022/03/07 13:02:30 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"
/*
typedef	struct	s_list
{
	struct s_list	*next;
	int				data;
}		t_list;


int cmp(int a, int b)
{
	return (a <= b);
}
*/

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int	swap;
	t_list	*start;

	start=lst;
	while (lst->next)
	{
		if(cmp(lst->data,lst->next->data)==0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = start;
		}
		else
			lst=lst->next;
	}
	return (start);
}
