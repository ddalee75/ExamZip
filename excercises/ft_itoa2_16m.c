/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:10:14 by chilee            #+#    #+#             */
/*   Updated: 2022/02/17 18:27:45 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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
	unsigned int	n;
	char			*dest;
	int				len;

	len = ft_count(nbr);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	if (nbr == 0)
		dest[0] = '0';
	else if (nbr < 0)
	{
		n = -nbr;
		dest[0] = '-';
	}
	else
		n = nbr;
	while (n > 0)
	{
		dest[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (dest);
}

#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	return (0);	
}
