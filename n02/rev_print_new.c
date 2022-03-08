/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:57:34 by chilee            #+#    #+#             */
/*   Updated: 2022/03/08 16:12:04 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char    *rev_print (char *str)
{
	int     i;
	i = 0;
    while (str[i])
		i++;
	i--;
	while (i>=0)
     {
            write (1, &str[i],1);
            i--;
     }
    return (str);             /*returning its argument */
}

/*
int main (void)
{
	rev_print("rainbow dash");
	write(1, "\n", 1);
	return (0);
}*/
