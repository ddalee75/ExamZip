/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:01:21 by chilee            #+#    #+#             */
/*   Updated: 2022/02/17 18:04:12 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include<unistd.h>

/*void	ft_putchar(char c)
{
	write (1, &c, 1);
}*/

int	ft_count(int n)
{
	int count;
	
	count = 1;
	if (n < 0)
		count++;
	while (n / 10)
	{
		n = n / 10;
		count++;
	}	
	return (count);
}

char	*ft_itoa(int nbr)
{
	char	*dest;
	int	len;
	unsigned	int n; 

	len = ft_count(nbr);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	if (nbr == 0) 
		dest[0] = '0';
	else if (nbr < 0 )
	{
		n = -nbr;
		dest[0] = '-';
	}
	else 
		n = nbr;
	while (n > 0)
		{
			dest[len - 1] = (n % 10) + '0';
			n = n / 10;
			len--;
		}
	return (dest);
}

#include<stdio.h>

int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	return (0); 
}
