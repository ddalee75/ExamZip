/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizz_buzz1_20m.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:54:41 by chilee            #+#    #+#             */
/*   Updated: 2022/02/17 11:55:47 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar(n % 10 + '0');
}

int	main(void)
{
	int	n; 

	n = 1;
	while ( n <= 100)
	{
		if (n % 3 == 0) 
		{
			write (1, "fizz\n", 5);
		}	
		if (n % 5 == 0)
		{
			write (1, "buzz\n", 5);
		}
		if (n % 3 == 0 && n % 5 == 0)
		{
			write (1, "fizzbuzz\n", 9);
		}
		else
		{
			ft_putnbr(n);
			ft_putchar('\n');
		}
		n++;
	}
	return (0); 
}
