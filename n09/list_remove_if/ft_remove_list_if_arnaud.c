#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "ft_list.h"

int	cmpstr(void *src, void *dest)
{
	int	i;
	char	*s1;
	char	*s2;
	
	s1 = (char *) src;
	s2 = (char *) dest; 
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return(0);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*lst;
	t_list	*tmp;

	while (*begin_list != 0 && (*cmp)((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free (tmp); 
	}

	lst = *begin_list;	
	while (lst != 0 && lst->next != 0)
	{
		if ((*cmp)(lst->next->data, data_ref) == 0)
		{
			tmp = lst->next;
			lst->next = lst->next->next;
			free(tmp);
		}
		else
			lst = lst->next;
	}	
}

int main(void)
{
	char    s1[] = "Hello";
        char    s2[] = "World";
	char 	s3[] = "Alain";
	char	s4[] = "!!!!!";
	t_list	*l;
	t_list	*t;
	t_list	*b;
	int	i;

	l = malloc (sizeof(t_list) *1);
	t = l;
	b = l;
	
	i = 0;
	while (i < 16)
	{
	
		if (i == 0)
			l->data = &s1;
		else if (i % 4 == 0)
			l->data = &s1;
		else if (i % 4 == 1)
			l->data = &s1;
		else if (i % 4 == 2)
			l->data = &s2;
		else
			l->data = &s3; 
		l->next = malloc (sizeof(t_list) * 1);
		l = l->next;
		i++;
	}
	l->data = &s4;
	l->next = NULL;

	while (t != 0)
	{
		printf("%s ", (char *) t->data);
		t = t->next;
	}
	printf("\n");

	ft_list_remove_if(&b, &s1, cmpstr);

	while (b != 0)
        {
                printf("%s ", (char *) b->data);
                b = b->next;
        }
	printf("\n");
	return (0);
}
