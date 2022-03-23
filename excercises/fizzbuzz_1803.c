/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz_1803.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:56:58 by chilee            #+#    #+#             */
/*   Updated: 2022/03/18 13:02:53 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write (1, &c, 1);
}

void ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n /10);
	}
	ft_putchar(n % 10 + '0');
}

int main(void)
{
	int n = 1;

	while (n <=100)
	{
		if (n %3 == 0 && n % 5==0)
			write (1, "fizzbuzz", 8);
		else if (n % 3 == 0)
			write (1, "fizz", 4);
		else if ( n % 5 == 0)
			write (1, "buzz", 4);
		else
			ft_putnbr(n);
		n++;
		ft_putchar('\n');
	}
	return (0);
}
