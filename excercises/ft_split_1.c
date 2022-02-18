/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:12:28 by chilee            #+#    #+#             */
/*   Updated: 2022/02/18 15:39:57 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int 	ft_strlen(char *s)
{
	int i;
	
	i = 0; 
	while (s[i])
		i++;
	return (i);
}

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

int	ft_count(char *s)
{
	int i; 
	int	count;

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
	return(count);
}

char	*ft_copy(char *s)
{
	int i;
	int j;
	char	*dest;

	i = 0;
	while (s[i] && (s[i] != ' ' && s[i] != '\t' && s[i] != '\n'))
		i++;
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	j = 0;
	while (j < i)
	{
		dest[j] = s[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	**ft_split(char *str)
{
	int i;
	char	**tab;
	int	i_tab;

	i = 0;
	i_tab = 0;
	tab = malloc(sizeof(char *) * ft_count(str) + 1);
	if (!*tab)
		return (NULL);
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
		{
			tab[i_tab] = ft_copy(&str[i]);
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
	return(tab);
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


/*
int main(void)
{
	char **tab;
	char *str;
	int i;

	i = 0;
	str = " Hello paris Hello world";
	tab = ft_split(str);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}*/	
