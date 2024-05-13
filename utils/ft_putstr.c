#include "../so_long.h"

void	ft_putstr(char	*str)
{
	int	i;

	if (!str)
		return ;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	write (1, "\n", 1);
}