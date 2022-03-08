/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:37:21 by chilee            #+#    #+#             */
/*   Updated: 2022/03/07 17:20:02 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen (char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

void	infin_mult(char *s1, char *s2)
{
	int len1 = ft_strlen(s1);
	int len2 = ft_strlen(s2);
	int len_all = len1 + len2;
	int i=0;
	int j;
	int *arr;
	if (*s1 == '0' || *s2 =='0')
	{
		write (1, "0", 1);
		return;
	}
	arr=malloc(sizeof(int) * len_all);
	if (!arr)
		return;
	while (i < len_all)
	{	
		arr[i] = 0;
		i++;
	}
	i = len1 -1;
	while (i >= 0)
	{
		j = len2-1;
		while (j >=0)
		{
			arr[i + j+ 1] += (s1[i] - '0') * (s2[j] - '0');
			j--;
		}
		i--;
	}
	i=len_all - 1;
	while (i >= 0)
	{
		arr[i-1] = arr[i-1] + arr[i] / 10;
		arr[i] = arr[i] % 10;
		i--; 
	}
	i = 0;
	while (arr[i] == 0)
		i++;
	while (i <len_all)
	{
		char c =  arr[i] + '0';
		write (1, &c, 1);
		i++;
	}
	free(arr);
}


int	main(int ac, char **av)
{
	char *s1 = av[1];
	char *s2 = av[2];

	if (ac ==3)
	{
		if ((*s1 == '-' && *s2=='-') || (*s1 != '-' && *s2 != '-'))
		{
			if (*s1 == '-' && *s2=='-')
			{
				s1++;
				s2++;
			}
			infin_mult(s1, s2);
		}
		else 
		{
			if (*s1 == '-')
				s1++;
			if (*s2 == '-')
				s2++;
			if (*s1 != '0' && *s2 !='0')
				write(1, "-", 1);
			infin_mult(s1, s2);
		}
	}
	write (1, "\n", 1);
	return (0);
}
