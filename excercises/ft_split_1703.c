/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_1703.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:04:42 by chilee            #+#    #+#             */
/*   Updated: 2022/03/17 16:31:12 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char **ft_split(char *str)
{
	char **tab = NULL;
	int i = 0; 
	int j = 0;
	int i_tab=0;

	tab = malloc(sizeof(char *) * 9000);
		if (!tab)
			return (0);
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')) 
		i++;
	while (str[i])
	{	
		j = 0; 
		tab[i_tab] = malloc(sizeof(char) * 9000);
		if (!tab[i_tab])
		return (0);
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
		{
			tab[i_tab][j] = str[i];
			j++;
			i++;
		}
		tab[i_tab][j] = '\0';
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		i_tab++;
	}
	tab[i_tab] = NULL; 
	return (tab);
}
#include <stdio.h>
int main(void)
{
	int i = 0;
	char *s = " HELLO YOU HELLO PARIS  ";
	char **tab = ft_split(s);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
			i++;
	}

	
}
