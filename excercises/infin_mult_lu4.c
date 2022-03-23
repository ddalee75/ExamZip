#include <unistd.h>
#include <stdlib.h>

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
	if (*s1 == '0' || *s2 == '0' || (*s1 == '-' && s1[1] == '0') || (*s2 == '-' && s2[1] == '0'))
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (*s1 == '-' && *s2 == '-')
	{
		s1 = s1 + 1;
		s2 = s2 + 1;
	}
	if (*s1 == '-' && *s2 != '-')
	{
		s1 = s1 + 1;
		write(1, "-", 1);
	}
	if (*s1 != '-' && *s2 == '-')
        {
                s2 = s2 + 1;
                write(1, "-", 1);
        }
	i = ft_strlen(s1);
        j = ft_strlen(s2);
	tab = malloc(sizeof(int) * (i + j));
	if (!tab)
		return (0);
	k = 0;
	while (k < i + j)
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
			tab[i+j+1] = tab[i+j+1] + (s2[j] - 48) * (s1[i] - 48);
			i--;
		}
		j--;
		i = ft_strlen(s1) - 1;
	}
	k--;
	while (k > 0)
	{
		tab[k-1] = tab[k-1] + (tab[k] / 10);
		tab[k] = tab[k] % 10;
		k--;
	}
	k=0;
	while (tab[k] == 0)
		k++;
	while (k < ft_strlen(s1) + ft_strlen(s2))
	{
		c = tab[k] + 48;
		write(1, &c, 1);
		k++;
	}
	write(1, "\n", 1);
	free (tab);
	return (0);
}
