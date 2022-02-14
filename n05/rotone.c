/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:12:19 by chilee            #+#    #+#             */
/*   Updated: 2022/02/14 11:23:09 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write (1, &c, 1);
}

char	rotone(char c)
{
	if ((c >= 'a' && c <= 'y') || (c >= 'A' && c <= 'Y'))
		c = c + 1;
	else if (c == 'z' || c == 'Z')
		c = c - 25;
	return (c);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			ft_putchar(rotone(av[1][i]));
			i ++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
