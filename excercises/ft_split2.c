/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:13:21 by chilee            #+#    #+#             */
/*   Updated: 2022/02/28 15:42:51 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	**ft_split(char *str)
{
	int i = 0;
	char **tab;
	int i_tab = 0;
	int j;

	tab = malloc(sizeof(char *) * 10000);
	   if (!tab)	
		   return (NULL);
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] =='\n'))
		i++;
	while (str[i])
	{
		tab[i_tab] = malloc(sizeof(char) * 10000);
		if (!tab[i_tab])
			return (NULL);
		j = 0;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
		{
			tab[i_tab][j] = str[i];
			i++;
			j++;
		}
		tab[i_tab][j] = '\0';
		i_tab++;
		while (str[i] && (str[i] == ' ' || str[i] == '\t'|| str[i] == '\n'))  
			i++;
	}
	tab[i_tab] = NULL;
	return (tab);
}

/*
#include <stdio.h>
int	main(void)
{
	int i;
	char **tab;

	i = 0;
	tab = ft_split(" hello paris hello world ");
	while (tab[i])
	{
		printf("%s\n", tab[i]);
			i++;
	}
	return (0);
}
*/
