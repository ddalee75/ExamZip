/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expland_str_1403.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:06:34 by chilee            #+#    #+#             */
/*   Updated: 2022/03/14 15:22:03 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen_c(char *s)
{
	int i = 0;
	while (s[i] && (s[i] != ' ' && s[i] != '\t'))
		i++;
	return(i);
}

int main(int ac, char **av)
{
	int i = 0;
	int first = 1;
	int len ;
	char *s = av[1];

	if (ac == 2)
	{
		while (s[i] && (s[i] == ' '|| s[i] == '\t'))
			i++;
		while (s[i])
		{
			len =ft_strlen_c(&s[i]);
			if (len > 0 && first== 0)
				write (1, "   ", 3);
			write (1, &s[i], len);
			i = i + len;
			while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			   i++;
			first = 0;	
		}
	}
	write (1, "\n", 1);
	return (0);
}
