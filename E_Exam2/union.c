#include <unistd.h>

int		is_no_match(char *s, char c, int end)
{
	int		i;

	i = 0;
	while (i < end)
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1)
}

void	ft_union(char *str1, char *str2)
{
	int		i;
	int		j;

	i = 0;
	while (str1[i])
	{
		if (is_no_match(str1, str1[i], i))
			write (1, &str1[i], 1);
		i++;
	}
	j = i;
	i = 0;
	while (str2[i])
	{
		if (is_no_match(str2, str2[i], i))
		{
			if (is_no_match(str1, str2[i], j))
				write (1, &str2[i], 1);
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}
	ft_union(argv[1], argv[2]);
	write (1,"\n", 1);
	return (0);
}