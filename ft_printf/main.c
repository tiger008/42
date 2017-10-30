#include <stdio.h>
#include "libftprintf.h"

int	main(void) {
		printf("%s\n", ft_itoabase(-2147483648, 10));
		printf(":%3.5f:\n", 5.6845);
		printf(":%10s:\n", "Hello, world !");
		printf(":%x:\n", 0x68);
		return(0);
}
