/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:15:59 by chilee            #+#    #+#             */
/*   Updated: 2022/03/03 14:56:37 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char*s)
{
	int i = 0;
	while (s[i] && (s[i] != ' ' && s[i] != '\t'))
		i++;
	return (i);
}

int main(int ac, char **av)
{
	int i = 0; 
	int first = 1;
	char *s = av[1];
	int len;

	
	if (ac==2)
	{
		while (s[i] == ' ' ||s[i] == '\t')
			i++;
		while (s[i])
		{
			len = ft_strlen(&s[i]);
			if (len > 0 && first == 0)
				write (1, "   ", 3);
			if (s[i] && (s[i] != ' ' && s[i] != '\t'))
			{
				write (1, &s[i], len);
				i = i + len;
			}
			while (s[i] == ' ' || s[i] == '\t')
				i++   ;
			first = 0;			
		}
	}
	write (1, "\n", 1);
	return (0);
}
	
