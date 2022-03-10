/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_diam_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:22:33 by chilee            #+#    #+#             */
/*   Updated: 2022/03/10 11:52:18 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int nodes = 2;

int 	ft_atoi_c(char **s)
{
	int n = 0;;
	while (**s && **s >= '0'&& **s <='9')
	{
		n = n * 10 + (**s - '0');
		(*s)++;
	}
	if (**s)
		(*s)++;
return (n);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb /10);
	}
	char c;
	c = nb % 10 + '0';
	write (1, &c, 1);
}

void	ft_nodes(int max, int path[max], int grid[max][max], int y, int len)
{
	int x = -1;
	path[y] = 1;
	while (++x < max)
	{
		if (path[x] == 0 && grid[x][y] == 1)
		{
			if (nodes < len + 1)
				nodes = len + 1;
			ft_nodes(max, path, grid, x, len + 1);
		}
	}	
	path[y] = 0;	
}

void	ft_init(char *s , int max)
{
	int path[max];
	int grid[max][max];
	int x ;
	int y;
	x = -1;
	while (++x < max)
		path[x] = 0; 	
	x = -1;
	while (++x < max)
	{
		y =-1;
		while (++y < max)
		{
			grid[x][y] = 0;
		}
	}
	while (*s)
	{
			x = ft_atoi_c(&s);
			y = ft_atoi_c(&s);
			grid[x][y] = 1;
			grid[y][x] = 1;
	}
		y = -1;
	while (++y < max)
	{
		ft_nodes(max, path, grid, y, 1);
	}	
}

int main(int ac, char **av)
{
	char *s = av[1];
	int max = 0;
	int tmp = 0;

	if (ac == 2 )
	{
		if (*s == '\0')
			ft_putnbr(0);
		else if (ft_atoi_c(&s) == ft_atoi_c(&s) && *s == '\0')
			ft_putnbr(1);
		else 
		{
			while (*s)
			{
				tmp = ft_atoi_c(&s);
				if (tmp > max)
					max = tmp;			
			}
			max++;
			s = av[1];
			ft_init(s, max);
		   	ft_putnbr(nodes);	
		}
	}
	write (1, "\n", 1);
	return (0);
}
