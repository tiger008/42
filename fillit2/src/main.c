#include "fillit.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_trio	*a_trio;
	int		i;

	if (argc == 2 && (fd = open(argv[1], O_RDONLY)) != ER)
	{
		a_trio = (t_trio *)malloc(sizeof(t_trio) * MAX_TRIO);
		i = 0;
		if (ft_parser(fd, &a_trio) != -1)
		{
			while (i < MAX_TRIO)
			{

			}
		}
		else
			ft_putdendl("error");
		free(a_trio);
	}
	return (0);
}
