/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word_1603.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:32:28 by chilee            #+#    #+#             */
/*   Updated: 2022/03/16 18:39:18 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	char *s =av[1];
	int i =0;
	
	if (ac ==2)
	{
		while (s[i])
			i++;
		i--;
		while (i >=0 && (s[i] ==' ' || s[i] == '\t'))
			i--;
		while (i >= 0 && (s[i] !=' ' && s[i] != '\t'))
			i--;
		i++;
		while (s[i] && (s[i] !=' ' && s[i] != '\t'))
		{
			write (1, &s[i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
