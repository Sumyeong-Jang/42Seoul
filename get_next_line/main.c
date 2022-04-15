#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd;
	int	i=1;
	char *line;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%d -- %s", i, line);
		i++;
	   	free(line);
		if (line == NULL)
			break;
	}
	return (0);
}
