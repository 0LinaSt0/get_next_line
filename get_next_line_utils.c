#include "get_next_line.h"

int	strlen_N_copyror(char **ror, char *buf, char **line, char **point_elem)
{
	int	i;

	i = 0;
	if (point_elem == NULL)
	{
		while ((*ror)[i] != '\0')
			i++;
		return (i);
	}
	*ror = ft_strjoin(*ror, buf, 1);
	*point_elem = ft_strchr(*ror, '\n');
	if (*point_elem != NULL)
		**point_elem = '\0';
	*line = ft_strjoin(*line, *ror, 1);
	if (!*ror || !*line)
		return (-1);
	if (*point_elem != NULL)
	{
		*ror = ft_strdup(++*point_elem, *ror, 0, buf);
		return (1);
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == 0)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	while (*src)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(char *s, int start, int len, char *line)
{
	char	*d;
	size_t	i;

	i = 0;
	free (line);
	if (!s)
		return (0);
	if (start >= strlen_N_copyror(&s, 0, 0, 0))
	{
		d = malloc(1);
		if (d == NULL)
			return (NULL);
		*d = '\0';
		return (d);
	}
	if (len > strlen_N_copyror(&s, 0, 0, 0) - start)
		len = strlen_N_copyror(&s, 0, 0, 0) - start;
	d = (char *)malloc(len + 1);
	if (d == NULL)
		return (NULL);
	while (s[start] != '\0' && i < (size_t)len)
		d[i++] = s[start++];
	d[i] = '\0';
	return (d);
}

char	*ft_strjoin(char *s1, char *s2, int del_s1)
{
	char	*d;
	size_t	j;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	d = (char *)malloc(strlen_N_copyror(&s1, 0, 0, 0)
			+ strlen_N_copyror(&s2, 0, 0, 0) + 1);
	if (d == NULL)
		free(s1);
	if (d == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		d[i++] = s2[j++];
	d[i] = '\0';
	if (del_s1)
		free (s1);
	return (d);
}
