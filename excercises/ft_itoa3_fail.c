/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:16:43 by chilee            #+#    #+#             */
/*   Updated: 2022/02/18 12:53:24 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_count(int n)
{
	int	count;

	count = 1;
	if (n < 0)
		count++;
	while (n / 10)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	char *dest;
	int	len;
	unsigned int n;

	len =  ft_count(nbr);
	dest =  malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	if (nbr < 0)
	{
		n = -nbr;
		dest[0] = '-'; 
	}
	else
		n = nbr;
//	if (n > 0)
//	{
		while (n > 0)
		{
			dest[len - 1] =  n % 10 + '0';
			n = n / 10; 
			len--;
		}
//	}
	return (dest);
}

#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_itoa(-123));
	return (0);	
}
