/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:00:20 by chilee            #+#    #+#             */
/*   Updated: 2022/03/10 14:54:08 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int ft_strlen_c(char *s, char c)
{
	int i = 0;
	while (s[i] && s[i] !=c)
		i++;
	return (i);
}

int 	ft_check(char *s)
{
		int i = 0;
		int len_0 = ft_strlen_c(s, '\n')+ 1;
		if (len_0 > 1024)
		{
			return (0);
		}
		if (s[i] == '\0' || s[i] == '\n')
		{	
			return (0);
		}
		while (s[i])
		{
			if ((s[i] != 'X' && s[i] != '.' && s[i] != '\0' && s[i] != '\n') ||
				((s[i] == '\n'|| s[i] == '\0') && ((i + 1) % len_0 != 0)))
				return (0);
			i++;
		}
		return (1);
}
int 	ft_read(int fd, char **s, int len)
{
		int len_read;
		char c;
		len_read = read(fd, &c, 1);
		if (len_read < 0)
			return (0);
		if (len_read > 0)
		{
			ft_read(fd, s, len + 1); 
			(*s)[len] = c;
		}
		else 
		{
			*s = malloc(sizeof(char) * len + 1); 
			if (!*s)
				return (0);
			(*s)[len] = '\0';
		}
		return (1);
}
void	 ft_fill(char *s, int i, int nb) 
{	
	int len_0 = ft_strlen_c(s, '\n') + 1;
	int len_all = ft_strlen_c(s, '\0') +1;

	if (i < len_all && s[i] == 'X')
	{
		s[i] = nb + '0'; 
		ft_fill(s, i + 1, nb);
		ft_fill(s, i + len_0, nb);
		ft_fill(s, i - 1, nb);
		ft_fill(s, i - len_0, nb);
	}
}

#include <stdio.h>
int main(int ac , char **av)
{
	int i = 0;
	int fd;
	char *s = NULL;
	int nb = 0;
	if (ac != 2)
	{
		write (1, "\n", 1);
	}
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd > 0 && ft_read(fd, &s, 0) && ft_check(s) == 1)
		{
				while (s[i])
				{	
					if (s[i] == 'X') 
					{	
						ft_fill(s, i, nb);
							nb++;
					}
					i++;
				}
				if (nb < 10)
				{	
					i = 0;
					while (s[i])
					{
						ft_putchar(s[i]);
						i++;						
					}
				}
		}	
		else
			write (1, "\n", 1);
	free(s);
	close(fd);
	}
	return (0);
}

