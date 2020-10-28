#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return ((char*)&s[i]);
	if (s[i] == c)
		return ((char*)&s[i]);
	return (0);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*new;

	len = ft_strlen(str);
	if (!(new = malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = -1;
	while (++i < len)
		new[i] = str[i];
	new[i] = '\0';
	return (new);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*new;
	int		i;
	int		size;

	if (start > ft_strlen(s) || !s)
		return (NULL);
	size = ft_strlen(&s[start]);
	if (size < len)
		len = size;
	if (!(new = malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (s[start] && (i < len))
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*new;
	size_t		len;
	size_t		i;
	size_t		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	j = -1;
	while (s2[++j])
		new[i++] = s2[j];
	new[i] = '\0';
	return (new);
}
