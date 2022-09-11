#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		strlen_N_copyror(char **ror, char *buf, char **line, char **point_elem);
int		ft_read(char **ror, char *buf, char **line, int fd);
int		free_gnl(char **ror, char *buf, char **line, int free_line);
int		check_ror(char **remainder, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_substr(char *s, int start, int len, char *line);
char	*ft_strjoin(char *s1, char *s2, int del_s1);
char	*ft_strdup(char *s, char *ror, char *line, char *buf);

#endif
