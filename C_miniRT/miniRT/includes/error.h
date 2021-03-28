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
# define ERROR_MALLOC "failed to allocate memory"

void	error_exit(char *s);

#endif
