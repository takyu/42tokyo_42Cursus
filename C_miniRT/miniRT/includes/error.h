/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 19:49:09 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/03/27 19:49:15 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERROR "ERROR"
# define ERROR_ARG "usage : ./miniRT [.rt file] or ./miniRT [.rt file] --save"
# define ERROR_RTFILE "This file is not rt file ."
# define ERROR_OPEN "Cannnot open the file ."
# define ERROR_MALLOC "Failed to allocate memory"
# define ERROR_FORMAT_RT_FILE "Invalid format rt file"
# define ERROR_RESOLUTION "One resolution per rt file."

void	error_exit(char *s);
void	free_status_and_error_exit(t_status *status, char *s);

#endif
