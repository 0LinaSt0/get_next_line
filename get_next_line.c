#include "get_next_line.h"

char	*ft_strdup(char *s, char *ror, char *line, char *buf)
{
	char	*d;
	size_t	z;

	z = 0;
	free (line);
	free (buf);
	d = (char *)malloc(strlen_N_copyror(&s, 0, 0, 0) + 1);
	if (d == NULL)
		return (NULL);
	while (s[z] != '\0')
	{
		d[z] = s[z];
		z++;
	}
	d[z] = '\0';
	free (ror);
	return (d);
}

int	check_ror(char **ror, char **line)
{
	char	*p_ror;
	char	*remainder;

	remainder = *ror;
	if (*ror)
	{
		p_ror = ft_strchr(remainder, '\n');
		if (p_ror)
		{
			*line = ft_substr(*ror, 0, (p_ror - *ror), *line);
			*p_ror = '\0';
			ft_strcpy(remainder, ++p_ror);
			return (1);
		}
		else if (**ror == '\0')
			*line = ft_strdup(*ror, 0, *line, 0);
		else if (**line == '\0')
			return (2);
		else
		{
			while (*remainder)
				*remainder++ = '\0';
		}
	}
	return (3);
}

int	free_gnl(char **ror, char *buf, char **line, int free_line)
{
	if (ror)
	{
		free (*ror);
		*ror = NULL;
	}
	free(buf);
	if (free_line == 1)
	{
		free(*line);
		*line = 0;
	}
	return (-1);
}

int	ft_read(char **ror, char *buf, char **line, int fd)
{
	int			byte_read;
	char		*point_elem;

	byte_read = 1;
	point_elem = NULL;
	while (!point_elem && byte_read != 0)
	{
		if (strlen_N_copyror(ror, 0, 0, 0) == -1)
			return (-1);
		if (*ror && strlen_N_copyror(ror, 0, 0, 0) && byte_read == 0
			&& free_gnl(ror, buf, line, 2) == -1)
			return (0);
		if (check_ror(ror, line) == 1 && free_gnl(0, buf, 0, 2) == -1 && *line)
			return (1);
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read < 0 && free_gnl(ror, buf, line, 1) == -1)
			return (-1);
		buf[byte_read] = '\0';
		if (strlen_N_copyror(ror, buf, line, &point_elem) == 1)
			return (1);
	}
	if (**line && byte_read > 0)
		return (1);
	free_gnl(ror, buf, line, 2);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*record_of_remainder = NULL;

	if (BUFFER_SIZE < 1 || fd < 0)
	{
		*line = 0;
		return (-1);
	}
	buf = (char *)malloc(BUFFER_SIZE + 1);
	*line = (char *)malloc(1);
	if (buf == NULL || *line == NULL)
		return (free_gnl(&record_of_remainder, buf, line, 1));
	**line = '\0';
	if (record_of_remainder == NULL)
	{
		record_of_remainder = (char *)malloc(1);
		if (record_of_remainder == NULL)
			return (free_gnl(&record_of_remainder, buf, line, 1));
		*record_of_remainder = '\0';
	}
	return (ft_read(&record_of_remainder, buf, line, fd));
}
