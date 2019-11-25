/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 13:09:11 by pde-bakk       #+#    #+#                */
/*   Updated: 2019/11/25 14:19:23 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;
	int		fd2;
	int		i;
	int		i2;

	fd = open("get_next_line.c", O_RDONLY);
	fd2 = open("get_next_line.c", O_RDONLY);

	i = 1;
	i2 = 2;
	while (i > 0 && i2 > 0)
	{
		i = get_next_line(fd, &line);
		printf("%d-%s\n", i, line);
		free(line);
//		i2 = get_next_line(fd2, &line);
//		printf("%d-%s\n", i2, line);
//		free(line);
	}
//	i = get_next_line(fd, &line);
//	printf("%d-%s\n", i, line);
//	free(line);
	while (1)
	{}
	return (0);
}
