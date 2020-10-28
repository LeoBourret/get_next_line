#include "get_next_line.h"

void	ft_memdel(void **file_content)
{
	if (file_content != NULL)
	{
		free(*file_content);
		*file_content = NULL;
	}
}

void	ft_strdel(char **file_content)
{
	if (file_content != NULL && *file_content != NULL)
		ft_memdel((void**)file_content);
}

void	fill_line(char **file_content, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*file_content)[len] && (*file_content)[len] != '\n')
		len++;
	if ((*file_content)[len] == '\n')
	{
		*line = ft_substr(*file_content, 0, len);
		tmp = ft_strdup(&(*file_content)[len + 1]);
		free(*file_content);
		*file_content = tmp;
		if ((*file_content)[0] == '\0')
			ft_strdel(file_content);
	}
	else
	{
		*line = ft_strdup(*file_content);
		ft_strdel(file_content);
	}
}

int		manage_return(char **file_content, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && file_content[fd] == NULL)
		return (0);
	else
	{
		fill_line(&file_content[fd], line);
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
		buffer[ret] = 0;
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
	return (manage_return(file_content, line, ret, fd));
}
