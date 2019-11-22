/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utensils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 13:52:42 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/22 13:26:07 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strdup(const char *s1, int n, int startpos)
{
	char	*dup;
	size_t	i;
	size_t	len;

	i = 0;
	if (n == 0)
		return (ft_calloc(0, 0));
	len = n;
	dup = (char*)malloc(len);
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = s1[startpos + i];
		i++;
	}
	return (dup);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (s[0] == 0)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		n;
	char	*join;

	i = 0;
	n = 0;
	join = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (join == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2 && s2[n])
	{
		join[i] = s2[n];
		i++;
		n++;
	}
	join[i] = '\0';
	return (join);
}
