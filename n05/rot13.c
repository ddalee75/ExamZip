/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot13.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:35:23 by chilee            #+#    #+#             */
/*   Updated: 2022/02/14 11:12:12 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void 	ft_putchar(char c)
{
	write (1, &c, 1);
}

char	ft_rot13(char c)
{
 	if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
		c = c + 13;
	else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
		c = c - 13;
	return (c);
}

int	main(int ac, char **av)
{	
	int i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			ft_putchar(ft_rot13(av[1][i]));
			i ++ ;
		}
	}
	write (1, "\n", 1);
	return (0);
}
