/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:09:50 by chilee            #+#    #+#             */
/*   Updated: 2022/02/10 17:40:13 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	check_ascii(char *s1, char *s2)
{
	int		i;
	char	ascii[256] = {0};

	i = 0 ;
	while (s2[i])
	{
		if (ascii[(int)s2[i]] == 0)
			ascii[(int)s2[i]] = 1;
		i++;
	}
	i = 0;
	while (s1[i])
	{
		if (ascii[(int)s1[i]] == 1)
		{
			write (1, &s1[i], 1);
			ascii[(int)s1[i]] = 2;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		check_ascii(av[1], av[2]);
	}
	write (1, "\n", 1);
	return (0);
}
