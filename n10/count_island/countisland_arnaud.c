#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char 	**ft_split(char *str)
{
	int i;
	int j;
	int k;
	char **s;

	s =malloc(sizeof(char *) * 10000);
	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i] != '\0')
			i++;
		if (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i] != '\0')
		{
			j = 0;
			s[k] = malloc(sizeof(char) * 10000);
			while (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i] != '\0')
			{
				s[k][j] = str[i];
				i++;
				j++;
			}
			s[k][j] = '\0';
			k++;
		}
		i++;
	}
	s[k] = NULL;
	return (s);
}

void	ft_print(char **s)
{
	int i;
	int j;

	i = 0;
	while (s[i] != 0)
	{
		j = 0;
		while(s[i][j] != '\0')
		{
			write(1, &s[i][j], 1);
			j++;	
		}
		write(1, "\n", 1);
		i++;
	}
}

void	dfs(char **s, int i, int j, int row, int col, int count)
{
	if (i<0 || i>=row || j<0 || j>=col || s[i][j] == '.' || (s[i][j] >= '0' && s[i][j] <= '9'))
		return ;
	s[i][j] = count + '0';
	dfs(s, i+1, j, row, col, count);
	dfs(s, i-1, j, row, col, count);
	dfs(s, i, j+1, row, col, count);
	dfs(s, i, j-1, row, col, count);
}

int	ft_countisland(char **s)
{
	int i;
	int j;
	int count;	
	int row;
	int col;

	row = 0;
	while (s[row] != 0)
		row++;

	col = 0;
	while (s[0][col] != '\0')
		col++;
	
	i = 0;
	while (s[i] != 0)
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			if (!(s[i][j] == '.' || s[i][j] == 'X' || (s[i][j] >= '0' && s[i][j] <= '9')))
				return (-3);
			j++;
		}
		if ((j != col) || (j > 1024))
			return (-2);
		i++;
	}

	count = 0;
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j <col)
		{
			if (s[i][j] == 'X')
			{
				if (count < 10)
					dfs(s, i, j, row, col, count);
				else
					return (-1);
				count ++;
			}
			j++;
		}
		i++;
	}
	return(0);
}

int main (int argc, char **argv)
{
	char	**s;
	char	buf[4096];
	int	fd;
	int	nbread;
	
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
        {
                write(1, "\n", 1);
                return (0);
        }
	nbread = read (fd, buf, 4096);
	if (nbread == 0 || nbread == -1)  
	{
                write(1, "nbread\n", 7);
                return (0);
        }
	buf[nbread] = '\0';
	s = ft_split(buf);
	ft_print(s);
	printf("$$$$\n");
	if (ft_countisland(s) == -1)
	{
                write(1, "count\n", 6);
                return (0);
        }
        if (ft_countisland(s) == -2)
	{    write(1, "col\n", 4);
                return (0);
        } 
        if (ft_countisland(s) == -3)
	{    write(1, "letter\n", 7);
                return (0);
        } 
       ft_print(s);
	return (0);
} 
