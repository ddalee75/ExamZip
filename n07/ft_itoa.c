/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:37:20 by chilee            #+#    #+#             */
/*   Updated: 2022/02/14 15:33:54 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
//#include <stdio.h>

size_t	count_int(int nb)
{
	size_t count;

	count = 1;
	if (nb < 0)
		count++;
	while (nb / 10)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	size_t			len;
	char			*dest;		
	unsigned int	num; 

	len = count_int(nbr);
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	if (nbr == 0) 
		dest[0] = '0';
	if (nbr < 0)
	{
		num = nbr * -1;  
		dest[0] = '-';
	 }
	 else 
		 num = nbr;
	while (num > 0)
	{
		dest[len - 1] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (dest);
}
/*
int	main(void)
{
	int n;

	n = -2147483648;
	printf("%s", ft_itoa(n));
	return (0);
}
*/
