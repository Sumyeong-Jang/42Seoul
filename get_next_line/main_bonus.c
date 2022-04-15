#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

#define REV_COUNT 3

int	main(void)
{
	int				fd[2];
	int				ret[2];
	int				i=0;
	char			*line;
	unsigned char	count;

	ret[0] = 1;
	ret[1] = 1;
	count = REV_COUNT;
	fd[0] = open("./tests/file1", O_RDONLY);
	fd[1] = open("./tests/file2", O_RDONLY);
	while (1)
	{
		while (count-- > 0 && (line = get_next_line(fd[0])))
		{
			printf("[file1] %s\n", line);
			free(line);
			line = NULL;
		}
		if (line)
			free(line);
		count = REV_COUNT;
		while (count-- > 0 && ((line = get_next_line(fd[1])) > 0))
		{
			printf("[file2] %s\n", line);
			free(line);
			line = NULL;
		}
		i++;
		if (line)
			free(line);
		count = REV_COUNT;
		if (i == 100)
			break;
	}
	close(fd[0]);
	close(fd[1]);
	return (0);
}
