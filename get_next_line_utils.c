#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_free(char *surplus, char *buf)
{
	char	*ptr;
	size_t	len;

	if (!surplus)
	{
		surplus = malloc(1);
		surplus[0] = 0;
	}
	if (!surplus || !buf)
		return (NULL);
	len = ft_strlen(surplus) + ft_strlen(buf);
	ptr = (char *)malloc(sizeof(*surplus) * (len + 1));
	if (!ptr)
	{
		free (buf);
		return (NULL);
	}
	while (*surplus)
		*ptr++ = *surplus++;
	while (*buf)
		*ptr++ = *buf++;
	*ptr = 0;
	free(surplus);
	return (ptr - len);
}

int	ft_sheck_rtn(char *surplus)
{
	int	i;

	i = 0;
	if (!surplus)
		return (0);
	while (surplus[i])
	{
		if (surplus[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
