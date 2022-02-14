/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:26:31 by chilee            #+#    #+#             */
/*   Updated: 2022/02/14 12:33:33 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int		i;
	char	ascii[256] = {0};

	if (ac == 3)
	{
		i = 0;
		while (av[2][i])
		{
			if (ascii[(int)av[2][i]] == 0)
				ascii[(int)av[2][i]] = 1;
			i ++;
		}
		i = 0;
		while (av[1][i])
		{
			if (ascii[(int)av[1][i]] == 1)
			{
				write (1, &av[1][i], 1);
				ascii[(int)av[1][i]] = 2;
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
