/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:43:46 by chilee            #+#    #+#             */
/*   Updated: 2022/02/18 11:04:43 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write (1, &c, 1);
}

char	ft_check(char c)
{
	if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <=  'M'))
		c = c + 13;
	else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
		c = c - 13;
	return (c);
}

int	main(int ac, char **av)
{
	int		i;
	char	c;
	i = 0;
	
	if (ac == 2)
	{
		while (av[1][i])
		{
			c = ft_check(av[1][i]);
			ft_putchar(c);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
