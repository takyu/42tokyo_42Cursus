/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rt_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:14:54 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/03/28 14:14:56 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	initialyze_status(t_status *s)
{
	s->r = NULL;
	s->al = NULL;
	s->c = NULL;
	s->l = NULL;
}

static void	analyze_info(char *info, t_status *status)
{
	char	**arr;

	if (*info == '\0')
		return ;
	arr = ft_split(info, ' ');
	if (!arr)
		error_exit(ERROR_MALLOC);
}

void		read_rt_file(char *name, t_status *status)
{
	char	*info;
	int		fd;
	int		flag_read;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		error_exit(ERROR_OPEN);
	initialyze_status(status);
	flag_read = 0;
	while ((flag_read = get_next_line(fd, &info)) >= 0)
	{
		// 1行の仕様を読み込んでいく作業をする。
		analyze_info(info, status);
		if (flag_read == 0)
			break ;
	}
	close(fd);
}