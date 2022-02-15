/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:31:37 by chilee            #+#    #+#             */
/*   Updated: 2022/02/15 19:35:39 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_error(char **tab)
{
	int i;
	
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i); 
}

int	ft_count(char *s)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i++;
		if (s[i] && (s[i] != ' ' && s[i] != '\t' && s[i] != '\n'))
		{
			count++;
			while (s[i] && (s[i] != ' ' && s[i] != '\t' && s[i] != '\n'))
				i++;
		}
	}
	return (count);
}

char	*cpy_word(char *s)
{
	int	i;
	int j;
	char *dest;

	i = 0;
	while (s[i] && (s[i] != ' ' && s[i] != '\t' && s[i] != '\n'))
		i++;
	dest = (char *)malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	j = 0;
	while (i > j)
	{
		dest[j] = s[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	**ft_split(char *str)
{
	int	i;
	char	**tab;
	int	i_tab;
	
	i = 0;
	tab = malloc(sizeof(char *) * (ft_count(str) + 1));
	if (!tab)
		return (NULL);
	i_tab = 0;	
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;	
		if (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
		{
			tab[i_tab] = cpy_word(&str[i]);
			if (!tab[i_tab])
			{
				free_error(tab);
				return (NULL);
			}
			i = i + ft_strlen(tab[i_tab]);
			i_tab++;
		}
	}
	tab[i_tab] = NULL;
	return (tab);
}

#include <stdio.h>

int		main(void)
{
	int i = 0;
	char **tab;
		
	tab = ft_split("\nbonjour\n   je   m'appel\n \tsss je viens\t de Paris");
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	free_error(tab);
	return (0);
}
