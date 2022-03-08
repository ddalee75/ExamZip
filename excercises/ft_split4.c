/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:08:27 by chilee            #+#    #+#             */
/*   Updated: 2022/03/07 14:37:46 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	**ft_split(char *str)
{
	int i;
	char	**dest;
	i = 0;
	int	i_tab = 0;
	int j;
	while (str[i] == ' ' ||str[i] == '\t' || str[i] == '\n')
		i++;
	dest = malloc(sizeof(char *) * 10000);
	if (!dest)
		return (0);
	while (str[i]) 
	{
		j = 0;
		dest[i_tab] = malloc(sizeof(char)*10000);
		if(!dest[i_tab])
			return (0);
		while (str[i] && (str[i] !=' ' && str[i] !='\t' && str[i] != '\n'))
		{
			dest[i_tab][j] = str[i];
			i++;
			j++;
		}
		dest[i_tab][j] = '\0';
		i_tab++;
		while (str[i] == ' ' ||str[i] == '\t' || str[i] == '\n')
			i++;
	}
	dest[i_tab]= NULL;
	return (dest);
}

#include <stdio.h>
int main(void)
{
	char *str;
	str = "  HELLO HELLO                    YOU Paris ";
	char **s;
	s = ft_split(str);
	int i = 0;
	while (s[i])
	{
		printf("%s\n", s[i]);
		free(s[i]);
			i++;
	}
	free(s);
	return (0);

}
