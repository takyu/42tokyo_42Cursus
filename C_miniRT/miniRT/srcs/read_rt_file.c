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
	s->obj = NULL;
}

static int	count_string_array(char **ps)
{
	int		i;

	i = 0;
	while (ps[i])
		i++;
	return (i);
}

static void	analyze_info(char *info, t_status *status)
{
	char	**arr;

	if (*info == '\0')
		return ;
	arr = ft_split(info, ' ');
	if (!arr)
		error_exit(ERROR_MALLOC);
	if (count_string_array(arr) == 0 || count_string_array(arr) == 1)
		error_exit(ERROR_FORMAT_RT_FILE);
	if (*arr == 'R')
		analyze_resolution(&(status->r), arr);
	else if (*arr == 'A')
		analyze_ambient_light(&(status->al), arr);
	else if (*arr == 'c')
		analyze_camera(&(status->c), arr);
	else if (*arr == 'l')
		analyze_light(&(status->l), arr);
	else
		analyze_object(&(status->obj), arr);
	ft_safe_free_2d((void ***)&arr, count_string_array(arr));
}

void		read_rt_file(char *name, t_status *status)
{
	char	*info;
	int		fd;
	int		res;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		error_exit(ERROR_OPEN);
	initialyze_status(status);
	res = 0;
	while ((res = get_next_line(fd, &info)) >= 0)
	{
		analyze_info(info, status);
		ft_safe_free((void **)&info);
		if (res == 0)
			break ;
	}
	close(fd);
}