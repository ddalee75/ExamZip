/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rragne.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:10:35 by chilee            #+#    #+#             */
/*   Updated: 2022/02/15 15:35:40 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	nb_int(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	*ft_rrange(int start, int end)
{
	int	i;
	int	range;
	int	n;
	int *array;

	n = 1 + nb_int(end - start);
	array = (int *)malloc(sizeof(int) * n);
	if (!array)
		return (NULL);
	if (end > start)
		range = 1;
	else
		range = -1;
	i = 0;
	while (i < n) 
	{
		array[i] = end; 
		end = end - range;
		i++;
	} 
	return (array);
}
/*
#include <stdio.h>
int	main(void)
{
	int i;
	int *array;
	int start;
	int end;

	start = 5;
	end = 5;

	i = 0;
	array = ft_rrange(start, end);
	while (i < nb_int(end - start) + 1)
	{
		printf("%d, ", array[i]);
		i++;
	}
	return (0);
}*/
