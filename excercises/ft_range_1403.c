/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range_1403.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:29:11 by chilee            #+#    #+#             */
/*   Updated: 2022/03/14 14:45:05 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_abso(int nb)
{
	if (nb < 0)
		nb = nb *-1;
	return (nb);
}

int *ft_range(int start, int end)
{
	int i=0;
	int range =1;
	int *arr;
	int len = ft_abso(end - start) + 1;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (0);
	if (end > start)
		range = 1;
	else
		range = -1;
	while (i < len)
	{
		arr[i] = start;
	 	start = start + range;
   		i++;	   
	}
	return (arr);	
}

#include <stdio.h>
int main(void)
{
	int start = 0;
	int end = 0;
	int *arr = ft_range(start, end);
	int i = 0;
	while ( i < (ft_abso(end - start) + 1))
	{
		printf("%d, ", arr[i]);
		i++;
	}
	return (0);

}

