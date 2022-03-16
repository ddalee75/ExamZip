/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:06:26 by chilee            #+#    #+#             */
/*   Updated: 2022/03/16 16:28:09 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *rev_print(char *str)
{
	int i =0;
	while (str[i])
		i++;
	i--;
	while (i >= 0)
	{
		write (1, &str[i], 1);
		i--;
	}
	return (str);
}

/*
#include <stdio.h>
int main (int ac ,char **av)
{
	(void)ac;
	char *s = av[1];
	rev_print(s);
	printf("\n");
	printf("%s\n", s);
}*/
