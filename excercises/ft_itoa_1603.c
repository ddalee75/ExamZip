/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_1603.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:28:22 by chilee            #+#    #+#             */
/*   Updated: 2022/03/16 16:51:07 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_count(int n)
{
	int count = 1;
	if ( n< 0)
		count++;
	while (n/10)
	{
		n =  n/10;
		count++;
	}
	return (count);
}

char *ft_itoa(int nbr)
{
	char *dest;
	int len = ft_count(nbr);
	unsigned int n;
	//n = 0;

	dest =  malloc(sizeof(char) * len +1);
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	if (nbr == 0)
	{
		dest[0] = '0'; 
	}
	if (nbr < 0)
	{
		dest[0] = '-';
		n = nbr * -1;
	}
	else
		n = nbr;
	while (n > 0)
	{
		dest[len -1] = n % 10 + '0';
		len--;
		n = n / 10;
	}
	return (dest);
}


#include <stdio.h>
int main(void)
{
	int s = 0 ; 
	char *arr ;
	arr = ft_itoa(s);
	printf("%s\n", arr);
}
