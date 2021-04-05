#include "get_next_line.h"

void	ft_safe_free(void **p)
{
	free(*p);
	*p = NULL;
}

long	ft_strlen(char *s)
{
	return (*s ? ft_strlen(s + 1) + 1 : 0);
}

char	*ft_dup_until_br(char *s, long start, long end)
{
	long	i;
	char	*ret;

	i = 0;
	while (s[start + i] != '\n' && start + i < end)
		i++;
	ret = (char *)malloc(i + 1);
	i = 0;
	while (s[start + i] != '\n' && start + i < end)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int		get_next_line(char **line)
{
	static char		*memo;
	static long		start, end;
	static int		bef_end;
	int				reading_size;
	char			*ret;

	if (bef_end)
	{
		bef_end = 0;
		*line = (char *)malloc(1);
		**line = '\0';
		return (0);
	}
	if (!memo)
	{
		memo = (char *)malloc(1000000000);
		if (!memo)
			return (-1);
		reading_size = read(0, memo, 1024);
		if (reading_size == 0)
		{
			ft_safe_free((void **)&memo);
			*line = (char *)malloc(1);
			**line = '\0';
			return (0);
		}
		else if (reading_size < 0)
		{
			ft_safe_free((void **)&memo);
			*line = NULL;
			return (-1);
		}
		end = reading_size;
		while ((reading_size = read(0, memo + end, 1024)))
			end += reading_size;
		memo[end] = '\0';
	}
	ret = ft_dup_until_br(memo, start, end);
	*line = ret;
	start += ft_strlen(ret) + 1;
	if (start >= end)
	{
		ft_safe_free((void **)&memo);
		bef_end = (start == end);
		return (start == end);
	}
	return (1);
}