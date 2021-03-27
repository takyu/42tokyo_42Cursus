/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:32:08 by tnagoshi          #+#    #+#             */
/*   Updated: 2020/12/17 10:40:05 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		free_allocated_ptr(char **ps)
{
	free(*ps);
	*ps = NULL;
}

static int		case_newline_read(char **memo, char **line,
											char *ptr_newline, char **buf)
{
	char	*tmp;
	int		res_val;

	res_val = GNL_READ;
	tmp = *memo;
	if (!(*line = ft_substr(*memo, 0, ptr_newline - *memo)))
	{
		free_allocated_ptr(line);
		res_val = GNL_ERROR;
	}
	if (!(*memo = ft_strdup(ptr_newline + 1)))
		res_val = GNL_ERROR;
	free_allocated_ptr(&tmp);
	free_allocated_ptr(buf);
	return (res_val);
}

static int		case_newline_not_read(char **memo, char **line,
										ssize_t reading_size, char **buf)
{
	int		res_val;
	char	*ptr_newline;

	res_val = GNL_EOF;
	if (reading_size < 0)
		res_val = GNL_ERROR;
	if (!(*memo))
	{
		if (res_val != GNL_ERROR)
			*line = ft_strdup("");
		free_allocated_ptr(buf);
		return (res_val);
	}
	if ((ptr_newline = ft_strchr(*memo, '\n')) != NULL)
		return (case_newline_read(memo, line, ptr_newline, buf));
	if (!(*line = ft_strdup(*memo)))
		res_val = GNL_ERROR;
	free_allocated_ptr(memo);
	free_allocated_ptr(buf);
	return (res_val);
}

static int		case_insert_memo(char **memo, char *buf)
{
	int		flag;
	char	*tmp;

	flag = 1;
	if (*memo)
	{
		tmp = *memo;
		*memo = ft_strjoin(*memo, buf);
		free_allocated_ptr(&tmp);
	}
	else
		*memo = ft_strdup(buf);
	if (!(*memo))
		flag = -1;
	return (flag);
}

int				get_next_line(int fd, char **line)
{
	static char		*memo[MAX_FD];
	char			*buf;
	ssize_t			reading_size;
	char			*ptr_newline;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (GNL_ERROR);
	buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buf || !line || read(fd, buf, 0) == -1)
	{
		free_allocated_ptr(&memo[fd]);
		free_allocated_ptr(&buf);
		return (GNL_ERROR);
	}
	while ((reading_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[reading_size] = '\0';
		if ((reading_size = case_insert_memo(&memo[fd], buf)) == -1)
			break ;
		if ((ptr_newline = ft_strchr(memo[fd], '\n')) != NULL)
			return (case_newline_read(&memo[fd], line, ptr_newline, &buf));
	}
	return (case_newline_not_read(&memo[fd], line, reading_size, &buf));
}
