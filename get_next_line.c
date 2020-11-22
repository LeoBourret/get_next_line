#include "get_next_line.h"

void	fill_line(char **file_content, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*file_content)[len] && (*file_content)[len] != '\n')
		len++;
	if ((*file_content)[len] == '\n')
	{
		*line = ft_strncpy(*file_content, len);
		tmp = ft_strdup(&(*file_content)[len + 1]);
		free(*file_content);
		*file_content = tmp;
	}
	else
	{
		*line = ft_strdup(*file_content);
		free(*file_content);
		*file_content = NULL;
	}
}

int		manage_return(char **file_content, char **line, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && *file_content == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
	{
		fill_line(&(*file_content), line);
		if (*file_content == NULL)
			return (0);
		return (1);
	}
}

int		get_next_line(int fd, char **line)
{
	static char *file_content;
	char		*buffer;
	char		*tmp;
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = 0;
		if (file_content == NULL)
			file_content = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(file_content, buffer);
			free(file_content);
			file_content = tmp;
		}
		if (ft_strchr(file_content, '\n'))
			break ;
	}
	free(buffer);
	return (manage_return(&file_content, line, ret));
}
