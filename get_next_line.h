#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*ft_strchr(char *, int);
char	*ft_strdup(char *);
char	*ft_substr(char *, int, int);
char	*ft_strjoin(char *, char *);
int		get_next_line(int, char**);
#endif
