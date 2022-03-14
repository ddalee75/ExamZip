/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_1403.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:31:39 by chilee            #+#    #+#             */
/*   Updated: 2022/03/14 12:02:36 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_inter(char *s1, char *s2)
{
	int i = 0;
	int ascii[256] = {0};

	while (s2[i])
	{
		if (ascii[(int)s2[i]] == 0)
		{
			ascii[(int)s2[i]] = 1;
		}
		i++;
	}
	i = 0;
	while (s1[i])
	{
		if (ascii[(int)s1[i]] == 1)
		{
			ascii[(int)s1[i]] = 2;
			write (1, &s1[i],1);
		}
		i++;
		
	}
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_inter(av[1], av[2]);	
	}
	write( 1, "\n", 1);
	return (0);
}
