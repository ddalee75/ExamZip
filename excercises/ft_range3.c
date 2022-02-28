/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:24:38 by chilee            #+#    #+#             */
/*   Updated: 2022/02/28 17:57:33 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int absolu(int n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}

int *ft_range(int start, int end)
{
	int range;
	int i;
	int len;
	int *dest;

	i = 0;
	len = absolu(end - start) + 1; 
	dest = malloc(sizeof(int) * len);
	if (!dest)
		return(NULL);
	if (end > start)
		range = 1;
	else 
		range = -1;
	while (i <= len)
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
	int i = 0;
	int start = 0;
	int end = -3;
	int  *s;
	s = ft_range(start,end);
	while (i < (absolu(end-start) +1))
	{
		printf("%d,", s[i]);
		i++;
	}
		return (0);
}
