/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 12:37:45 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/22 14:25:07 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_newlinecheck(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
//			printf("newline found\n");
			return (i);
		}
		i++;
		if (str[i] == 0)
			return (i);
	}
//	printf("newline not found\n");
	return (-1);
}

char	*ft_stringsetter(char *str, int ret, char *buf)
{
	size_t	i;
	size_t	len;
	size_t	n;
	char	*result;

	len = 0;
	i = 0;
	n = 0;
	if (buf[0] == 0)
		return (ft_calloc(0, 0));
	if (str && str[i] != 0)
		len = ft_strlen(str);
	result = (char*)ft_calloc(ret + len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	while (str && str[i])
	{
		result[i] = str[i];
		i++;
	}
//	printf("result=%s&&&&\n", str);
	while (buf && buf[n])
	{
		result[i + n] = buf[n];
		n++;
	}
//	printf("testprintf\n");
//	if (str)
//		free(str);
	return (result);
}

char	*ft_bufferfixer(char *buf)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_newlinecheck(buf) + 1;
//	printf("len+1%cLEN+1", buf[len]);
	while (buf[i] && buf[len + i])
	{
		buf[i] = buf[len + i];
		i++;
	}
	while (buf[i])
	{
		buf[i] = 0;
		i++;
	}
//	printf("gefixte buffer=%s$$\n", buf);
	return (buf);
}

int		get_next_line(int fd, char **line)
{
	static char buf[BUFFER_SIZE];
	char		*str;
	size_t		ret;

	ret = 1;
// str = NULL;
	str = ft_calloc(0, 0);
	if (buf[0] != 0)
	{
//		printf("%s\n", buf);
		ret = ft_strlen(buf);
	}
	if (ret == 0 && buf[0] == 0)
		return (0);
	while (ret > 0)
	{
//		printf("buf==%s$$$$$$$$$\n", buf);
		str = ft_stringsetter(str, ret, buf);
		if (ft_newlinecheck(str) != -1)
		{
//			printf("\t\t\t\t\t\t\t\t\t\t%i\n", ft_newlinecheck(str));
			*line = ft_strdup(str, ft_newlinecheck(str), 0);
//			printf("WAGWAAN%s\n", *line);
			ft_bufferfixer(buf);
			return (1);
		}
		ret = read(fd, buf, BUFFER_SIZE);
	}
	if (buf[0] == 0 && ret == 0)
		return (0);
	return (0);
}

int		main(void)
{
	char	*line;
	int		fd;
	int		i;

	i = 1;
	fd = open("42", O_RDONLY);
	while (i < 15)
	{
		get_next_line(fd, &line);
		printf("%s\n", line);
//		printf("!@#$^&*()_+\n");
		i++;
	}
	return (0);
}
