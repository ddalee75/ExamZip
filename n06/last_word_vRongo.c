/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:08:09 by chilee            #+#    #+#             */
/*   Updated: 2022/02/21 16:05:16 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (av[1][i])
		i++;
	i--;
	while (av[1][i] == ' ' || av[1][i] == '\t')
		i--;
	while ((av[1][i] >= '!' || av[1][i] <= '~'))
	{
		i--;
		if (av[1][i] == ' ')
		{
			i++;
			while (av[1][i] >= '!' && av[1][i] <= '~')
			{
				write(1, &av[1][i], 1);
				i++;
			}
			write(1, "\n", 1);
			return (0);
		}
	}
}
