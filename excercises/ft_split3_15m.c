/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:10:54 by chilee            #+#    #+#             */
/*   Updated: 2022/03/03 16:27:06 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char **ft_split(char *str)
{
	int i =0;
	char **tab;
	int i_tab = 0;
	int j;

	while (str[i] == ' ' || str[i] =='\t' || str[i] =='\n')
		i++;
	tab = malloc(sizeof(char *) * 10000);
	if (!tab) 
		return (NULL);
	while (str[i])
	{
		j = 0;
		tab[i_tab] = malloc(sizeof(char) * 10000);
		if (!tab[i_tab])
			return (NULL);
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
		{
			tab[i_tab][j] = str[i];
			i++; 
			j++;
		}
		tab[i_tab][j] = '\0';
		while (str[i] && (str[i] ==' ' || str[i] == '\t' || str[i] == '\n'))
		{
			i++;
		}
		i_tab++;
	}
	tab[i_tab] = NULL;
	return (tab);
}

#include <stdio.h>
int main(void)
{
	char *s = "hello how are you  ";
	char **tab = ft_split(s);
	int i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	free (tab);
	return (0);

}
