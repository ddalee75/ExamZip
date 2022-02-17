/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:03:07 by chilee            #+#    #+#             */
/*   Updated: 2022/02/17 20:08:04 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len_need(int start, int end)
{
	int	len;
	
	if (end < start)
		len = -(end - start) + 1;
	else if (start == end)
		len = 1;
	else 
		len = end - start + 1;
	return (len);
}

int	*ft_range(int start, int end)
{
	int	n;
	int	*dest;
	int	range;
	int i;

	n = ft_len_need(start, end);
	dest = malloc(sizeof(int) * n);
	if (!dest)
		return (0);
	if (end == start)
		dest[0] = start;
	if (end > start)
		range = 1;
	if (end < start)
		range = -1;
	i = 0;
	while (i < n)
	{
		dest[i] = start;
		start = start + range;
		i++;
	}
	return (dest);
}

#include <stdio.h>
int	main(void)
{
	int start = 1;
	int	end = 7;
	int	i;
	int *array = ft_range(start, end);
	i =0;
	int l = ft_len_need(start, end);	
	while (i < l)
	{
		printf("%d, ", array[i]);
		i++;
	}
	return(0);
}
