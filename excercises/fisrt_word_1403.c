/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fisrt_word_1403.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:08:49 by chilee            #+#    #+#             */
/*   Updated: 2022/03/14 11:19:08 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int ac, char **av)
{
	int i = 0;
	char *s = av[1];
	if (ac == 2)
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
		while (s[i] && (s[i] != ' ' && s[i] != '\t'))
		{
			write (1, &s[i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
