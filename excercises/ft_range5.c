/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:34:17 by chilee            #+#    #+#             */
/*   Updated: 2022/03/07 17:59:43 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_abs(int nb)
{
	if (nb <0)
		nb = nb *-1;
	return (nb);
}

int 	*ft_range(int start, int end)
{
	int len;
	int i;
	int range;
	int *dest;
	len = ft_abs(end - start) + 1;
	dest = malloc(sizeof(int) * len);
	if (!dest)
		return (0);
	if (end > start)
		range = 1;
	else 
		range = -1;
	i = 0;
	while (i < len)
	{
		dest[i] = start;
		start = start + range;
		i++;
	}
	return (dest);
}
#include <stdio.h>
int main(void)
{
	int start = 3;
	int end =1;
	int *arr;
	arr = ft_range(start, end);
	int i = 0;
	while (i < (ft_abs(end-start) + 1))
	{
		printf("%d, ", arr[i]);
		i++; 	
	}
}
