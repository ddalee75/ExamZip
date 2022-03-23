/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_1703.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:39:45 by chilee            #+#    #+#             */
/*   Updated: 2022/03/17 16:02:01 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_count(int n)
{
	int count = 1;
	if (n < 0)
		count++;
	while (n /10)
	{
		n=n/10;
		count ++;
	}
	return (count);
}

char *ft_itoa(int nbr)
{
	unsigned int n = 0;
	char *dest;
	int len = ft_count(nbr);
		
	dest = malloc(sizeof(char) * len +1);
	if (!dest)
		return (0);
	dest[len] = '\0';
	if (nbr == 0)
	{
		dest[0] = '0';
	}
	else if (nbr < 0)
	{
		dest[0] = '-';
		n = nbr * -1;
	}
	else
		n = nbr;
	while (n>0)
	{
		dest[len -1] = n % 10 + '0';
		n = n/10;
		len--;
	}
	return (dest);
}

#include <stdio.h>
int main(void)
{
	int n = -42;
	
	printf("%s\n", ft_itoa(n));

	
}
