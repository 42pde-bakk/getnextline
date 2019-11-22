/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 11:50:20 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/21 22:33:51 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_newlinecheck(char *str)
{
	int	i;

	i = 0;
	if (str == NULL || str[i] == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
				return (i);
		i++;
	}
	return (-1);
}

char	*ft_setstring(int ret, char *buf, char *line)
{
	size_t	i;
	size_t	n;
	char	*tmp;
	size_t	len;

	i = 0;
	n = 0;
	tmp = NULL;
	len = 0;
	if (buf[i] == 0)
		return (ft_strdup("", 0, 0));
	if (line && line[i] != 0)
		len = ft_strlen(line);
	if (line)
		tmp = ft_strdup(line, 0, 0);
	line = (char*)ft_calloc(ret + len + 1, sizeof(char));
	while (tmp && ft_strlen(tmp) > 0 && tmp[i])
	{
		line[i] = tmp[i];
		i++;
	}
	while (buf && buf[n])
	{
		line[i + n] = buf[n];
		n++;
	}
//	line = ft_strjoin(tmp, buf);
	return (line);
}

char	*ft_liner(char *str)
{
	size_t	i;
	size_t	len;
	char	*line;

	i = 0;
	len = ft_newlinecheck(str);
	printf("len=%zu\n", len);
	line = ft_strdup(str, len, 0);
	return (line);
}

char	*ft_bufferfixer(char *buf)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_newlinecheck(buf) + 1;
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
//	printf("ENDRESULT=%s\n", buf);
	return (buf);
}

int		get_next_line(int fd, char **line)
{
	static char buf[BUFFER_SIZE];
	char		*str;
	size_t		ret;

	ret = 1;
	str = NULL;
	if (buf[0] != 0)
	{
		ret = ft_strlen(buf);
		ft_bufferfixer(buf);
		printf("fixedbuffer=%s\n", buf);
	}
	while (ret > 0)
	{	
		printf("Ret=%zu\nBuf=%s\n%sStr=s\n", ret, buf, str);
		str = ft_setstring(ret, buf, str);
//		printf("AFTERRRRR Ret=%zu\nBuf=%s\n%sStr=s\n", ret, buf, str);
		if (ft_newlinecheck(str) != -1)
		{
			*line = ft_liner(str);
			free(str);
//			printf("nextbuffer=%s\n", buf);
			return (1);
		}
		ret = read(fd, buf, BUFFER_SIZE);
	}
	free(str);
	return (0);
}

int		main(void)
{
	char	*line;
	int		fd;
	int		i;

	i = 1;
	fd = open("42", O_RDONLY);
	while (i < 5)
	{
		get_next_line(fd, &line);
		printf("%s\n", line);
		i++;
	}
	return (0);
}
