/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:19:19 by chilee            #+#    #+#             */
/*   Updated: 2022/02/22 11:37:17 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_count(int nb)
{
	int count;

	count = 1;
	if (nb < 0)
		count ++; 
	while (nb / 10)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

char *ft_itoa(int nbr)
{
	unsigned int n;
	int	 len;
	char *dest;

	len = ft_count(nbr);
	dest = malloc(sizeof(int) * len);
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	if (nbr < 0)
	{
		dest[0] = '-';
		n = -nbr;
	}
	else 
		n = nbr;
	while (n > 0)
	{
		dest[len -1] = n % 10 + '0'; 
		n = n / 10;
		len--;
	}
	return (dest);
}

#include <stdio.h>
int main(void)
{
	char *arr;

	arr = ft_itoa(2147483647);
	printf ("%s\n", arr);
	return (0);

}
