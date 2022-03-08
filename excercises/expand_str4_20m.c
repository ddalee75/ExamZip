/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:38:25 by chilee            #+#    #+#             */
/*   Updated: 2022/03/07 15:35:04 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i] && (s[i] != ' ' && s[i] !='\t'))
		i++;
	return (i);
}


int	main(int ac, char **av)
{
	int i = 0;
	int first = 1;
	char *s;
	s = av[1];
	int len;
	if (ac == 2)
	{
		while (s[i])
		{
			while (s[i] && (s[i] == ' ' || s[i] == '\t'))
				i++;
			len = ft_strlen(&s[i]);
			if (len > 0 && first == 0)
				write (1, "   ", 3);
			if (s[i] && (s[i] != ' ' && s[i] != '\t'))
			{
				write (1, &s[i], len);
			}
			i = i + len;
			first = 0;
		}
	}
	write (1, "\n", 1);
	return (0);
}
