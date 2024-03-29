/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot13_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:07:43 by chilee            #+#    #+#             */
/*   Updated: 2022/02/17 14:18:34 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	rot13(char c)
{
	if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
		c = c + 13;
	else if (( c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
		c = c - 13;
	return (c); 
}

int main(int ac, char **av)
{
	int i;
	int p;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			p = rot13(av[1][i]);
			write (1, &p, 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
