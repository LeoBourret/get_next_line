/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:21:34 by lebourre          #+#    #+#             */
/*   Updated: 2020/11/22 23:27:19 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	dell_content(char **file_content)
{
	if (file_content != NULL)
	{
		free(*file_content);
		*file_content = NULL;
	}
}

int		fill_line(char **file_content, char **line)
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
		if (*file_content == NULL)
			return (-1);
		free(tmp);
	}
	else
	{
		*line = ft_strdup(*file_content);
		if (*line == NULL)
			return (-1);
		dell_content(file_content);
	}
	return (1);
}

int		manage_return(char **file_content, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && !file_content[fd])
	{
		*line = ft_strdup("");
		if (*line == NULL)
			return (-1);
		return (0);
	}
	else
	{
		if (fill_line(&file_content[fd], line) == -1)
			return (-1);
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

	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))) || !line)
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (file_content[fd] == NULL)
			file_content[fd] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(file_content[fd], buffer);
			if (tmp == NULL)
				return (-1);
			free(file_content[fd]);
			file_content[fd] = tmp;
		}
		if (ft_strchr(file_content[fd], '\n'))
			break ;
	}
	free(buffer);
	return (manage_return(file_content, line, ret, fd));
}
