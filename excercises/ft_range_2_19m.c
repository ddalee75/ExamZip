/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:39:34 by chilee            #+#    #+#             */
/*   Updated: 2022/02/18 12:12:42 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_absolu_nb(int c)
{
	if ( c < 0)
		c = c * -1;
	return (c);
}

int	*ft_range(int start, int end)
{
	int	*dest;
	int i;
	int range;
	int len;

	i = 0;
	len = ft_absolu_nb(end - start) + 1;
	dest = malloc(sizeof(int) * len);
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	if (end > start) 
		range = 1;
	else 
		range = -1;
	while (i < len)
	{
		dest[i] = start;
		i++;
		start = start + range;
	}
	return (dest);
}

/*
#include <stdio.h>
int main(void)
{
	int i;
	int *array;
	int	start = -1;
	int	end = 2;
	int n;

	array = ft_range(start, end);
	i = 0;
	n = ft_absolu_nb(end - start) + 1;
	while (i < n)
	{
		printf("%d, ", array[i]);	
		i++; 
	}
	 return (0);
}*/
