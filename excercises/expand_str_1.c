/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:09:29 by chilee            #+#    #+#             */
/*   Updated: 2022/02/22 11:18:20 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] && (s[i] != ' ' && s[i] != '\t'))
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int i;
	int len;
	int	printspace;

	i = 0;
	printspace = 1;
	if ( ac == 2)
	{
		while (av[1][i])
		{
			while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
				i++;
			len = ft_strlen(&av[1][i]);
			if ((len > 0) && printspace == 0) 
				write (1, "   ", 3); 
			write (1, &av[1][i], len);
			i = i + len;
			printspace = 0;
		}
	}
	write (1, "\n", 1);
	return (0);
}

