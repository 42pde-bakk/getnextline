/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 12:21:37 by pde-bakk      #+#    #+#                 */
/*   Updated: 2020/09/24 13:01:25 by peerdb        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

void	*gnl_calloc(size_t count, size_t size);
char	*gnl_strdup(const char *s1, int n, int startpos);
size_t	gnl_strlen(const char *s);
char	*gnl_strjoiner(char *s1, char *s2, int ret);
void	gnl_bzero(char *s, int n);
int		get_next_line(int fd, char **line);

#endif
