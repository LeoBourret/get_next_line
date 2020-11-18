#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		ret;
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(av[1], O_RDONLY);
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		printf("%s\n", line);
		ret = get_next_line(fd, &line);
	}
	return (0);
}
