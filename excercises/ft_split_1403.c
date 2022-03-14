/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_1403.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:45:29 by chilee            #+#    #+#             */
/*   Updated: 2022/03/14 15:06:23 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_split(char *str)
{
	int i = 0;
	int j;
	char **dest;
	int tab = 0;

	dest = malloc(sizeof(char *) * 10000);
	if (!dest)
		return (NULL);
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	while (str[i])
	{
		j = 0;
		dest[tab] = malloc(sizeof(char) * 10000);
		if (!dest[tab])
			return (NULL);
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			dest[tab][j]= str[i];
			j++; 
			i++;
		}
		dest[tab][j] = '\0';
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		tab++;
	}
	dest[tab] = NULL;
	return (dest);
}

#include <stdio.h>
int main(void)
{
	int i = 0;
	char **arr;
	char *s = " Hello world, hello you  ";
	arr = ft_split(s);
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
	return(0);

}
