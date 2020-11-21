#include "get_next_line.h"

void	dell_content(char **file_content)
{
	if (file_content != NULL)
	{
		free(*file_content);
		*file_content = NULL;
	}
}

void	fill_line(char **file_content, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	tmp = *file_content;
	while ((*file_content)[len] && (*file_content)[len] != '\n')
		len++;
	if ((*file_content)[len] == '\n')
	{
		*line = ft_strncpy(*file_content, len);
		*file_content = ft_strdup(ft_strchr(tmp, '\n') + 1);
		free(tmp);
	}
	else
	{
		*line = ft_strdup(*file_content);
		dell_content(file_content);
	}
}

int		manage_return(char **file_content, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && !file_content[fd])
	{
		*line = ft_strdup("");
		return (0);
	}
	else
	{
		fill_line(&file_content[fd], line);
		if (file_content[fd] == NULL)
			return (0);
		return (1);
	}
}

int		get_next_line(int fd, char **line)
{
	static char *file_content[4096];
	char		*buffer;
	char		*tmp;
	int			ret;

	if (!line)
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (file_content[fd] == NULL)
			file_content[fd] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(file_content[fd], buffer);
			free(file_content[fd]);
			file_content[fd] = tmp;
		}
		if (ft_strchr(file_content[fd], '\n'))
			break ;
	}
	free(buffer);
	return (manage_return(file_content, line, ret, fd));
}
