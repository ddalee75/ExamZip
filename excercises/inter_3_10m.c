/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:06:05 by chilee            #+#    #+#             */
/*   Updated: 2022/02/18 11:36:05 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int i;
	char tab[256] = {0};

	i = 0;
	if (ac == 3)
	{
		while (av[2][i])
		{
			if (tab[(int)av[2][i]] == 0)
				tab[(int)av[2][i]] = 1;
			i++;
		}
		i = 0;
		while (av[1][i])
		{
			if (tab[(int)av[1][i]] == 1)
			{
				write (1, &av[1][i], 1);	
				tab[(int)av[1][i]] = 2;
			}
			i++;
		}
		return (0);
	}
	write (1, "\n", 1);
}
