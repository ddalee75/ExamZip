#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define VAL(x)   (x - '0')
#define ASCII(x) (x + '0')

char *create_str(int nb) 
{
	char	*s;
	int	i;

	s = malloc(sizeof(char) * (nb + 1));
	if (s == 0)
		return(NULL);
	while (i < nb)
	{
        	s[i] = '0';
		i++;
	}
    	s[nb] = '\0';
    	return s;
}

void	ft_print(char *s)
{
	long long	i;

	if (s[0] == '0' && s[1] == '\0')
	{
		write (1, "0\n", 2);
		return ;
	}
	i = 0;
	if (s[i] == '-')
	{
		write(1, &s[i], 1);
		i++;
	}
	while (s[i] == '0' && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

static char	*mul(char *a, char *b) 
{
 	char		*s;
 	int		sign, carry;
 	long long	la, lb, len;
 	long long	i, j, k;
 	int		mul;

	if (VAL(*a) == 0 || VAL(*b) == 0)
        {
		s = malloc(sizeof(char) * 2);
                s[0] = '0';
                s[1] = '\0';
                return (s);
        }

 	sign = 0;
 	if (*a == '-')
 	{
 		a++;
		sign = !sign;
 	}
 	if (*b == '-')
	{
		b++;
		sign = !sign;
	}

	la = strlen(a);
	lb = strlen(b);
	len = la + lb;
  
	s = create_str(len + sign);
 	if (s == 0)
		return (NULL);
	if (sign == 1)
		*s = '-';
	s[len + sign] = 0;
	
	i = la - 1;
 	while (i >= 0)
 	{
		j = lb - 1;
		k = i + j + 1 + sign;
		carry = 0;
		while (j >= 0)
		{
			mul = VAL(a[i]) * VAL(b[j]) + VAL(s[k]) + carry;
			carry = mul / 10;
			s[k] = ASCII(mul % 10);
			j--;
			k--;
		}
		s[k] += carry;
		i--;
	}
	return (s);
}

int	main(int ac, char **av)
{
  char	*res;

  if (ac < 3 || !(res = mul(av[1], av[2])))
    return (1);
  ft_print(res);
  free(res);
  return (0);
}

