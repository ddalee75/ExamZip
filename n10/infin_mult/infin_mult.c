/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult_ching.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:31:39 by chilee            #+#    #+#             */
/*   Updated: 2022/03/01 16:51:59 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int i;
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	infin_mult(char *s1, char *s2)
{
	int *arr;
	int	i;
	int	j;
	int	len1;
	int	len2;
	int	len_all;

	if (*s1 == '0' || *s2 == '0')
	{	
		write (1, "0", 1);
		return;
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len_all = len1 + len2;
	arr = (int *)malloc(sizeof(int) * len_all);
	if (!arr)
		return;
	i = 0;
	while (i < len_all)
	{
		arr[i] = 0;
		i++;
	}
	i = len1 - 1;
	while (i >= 0)
	{
		j = len2 - 1;
		while (j >= 0)
		{
			arr[i + j + 1] = arr[i + j + 1] + ((s1[i] - '0') * (s2[j] - '0'));
			j--;
		}
		i--;
	}
	i = len_all - 1;
	while (i >= 0)
	{
		arr[i - 1] = arr[i - 1] + arr[i] / 10;
		arr[i] = arr[i] % 10 ;
		i--;
	}
	i = 0;
	while(i < len_all && arr[i] == 0)
		i++;
	while (i < len_all)
	{
		char c = arr[i] + '0';
		write (1, &c, 1);
		i++;
	}
	free(arr);
}

int	main(int ac, char **av)
{
	char *s1;
	char *s2;

	if (ac == 3)
	{
		s1 = av[1];
		s2 = av[2];

		if ((*s1 == '-' && *s2 == '-') || (*s1 != '-' && *s2 != '-'))
		{
			if (*s1 == '-' && *s2 == '-')
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
			if (*s1 != 0 && *s2 != 0)
				write (1,"-", 1);
			infin_mult(s1, s2);
		}
		write (1, "\n", 1);
	}
	write (1, "\n", 1);
	return (0);
}
