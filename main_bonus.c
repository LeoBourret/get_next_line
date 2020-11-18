#include <stdio.h>
#include "get_next_line_bonus.h"

int   main(int ac, char **av)
{
	char	*line;
	int		fd1;
	int		fd2;
	int		ret1;
	int		ret2;

	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	ret1 = get_next_line(fd1, &line);
	printf("%s\n", line);
	ret2 = get_next_line(fd2, &line);
	printf("%s\n", line);
	while (ret1 > 0 || ret2 > 0)
	{
		ret1 = get_next_line(fd1, &line);
		if (ret1 > 0)
			printf("%s\n", line);
		ret2 = get_next_line(fd2, &line);
		if (ret2 > 0)
			printf("%s\n", line);
	}
	return (0);
}
