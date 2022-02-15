/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:33:29 by chilee            #+#    #+#             */
/*   Updated: 2022/02/15 15:04:46 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	nb_int(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	*ft_range(int start, int end)
{
	int i;
	int	*array;
	int	range;
	int n;

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
		array[i] = start;
		start = start + range;
		i++;
	}
	return (array);
 }

#include <stdio.h>
 int	main(void)
 {
	int start = -10 ;
	int end = 10;
	int i;

	int	*array = ft_range(start, end);
	i = 0; 
	while ( i < (nb_int(end-start) + 1))
	{
		printf("%d,", array[i]);
		i++;
	}
	return (0);
 }
