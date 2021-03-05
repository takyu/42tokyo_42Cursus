/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:32:20 by tnagoshi          #+#    #+#             */
/*   Updated: 2020/12/17 09:32:53 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2000
# endif

# define MAX_FD 256

# define GNL_READ 1
# define GNL_EOF 0
# define GNL_ERROR -1

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

/*
** get_next_line.c
*/
int			get_next_line(int fd, char **line);

/*
** get_next_line_utils.c
*/
size_t		ft_strlen(const char *s);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_substr(const char *s, unsigned int start, size_t len);

#endif
