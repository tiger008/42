#include <unistd.h>

int	main(int ac, char **av)
{
	char	out[2048] = {0};
	char	*in;
	int		i;
	int		par;
	int		tmp;

	if (ac == 2)
	{
		in = av[1];
		par = 0;
		i = 0;
		while (*in)
		{
			if (*in == '>')
				i++;
			else if (*in == '<')
				i--;
			else if (*in == '+')
				out[i]++;
			else if (*in == '-')
				out[i]--;
			else if (*in == '.')
				write(1, &out[i], 1);
			else if (*in == '[')
			{
				par++;
				if (out[i] == '\0')
				{
					tmp = par - 1;
					while (par != tmp)
					{
						in++;
						if (*in == '[')
							par++;
						if (*in == ']')
							par--;
					}
				}
			}
			else if (*in == ']')
			{
				par--;
				if (out[i] != '\0')
				{
					tmp = par + 1;
					while (par != tmp)
					{
						in--;
						if (*in == '[')
							par++;
						if (*in == ']')
							par--;
					}
				}
			}
			in++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
