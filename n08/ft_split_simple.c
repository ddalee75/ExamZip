/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_simple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:27:35 by chilee            #+#    #+#             */
/*   Updated: 2022/02/21 18:48:29 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>


char	**ft_split(char *str)
{
	int	i = 0;
	int	tab = 0;
	int	j;
	char ** ret;

	ret = (char **)malloc(sizeof(char *) * 10000);
	if (!ret)
		return (NULL);
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	while (str[i])
	{
		j = 0;
		ret[tab] = (char *)malloc(sizeof(char) * 10000);
		if (!ret)
			return (NULL);
		while (str[i] && (str[i] != ' ') && (str[i] != '\t') && (str[i] != '\n'))
		{
			ret[tab][j] = str[i];
			j++;
			i++;
		}
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		ret[tab][j] = '\0';
		tab++;
	}
	ret[tab] = NULL; 
	return (ret);
}


#include <stdio.h>

int    main(void)
{
    char    **result;
    char    *str;
    int        i;

    i = 0;
    str = "  Thanks, I'm fine! ";
    result = ft_split(str);
    while (result[i])
    {
        printf("%s\n", result[i]);
        i++;
    }
    return (0);
}
/*
int	main(int ac, char **av)
{
	int i;
	char **p;

	i = 0;
	p = ft_split(av[1]);
	if (ac == 2)
	{
		while (p[i])
		{
			printf("%s\n", p[i]);		
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}*/
