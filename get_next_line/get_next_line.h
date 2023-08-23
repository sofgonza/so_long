/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:30:48 by sofgonza          #+#    #+#             */
/*   Updated: 2023/06/13 11:57:01 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*gnl_read(int fd, char *stash);
char	*gnl_new_stash(char *stash);
char	*gnl_line(char *stash);
int		gnl_strchr(const char *s, int c);
char	*gnl_strjoin(char *stash, char *s2);
int		gnl_strlen(const char *s);

#endif
