/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:22:42 by lebourre          #+#    #+#             */
/*   Updated: 2020/11/22 18:26:59 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s);
char	*ft_strncpy(char *s, int n);
char	*ft_strjoin(char *s1, char *s2);
int		get_next_line(int fd, char **lines);

#endif
