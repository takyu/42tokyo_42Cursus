/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:50:14 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/02/04 22:32:36 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define INTMIN "-2147483648"

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*
***************  function I added **********************
*/

/*
** ft_safe_free.c
*/
void				ft_safe_free(void **target);

/*
** ft_safe_free_2d.c
*/
void				ft_safe_free_2d(void ***p, int index);

/*
***************  function of assignment  ***************
*/

/*
** ft_memset.c
*/
void				*ft_memset(void *b, int c, size_t len);

/*
** ft_bzero.c
*/
void				ft_bzero(void *s, size_t n);

/*
** ft_memcpy.c
*/
void				*ft_memcpy(void *dst, const void *src, size_t n);

/*
** ft_memccpy.c
*/
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

/*
** ft_memmove.c
*/
void				*ft_memmove(void *dst, const void *src, size_t len);

/*
** ft_memchr.c
*/
void				*ft_memchr(const void *s, int c, size_t n);

/*
** ft_memcmp.c
*/
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** ft_strlen.c
*/
size_t				ft_strlen(const char *s);

/*
** ft_strlcpy.c
*/
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);

/*
** ft_strlcat.c
*/
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);

/*
** ft_strchr.c
*/
char				*ft_strchr(const char *s, int c);

/*
** ft_strrchr.c
*/
char				*ft_strrchr(const char *s, int c);

/*
** ft_strnstr.c
*/
char				*ft_strnstr(const char *haystack,
						const char *needle, size_t len);

/*
** ft_strncmp.c
*/
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** ft_atoi.c
*/
int					ft_atoi(const char *str);

/*
** ft_isalpha.c
*/
int					ft_isalpha(int c);

/*
** ft_isdigit.c
*/
int					ft_isdigit(int c);

/*
** ft_isalnum.c
*/
int					ft_isalnum(int c);

/*
** ft_isascii.c
*/
int					ft_isascii(int c);

/*
** ft_isprint
*/
int					ft_isprint(int c);

/*
** ft_toupper.c
*/
int					ft_toupper(int c);

/*
** ft_tolower.c
*/
int					ft_tolower(int c);

/*
** ft_calloc.c
*/
void				*ft_calloc(size_t count, size_t size);

/*
** ft_strdup.c
*/
char				*ft_strdup(const char *s1);

/*
** ft_substr.c
*/
char				*ft_substr(char const *s, unsigned int start, size_t len);

/*
** ft_strjoin.c
*/
char				*ft_strjoin(char const *s1, char const *s2);

/*
** ft_strtrim.c
*/
char				*ft_strtrim(char const *s1, char const *set);

/*
** ft_split.c
*/
char				**ft_split(char const *s, char c);

/*
** ft_itoa.c
*/
char				*ft_itoa(int n);

/*
** ft_strmapi.c
*/
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
** ft_putchar_fd.c
*/
void				ft_putchar_fd(char c, int fd);

/*
** ft_putstr_fd.c
*/
void				ft_putstr_fd(char *s, int fd);

/*
** ft_putendl_fd.c
*/
void				ft_putendl_fd(char *s, int fd);

/*
** ft_putnbr_fd.c
*/
void				ft_putnbr_fd(int n, int fd);

/*
** ft_lstnew.c
*/
t_list				*ft_lstnew(void *content);

/*
** ft_lstadd_front.c
*/
void				ft_lstadd_front(t_list **lst, t_list *new);

/*
** ft_lstsize.c
*/
int					ft_lstsize(t_list *lst);

/*
** ft_lstlast
*/
t_list				*ft_lstlast(t_list *lst);

/*
** ft_lstadd_back.c
*/
void				ft_lstadd_back(t_list **lst, t_list *new);

/*
** ft_lstdelone.c
*/
void				ft_lstdelone(t_list *lst, void (*del)(void *));

/*
** ft_lstclear.c
*/
void				ft_lstclear(t_list **lst, void (*del)(void *));

/*
** ft_lstiter.c
*/
void				ft_lstiter(t_list *lst, void (*f)(void *));

/*
** ft_lstmap.c
*/
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
													void (*del)(void *));

#endif
