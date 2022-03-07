/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range4_15m.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:21:41 by chilee            #+#    #+#             */
/*   Updated: 2022/03/03 14:15:28 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_absolu(int nb)
{
	if(nb <0) 
	{
		nb = nb * -1;
	}
	return (nb);
}
int *ft_range(int start, int end)
{
	int *dest;
	int rang;
	int len;
	int i=0;

	len = ft_absolu(end - start) + 1;
	dest=malloc(sizeof(int) * len);
	if (!dest)
		return (0);
	if (end >start)
		rang = 1;
	else
		rang = -1;
	while (i < len)
	{
		dest[i] = start;
		start = start + rang;
		i++;
	}
	return (dest);
}


#include <stdio.h>
int main(void)
{
	int i = 0;
	int start = 0;
	int end = 0;
	int *arr = ft_range(start, end);
	while (i < (ft_absolu(end -start) + 1))
	{
		printf("%d,", arr[i]);
		i++;
	}

}
