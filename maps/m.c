#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	int		rd;
	char	c;

	fd = open("map1.ber", O_RDONLY);
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		printf ("%c", c);
	}
	close (fd);
	return (0);
}
