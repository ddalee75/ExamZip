/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:50:16 by chilee            #+#    #+#             */
/*   Updated: 2022/02/28 16:23:47 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i] && (s[i] != ' ' && s[i] != '\t'))
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	char *s;
	s = av[1];
	int i;
	i = 0;
	int first = 1;
	int len;

	if (ac == 2)
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
		while (s[i])
		{
			len = ft_strlen(&s[i]);
			if(len > 0 && first == 0)
				write(1 , "   ", 3);
			while (s[i] && (s[i] != ' ' && s[i] != '\t'))
			{
				write(1, &s[i], len);
				i = i + len;
			}
			while (s[i] && (s[i] == ' '|| s[i] == '\t'))
				i++;
			first = 0;
		}
	}
	write(1, "\n", 1);
	return (0);
}
