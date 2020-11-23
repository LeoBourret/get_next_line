/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:21:42 by lebourre          #+#    #+#             */
/*   Updated: 2020/11/23 16:13:43 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		fill_line(char **file_content, char **line)
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
		if (tmp == NULL)
			return (-1);
		free(*file_content);
		*file_content = tmp;
	}
	else
	{
		*line = ft_strdup(*file_content);
		if (*line == NULL)
			return (-1);
		free(*file_content);
		*file_content = NULL;
	}
	return (1);
}

int		manage_return(char **file_content, char **line, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && *file_content == NULL)
	{
		*line = ft_strdup("");
		if (*line == NULL)
			return (-1);
		return (0);
	}
	else
	{
		if (fill_line(&(*file_content), line) == -1)
			return (-1);
		if (*file_content == NULL)
			return (0);
		return (1);
	}
}

int		get_next_line(int fd, char **line)
{
	static char *file_content;
	char		*buff;
	char		*tmp;
	int			ret;

	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))) || fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (file_content == NULL)
			file_content = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(file_content, buff);
			if (tmp == NULL)
				return (-1);
			free(file_content);
			file_content = tmp;
		}
		if (ft_strchr(file_content, '\n'))
			break ;
	}
	free(buff);
	return (manage_return(&file_content, line, ret));
}
