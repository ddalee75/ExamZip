#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	(void)	ac;
	char	*s1;
	char	*s2;
	int	*tab;
	int	i;
	int	j;
	int	k;
	char	c;

	s1 = av[1];
	s2 = av[2];
	i = ft_strlen(s1);
        j = ft_strlen(s2);

/*	if (s1[0] == '-' && s2[0] == '-')
	{
		i--;
		j--;
	}
	if ((s1[0] == '-' && s2[0] != '-')
	if (s1[0] != '-' && s2[0] == '-'))
*/
	tab = malloc(sizeof(int) * (i + j - 1));
	if (!tab)
		return (0);
	k = 0;
	while (k < i + j - 1)
	{
		tab[k] = 0;
		k++;
	}
	i--;
	j--;
	while (j >= 0)
	{
		while (i >= 0)
		{
			tab[i+j] = tab[i+j] + (s2[j] - 48) * (s1[i] - 48);
			i--;
		}
		j--;
		i = ft_strlen(s1) - 1;
	}
	k--;
	while (k >= 0)
	{
		tab[k-1] = tab[k-1] + (tab[k] / 10);
		tab[k] = tab[k] % 10;
		k--;
	}
	k = 0;
	while (k <= ft_strlen(s1) + ft_strlen(s2) - 2)
	{
		c = tab[k] + 48;
		write(1, &c, 1);
		k++;
	}
}

