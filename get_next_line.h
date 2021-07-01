#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		ft_sheck_rtn(char *surplus);
size_t	ft_strlen(const char *str);
char	*ft_strjoin_free(char *surplus, char *buf);
int		get_next_line(int fd, char **line);

#endif
