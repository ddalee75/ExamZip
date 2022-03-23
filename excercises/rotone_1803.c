/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone_1803.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:29:14 by chilee            #+#    #+#             */
/*   Updated: 2022/03/18 13:40:16 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write (1, &c, 1);
}

char 	ft_rotone(char c)
{
	if ((c >= 'a' && c <= 'y') || (c >= 'A' && c <= 'Y'))
		c = c +1;
	else if (c == 'z' || c == 'Z')
		c = c-25;
	return (c);
}

int main(int ac, char **av)
{
	int i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{	
			ft_putchar(ft_rotone(av[1][i]));
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}


