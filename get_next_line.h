/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 12:21:37 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/24 16:02:11 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*ft_strdup(const char *s1, int n, int startpos);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoiner(char *s1, char *s2, int ret);
size_t	ft_strlen(const char *s);
int		get_next_line(int fd, char **line);

#endif
