/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:25:43 by chilee            #+#    #+#             */
/*   Updated: 2022/02/28 17:13:20 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_count(int nbr)
{
	int count;
	int n;

	n = nbr;
	count =1;
	if (n < 0)
		count++;
	while(n /10)
	{
		n = n/ 10;
		count++;
	}
	return(count);
}

char *ft_itoa(int nbr)
{
	int len;
	char *dest;
	unsigned int n;

	len = ft_count(nbr);
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	if (nbr == 0)
		dest[0] = '0';
	if (nbr < 0)
	{
		n = -nbr;
		dest[0] = '-';
	}
	else 
		n = nbr;

	while (n >0)
	{
		dest[len - 1] = n % 10 + '0';
	  	n = n / 10; 
		len--;
	}
	return (dest);
}

#include <stdio.h>
int main(void)
{
	int i = 0 ; 
	char *s;
	s = ft_itoa(i);
	printf("%s\n", s);
	return (0);

}
