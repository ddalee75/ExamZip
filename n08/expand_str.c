/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:29:03 by chilee            #+#    #+#             */
/*   Updated: 2022/02/16 12:51:09 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	word_len(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\t')
		i++;
	return (i);

}

void 	expland_str(char *s)
{
	int i;
	int first_word;
	int	len;

	i = 0;
	first_word = 1;
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		len = word_len(&s[i]);
		if (len > 0 && first_word == 0)
			write (1, "   ", 3);
		write (1, &s[i], len);
		first_word = 0;
		i =  i + len;	
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		expland_str(av[1]);
	write (1, "\n", 1);
	return (0);
}
